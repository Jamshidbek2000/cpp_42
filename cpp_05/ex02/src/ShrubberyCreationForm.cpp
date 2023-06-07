#include "../include/ShrubberyCreationForm.hpp"

// ShrubberyCreationForm

// ************************************************************************** //
//                               CONSTRUCTORS / DESTRUCTOR                    //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", ShrubberyCreationForm::requiredSignGrade), target("target_shrubbery")
{
	std::cout << GREEN_TXT
			<< "ShrubberyCreationForm Default constructor is called"
			<< DEFAULT_TXT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & inputTarget) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::requiredSignGrade), target(inputTarget + "_shrubbery")
{
	std::cout << GREEN_TXT
			<< "ShrubberyCreationForm "
			<< target << ", parametric constructor is called"
			<< DEFAULT_TXT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : AForm(rhs)
{
	target = rhs.target;
	std::cout << GREEN_TXT
			<< "ShrubberyCreationForm "
			<< target << ", copy constructor is called"
			<< DEFAULT_TXT << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BLUE_TXT
			<< "ShrubberyCreationForm " << target << ", destructor is called"
			<< DEFAULT_TXT << std::endl;
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string	ShrubberyCreationForm::getTarget() const
{
	return target;
}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << ORANGE_TXT
			<< "ShrubberyCreationForm " << target << ", assignment operator is called"
			<< DEFAULT_TXT << std::endl;
	return *this;
}

// ************************************************************************** //
//                               REST                                         //
// ************************************************************************** //

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree = 
	"     ccee88oo          \n"
	"  C8O8O8Q8PoOb o8oo    \n"
	" dOB69QO8PdUOpugoO9bD  \n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"   6OuU  /p u gcoUodpP \n"
	"      \\\\//  /douUP   \n"
	"        \\\\////       \n"
	"         |||/\\        \n"
	"         |||\\/        \n"
	"         |||||         \n"
	"  .....\\//||||\\....  \n";

	if (getIsSigned() == false)
		throw(AForm::FormIsNotSignedException());
	if (executor.getGrade() > ShrubberyCreationForm::requiredExecGrade)
		throw (AForm::LowGradeToExecuteException());
	std::ofstream	outfile(target.c_str());
	if (!outfile)
      throw std::runtime_error("Failed to open the file for writing.");
	outfile << tree;
	std::cout << "ShrubberyCreationForm is executed successfully!" << std::endl;
}
