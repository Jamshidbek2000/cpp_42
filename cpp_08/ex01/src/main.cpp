#include "../include/Span.hpp"

static unsigned int const range = 526176599;

int getRandNbr(int seed) {
	for (int i = 0; i < seed % 100; ++i) rand();
	int randNbr = rand() % range;
	int sign = rand() % 2;
	return sign ? randNbr : -randNbr;
}

void manyNbrsWithDuplicates() {
	std::cout << GREEN_TXT
			  << "Test a span with many nbrs, span may include duplicates:" << DEFAULT_TXT
			  << std::endl;
	unsigned int size = 100000;
	Span sp(size);
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++) sp.addNumber(getRandNbr(rand()));
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}

void manyNbrsWithoutDuplicates() {
	std::cout << GREEN_TXT << "Test a span with many nbrs, without duplicates:" << DEFAULT_TXT
			  << std::endl;
	unsigned int size = 21000;
	std::vector<int> v;
	for (unsigned int i = 0; i < size; ++i) v.push_back(getRandNbr(rand()));
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	Span sp(v.size());
	for (unsigned int i = 0; i < v.size(); ++i) sp.addNumber(v[i]);
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}

void subjectPDF() {
	std::cout << GREEN_TXT << "Test from subject PDF:" << DEFAULT_TXT << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void addTooManyNbrs() {
	std::cout << GREEN_TXT << "Test adding too many numbers:" << DEFAULT_TXT << std::endl;
	Span sp(10);
	try {
		for (int i = 0; i < 11; ++i) sp.addNumber(i * 3);
	} catch (std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}
}

void unsortedNbrs() {
	std::cout << GREEN_TXT << "Test with unsorted numbers:" << DEFAULT_TXT << std::endl;
	Span sp(8);
	sp.addNumber(-9);
	sp.addNumber(39);
	sp.addNumber(15);
	sp.addNumber(400);
	sp.addNumber(36);
	sp.addNumber(89);
	sp.addNumber(2);
	sp.addNumber(7);
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}

void sortedNbrs() {
	std::cout << GREEN_TXT << "Test with sorted numbers:" << DEFAULT_TXT << std::endl;
	Span sp(8);
	sp.addNumber(-9);
	sp.addNumber(2);
	sp.addNumber(7);
	sp.addNumber(15);
	sp.addNumber(36);
	sp.addNumber(39);
	sp.addNumber(89);
	sp.addNumber(400);
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}

void tooFewElements() {
	std::cout << GREEN_TXT
			  << "Test finding spans with insufficent elements in Span object:" << DEFAULT_TXT
			  << std::endl;
	Span sp(8);
	try {
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}
	sp.addNumber(9);
	try {
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}
}

void addRangeExample() {
	std::cout << GREEN_TXT << "Add Range test" << DEFAULT_TXT << std::endl;
	std::vector<int> nums1;
	std::vector<int> nums2;

	for (int i = 0; i < 5; i++) nums1.push_back(i);
	for (int i = 0; i < 10; i++) nums2.push_back(i);

	Span span(6);
	span.print();

	try {
		span.addRange(nums1.begin(), nums1.end());
		span.print();

		span.addRange(nums2.begin(), nums2.end());
		span.print();
	} catch (std::exception& e) {
		std::cout << RED_TXT << e.what() << DEFAULT_TXT << std::endl;
	}
}

int main() {
	subjectPDF();
	addTooManyNbrs();
	unsortedNbrs();
	sortedNbrs();
	tooFewElements();
	manyNbrsWithDuplicates();
	manyNbrsWithoutDuplicates();
	addRangeExample();
	return 0;
}
