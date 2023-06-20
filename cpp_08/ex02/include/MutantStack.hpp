#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>

#define RED_TXT "\033[1;31m"
#define GREEN_TXT "\033[0;32m"
#define YELLOW_TXT "\033[0;33m"
#define BLUE_TXT "\033[0;34m"
#define ORANGE_TXT "\033[38;5;202m\033[22m"
#define DEFAULT_TXT "\033[1;39m"

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
   public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	MutantStack() {}
	MutantStack(Container const& a) : std::stack<T, Container>::stack(a) {}
	MutantStack& operator=(Container const& a) { std::stack<T, Container>::operator=(a); }
	~MutantStack() {}
};

#endif
