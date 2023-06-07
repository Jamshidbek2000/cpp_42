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
		throw(Form::GradeTooHighException());
	if (inputRequiredGrade > 150)
		throw(Form::GradeTooLowException());
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
		throw(Form::FormIsAlreadySigned());
	if (requiredGrade < bureaucrat.getGrade())
		throw(Form::LowGradeToSignException());
	std::cout << "Bureaucrat " << bureaucrat.getName()
			<< " signed Form " << name << std::endl;
	isSigned = true;
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high for the form!\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low for the form!\n";
}

const char* Form::FormIsAlreadySigned::what() const throw()
{
	return "Form is already signed!\n";
}

const char* Form::LowGradeToSignException::what() const throw()
{
	return "Bureaucrat has lower grade than required!\n";
}
