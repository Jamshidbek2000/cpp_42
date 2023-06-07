#include "../include/Bureaucrat.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150)
{
	std::cout << GREEN_TXT 
			<< "Bureaucrat Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & inputName, int inputGrade) : name(inputName)
{
	if (inputGrade > Bureaucrat::minGrade)
		throw(Bureaucrat::GradeTooLowException());
	if (inputGrade < Bureaucrat::maxGrade)
		throw(Bureaucrat::GradeTooHighException());
	grade = inputGrade;

	std::cout << GREEN_TXT
			<< "Bureaucrat " << name << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : name(rhs.name)
{
	std::cout << GREEN_TXT
			<< "Bureaucrat " << name << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
	*this = rhs;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BLUE_TXT
			<< "Bureaucrat " << name << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string const &	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		grade = rhs.grade;
	std::cout << ORANGE_TXT
			<< "Bureaucrat " << name << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Bureaucrat::incrementGrade()
{
	std::cout << "Bureaucrat " << name << ", incrementGrade is called" << std::endl;
	if (grade == Bureaucrat::maxGrade)
		throw(Bureaucrat::GradeTooHighException());
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Bureaucrat " << name << ", decrementGrade is called" << std::endl;
	if (grade == Bureaucrat::minGrade)
		throw(Bureaucrat::GradeTooLowException());
	grade++;
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< "Bureaucrat " << name
				<< " could not sign Form " << form.getName()
				<< ". Because " << e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << name
				<< " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED_TXT
				<< "Bureaucrat " << name
				<< " could not execute Form " << form.getName()
				<< ". Because " << e.what()
				<< DEFAULT_TXT << std::endl;
	}
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!\n";
}
