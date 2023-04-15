#include "../includes/Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. " << std::endl;
	std::cout << "You didn't put enough bacon in my burger! " << std::endl;
	std::cout << "If you did I wouldn't be asking for it!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int	id = -1;

	std::string	str_ft[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::* ptr_ft[4]) () = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
		if (level.compare(str_ft[i]) == 0)
			id = i;
	switch (id)
	{
		case 0:
			std::cout << "[ " << str_ft[0] << " ]" << std::endl;
			(this->*ptr_ft[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << str_ft[1] << " ]" << std::endl;
			(this->*ptr_ft[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << str_ft[2] << " ]" << std::endl;
			(this->*ptr_ft[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << str_ft[3] << " ]" << std::endl;
			(this->*ptr_ft[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
