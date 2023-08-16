#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

class PmergeMe {
   private:
	std::vector<int> vec;
	std::deque<int> deq;

	PmergeMe();

	void sortVector();
	void sortDeque();

	std::vector<std::pair<int, int> > mergePairs(const std::vector<std::pair<int, int> >& left,
												 const std::vector<std::pair<int, int> >& right);
	std::deque<std::pair<int, int> > mergePairs(const std::deque<std::pair<int, int> >& left,
												const std::deque<std::pair<int, int> >& right);

	std::vector<std::pair<int, int> > mergeSortPairs(
		const std::vector<std::pair<int, int> >& pairs);
	std::deque<std::pair<int, int> > mergeSortPairs(const std::deque<std::pair<int, int> >& pairs);

	void sortEachVectorPair();
	void sortEachDequePair();

	void binaryInsertionSort(std::vector<int>& v1, std::vector<int>& v2);
	void binaryInsertionSort(std::deque<int>& d1, std::deque<int>& d2);

	void insertNumber(std::vector<int>& v, int num, int high);
	void insertNumber(std::deque<int>& d, int num, int high);

	void printVector(const std::vector<int>& vec);
	void printDeque(const std::deque<int>& deq);

	void printJacobsthalNumbers();
	int getNextJacobsthalNumber(int prev);

	bool isSorted();

   public:
	PmergeMe(std::vector<int> vecInput, std::deque<int> deqInput);
	PmergeMe(PmergeMe const& rhs);
	PmergeMe& operator=(PmergeMe const& rhs);
	~PmergeMe();

	void sort();
};

#endif
