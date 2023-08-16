#include "../include/PmergeMe.hpp"

#include <vector>

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vecInput, std::deque<int> deqInput) {
	vec = vecInput;
	deq = deqInput;
}

PmergeMe::PmergeMe(PmergeMe const& rhs) { *this = rhs; }

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
	if (this != &rhs) {
		vec.clear();
		deq.clear();

		vec = rhs.vec;
		deq = rhs.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// ************************************************************************** //
//                               PUBLIC MEMBER FUNCTIONS                      //
// ************************************************************************** //

void PmergeMe::sort() {
	struct timeval startTime, endTime;

	if (isSorted()) {
		std::cout << ORANGE_TXT << "Sequence is already sorted. Sorting is unnecessary."
				  << std::endl
				  << DEFAULT_TXT;
		return;
	}

	std::cout << std::endl;
	std::cout << "Before: ";
	printVector(vec);
	std::cout << std::endl;

	gettimeofday(&startTime, NULL);
	sortVector();
	gettimeofday(&endTime, NULL);

	std::cout << "After: ";
	printVector(vec);
	std::cout << std::endl;

	std::cout << BLUE_TXT << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(6)
			  << (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) * 1e-6
			  << " us" << std::endl
			  << std::endl
			  << DEFAULT_TXT;

	gettimeofday(&startTime, NULL);
	sortDeque();
	gettimeofday(&endTime, NULL);

	std::cout << GREEN_TXT << "Time to process a range of " << vec.size()
			  << " elements with std::deque : " << std::fixed << std::setprecision(6)
			  << (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec) * 1e-6
			  << " us" << std::endl
			  << std::endl
			  << DEFAULT_TXT;
}

// ************************************************************************** //
//                               PRIVATE MEMBER FUNCTIONS                     //
// ************************************************************************** //

// ************************************************************************** //
//                               VECTOR                                       //
// ************************************************************************** //

void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> bigs;
	std::vector<int> smalls;

	sortEachVectorPair();

	// make pairs
	for (unsigned long i = 1; i < vec.size(); i += 2) {
		pairs.push_back(std::make_pair(vec.at(i - 1), vec.at(i)));
	}

	// sort pairs
	std::vector<std::pair<int, int> > sortedPairs = mergeSortPairs(pairs);

	// separate big elements from small
	for (std::vector<std::pair<int, int> >::iterator it = sortedPairs.begin();
		 it != sortedPairs.end(); it++) {
		bigs.push_back(it->first);
		smalls.push_back(it->second);
	}

	binaryInsertionSort(bigs, smalls);

	// if number of numbers is odd -> add the last element
	if (vec.size() % 2 == 1) insertNumber(bigs, vec.at(vec.size() - 1), bigs.size() - 1);
	vec = bigs;
}

void PmergeMe::sortEachVectorPair() {
	for (std::vector<int>::iterator it = vec.begin() + 1; it < vec.end(); it += 2) {
		if (*(it - 1) < *it) std::iter_swap(it - 1, it);
	}
}

std::vector<std::pair<int, int> > PmergeMe::mergeSortPairs(
	const std::vector<std::pair<int, int> >& pairs) {
	if (pairs.size() <= 1) {
		return pairs;
	}

	size_t mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > leftPairs(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > rightPairs(pairs.begin() + mid, pairs.end());

	leftPairs = mergeSortPairs(leftPairs);
	rightPairs = mergeSortPairs(rightPairs);

	return mergePairs(leftPairs, rightPairs);
}

std::vector<std::pair<int, int> > PmergeMe::mergePairs(
	const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right) {
	std::vector<std::pair<int, int> > mergedPairs;
	size_t leftIdx = 0;
	size_t rightIdx = 0;

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx].first <= right[rightIdx].first) {
			mergedPairs.push_back(left[leftIdx]);
			leftIdx++;
		} else {
			mergedPairs.push_back(right[rightIdx]);
			rightIdx++;
		}
	}

	// Copy the remaining pairs
	while (leftIdx < left.size()) {
		mergedPairs.push_back(left[leftIdx]);
		leftIdx++;
	}

	while (rightIdx < right.size()) {
		mergedPairs.push_back(right[rightIdx]);
		rightIdx++;
	}

	return mergedPairs;
}

void PmergeMe::binaryInsertionSort(std::vector<int>& v1, std::vector<int>& v2) {
	unsigned long lower = 1;
	unsigned long upper = (v2.size() > 2) ? 2 : v2.size() - 1;
	unsigned long i = upper;

	v1.insert(v1.begin(), v2.at(0));

	for (; lower < v2.size();) {
		insertNumber(v1, v2.at(i), upper + lower - 1);
		if (i == lower) {
			lower = upper + 1;
			upper = (getNextJacobsthalNumber(upper + 1) > static_cast<int>(v2.size()))
						? v2.size() - 1
						: getNextJacobsthalNumber(upper + 1) - 1;
			i = upper;
		} else
			i--;
	}
}

