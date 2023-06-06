#include "../include/Form.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

Form::Form() : name("Default Form"), isSigned(false), requiredGrade(150)
{
	std::cout << GREEN_TXT
			<< "Form Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Form::Form(std::string const & inputName, int inputRequiredGrade) : name(inputName), isSigned(false), requiredGrade(inputRequiredGrade)
{
	if (inputRequiredGrade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (inputRequiredGrade > 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << GREEN_TXT
			<< "Form " << name << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Form::Form(Form const & rhs) : name(rhs.name), isSigned(false), requiredGrade(rhs.requiredGrade)
{
	std::cout << GREEN_TXT
			<< "Form " << name << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

Form::~Form()
{
	std::cout << BLUE_TXT
			<< "Form " << name << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string Form::getName()
{
	return name;
}

bool	Form::getIsSigned()
{
	return isSigned;
}

int	Form::getRequiredGrade()
{
	return requiredGrade;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

Form & Form::operator=(Form const & rhs)
{
	isSigned = rhs.isSigned;
	std::cout << ORANGE_TXT
			<< "Form " << name << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream & os, Form & form)
{
	os << "Form " << form.getName()
		<< "that requires grade "
		<< form.getRequiredGrade() << " is ";
	if (form.getIsSigned() == false)
		os << "not ";
	os << "signed." << std::endl;
	return os;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	Form::beSigned(Bureaucrat & bureaucrat)
{
	if (isSigned == true)
	{
		std::cout << "Form " << name << " is already signed!" << std::endl;
		return;
	}
	if (requiredGrade < bureaucrat.getGrade())
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat " << bureaucrat.getName()
			<< " signed Form " << name << std::endl;
	isSigned = true;
}
