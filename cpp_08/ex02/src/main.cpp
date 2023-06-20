#include "../include/MutantStack.hpp"

void test42() {
	std::cout << YELLOW_TXT << "\t\t\tTest 42" << DEFAULT_TXT << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "On top is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size is: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << '\n';
}

void myTest1() {
	std::cout << YELLOW_TXT << "\t\t\tMy Test 1" << DEFAULT_TXT << std::endl;
	MutantStack<int> mstack;
	mstack.push(0);
	mstack.push(1);
	mstack.push(4);
	mstack.push(9);
	mstack.push(16);
	mstack.push(25);

	MutantStack<int>::iterator start = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();
	while (start != end) {
		(*start)++;
		std::cout << *start << std::endl;
		++start;
	}
	std::stack<int> s(mstack);
	std::cout << '\n';
}

void myTest2() {
	std::cout << YELLOW_TXT << "\t\t\tMy Test 2" << DEFAULT_TXT << std::endl;
	MutantStack<int> mstack;
	mstack.push(0);
	mstack.push(1);
	mstack.push(4);
	mstack.push(9);
	mstack.push(16);
	mstack.push(25);

	MutantStack<int>::const_iterator start = mstack.begin();
	MutantStack<int>::const_iterator end = mstack.end();
	while (start != end) {
		// (*start)++;
		std::cout << *start << std::endl;
		++start;
	}
	std::stack<int> s(mstack);
	std::cout << '\n';
}

int main() {
	test42();
	myTest1();
	myTest2();

	return 0;
}