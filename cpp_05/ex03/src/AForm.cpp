#include "../include/AForm.hpp"

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

AForm::AForm() : name("Default AForm"), isSigned(false), requiredGrade(150)
{
	std::cout << GREEN_TXT
			<< "AForm Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

AForm::AForm(std::string const & inputName, int inputRequiredGrade) : name(inputName), isSigned(false), requiredGrade(inputRequiredGrade)
{
	if (inputRequiredGrade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (inputRequiredGrade > 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << GREEN_TXT
			<< "AForm " << name << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

AForm::AForm(AForm const & rhs) : name(rhs.name), isSigned(false), requiredGrade(rhs.requiredGrade)
{
	std::cout << GREEN_TXT
			<< "AForm " << name << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

AForm::~AForm()
{
	std::cout << BLUE_TXT
			<< "AForm " << name << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string AForm::getName() const
{
	return name;
}

bool	AForm::getIsSigned() const
{
	return isSigned;
}

int	AForm::getRequiredGrade() const
{
	return requiredGrade;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
		isSigned = rhs.isSigned;
	std::cout << ORANGE_TXT
			<< "AForm " << name << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream & os, AForm & Aform)
{
	os << "AForm " << Aform.getName()
		<< "that requires grade "
		<< Aform.getRequiredGrade() << " is ";
	if (Aform.getIsSigned() == false)
		os << "not ";
	os << "signed." << std::endl;
	return os;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (isSigned == true)
	{
		std::cout << "Form " << name << " is already signed!" << std::endl;
		return;
	}
	if (requiredGrade < bureaucrat.getGrade())
		throw(AForm::LowGradeToSignException());
	std::cout << "Bureaucrat " << bureaucrat.getName()
			<< " signed Form " << name << std::endl;
	isSigned = true;
}

// ************************************************************************** //
//                               NESTED CLASS                                 //
// ************************************************************************** //

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return "Form is not signed!\n";
}

const char* AForm::LowGradeToSignException::what() const throw()
{
	return "Grade is lower than needed to sign the form!\n";
}

const char* AForm::LowGradeToExecuteException::what() const throw()
{
	return "Grade is lower than needed to execute the form!\n";
}