void PmergeMe::insertNumber(std::vector<int>& v, int num, int upper) {
	int low = 0;
	int high = (v.size() < static_cast<unsigned long>(upper)) ? v.size() : upper;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (v[mid] == num) {
			// If the number already exists, insert after it
			v.insert(v.begin() + mid + 1, num);
			return;
		} else if (v[mid] < num) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	// If the number doesn't exist, insert at the appropriate position
	v.insert(v.begin() + low, num);
}

void PmergeMe::printVector(const std::vector<int>& v) {
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// ************************************************************************** //
//                               DEQUE                                        //
// ************************************************************************** //

void PmergeMe::sortDeque() {
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> bigs;
	std::deque<int> smalls;

	sortEachDequePair();

	// Make pairs
	for (unsigned long i = 1; i < deq.size(); i += 2) {
		pairs.push_back(std::make_pair(deq.at(i - 1), deq.at(i)));
	}

	// Sort pairs
	std::deque<std::pair<int, int> > sortedPairs = mergeSortPairs(pairs);

	// Separate big elements from small
	for (std::deque<std::pair<int, int> >::iterator it = sortedPairs.begin();
		 it != sortedPairs.end(); it++) {
		bigs.push_back(it->first);
		smalls.push_back(it->second);
	}

	binaryInsertionSort(bigs, smalls);

	// If the number of numbers is odd, add the last element
	if (deq.size() % 2 == 1) {
		insertNumber(bigs, deq.at(deq.size() - 1), bigs.size() - 1);
	}
	deq = bigs;
}

void PmergeMe::sortEachDequePair() {
	for (std::deque<int>::iterator it = deq.begin() + 1; it < deq.end(); it += 2) {
		if (*(it - 1) < *it) std::iter_swap(it - 1, it);
	}
}

std::deque<std::pair<int, int> > PmergeMe::mergeSortPairs(
	const std::deque<std::pair<int, int> >& pairs) {
	if (pairs.size() <= 1) {
		return pairs;
	}

	size_t mid = pairs.size() / 2;
	std::deque<std::pair<int, int> > leftPairs(pairs.begin(), pairs.begin() + mid);
	std::deque<std::pair<int, int> > rightPairs(pairs.begin() + mid, pairs.end());

	leftPairs = mergeSortPairs(leftPairs);
	rightPairs = mergeSortPairs(rightPairs);

	return mergePairs(leftPairs, rightPairs);
}

std::deque<std::pair<int, int> > PmergeMe::mergePairs(
	const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right) {
	std::deque<std::pair<int, int> > mergedPairs;
	size_t leftIdx = 0;
	size_t rightIdx = 0;

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx].first <= right[rightIdx].first) {
			mergedPairs.push_back(left[leftIdx]);
			leftIdx++;
		} else {
			mergedPairs.push_back(right[rightIdx]);
			rightIdx++;
		}
	}

	// Copy the remaining pairs
	while (leftIdx < left.size()) {
		mergedPairs.push_back(left[leftIdx]);
		leftIdx++;
	}

	while (rightIdx < right.size()) {
		mergedPairs.push_back(right[rightIdx]);
		rightIdx++;
	}

	return mergedPairs;
}

void PmergeMe::binaryInsertionSort(std::deque<int>& d1, std::deque<int>& d2) {
	unsigned long lower = 1;
	unsigned long upper = (d2.size() > 2) ? 2 : d2.size() - 1;
	unsigned long i = upper;

	d1.insert(d1.begin(), d2.at(0));

	for (; lower < d2.size();) {
		insertNumber(d1, d2.at(i), upper + lower - 1);
		if (i == lower) {
			lower = upper + 1;
			upper = (getNextJacobsthalNumber(upper + 1) > static_cast<int>(d2.size()))
						? d2.size() - 1
						: getNextJacobsthalNumber(upper + 1) - 1;
			i = upper;
		} else
			i--;
	}
}

void PmergeMe::insertNumber(std::deque<int>& d, int num, int upper) {
	int low = 0;
	int high = (d.size() < static_cast<unsigned long>(upper)) ? d.size() : upper;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (d[mid] == num) {
			// If the number already exists, insert after it
			d.insert(d.begin() + mid + 1, num);
			return;
		} else if (d[mid] < num) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	// If the number doesn't exist, insert at the appropriate position
	d.insert(d.begin() + low, num);
}

void PmergeMe::printDeque(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// ************************************************************************** //
//                               SHARED                                       //
// ************************************************************************** //

void PmergeMe::printJacobsthalNumbers() {
	int n1 = 0;
	int n2 = 1;
	int next;

	std::cout << n1 << " " << n2 << " ";
	while (n2 < 10000) {
		next = 2 * n1 + n2;
		n1 = n2;
		n2 = next;
		std::cout << next << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::getNextJacobsthalNumber(int prev) {
	int n1 = 0;
	int n2 = 1;
	int next = prev;

	while (true) {
		next = 2 * n1 + n2;
		n1 = n2;
		n2 = next;
		if (next > prev) return next;
	}
	return next;
}

bool PmergeMe::isSorted() {
	int prev = vec[0];
	for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++) {
		if (prev > *it) return false;
		prev = *it;
	}
	return true;
}
