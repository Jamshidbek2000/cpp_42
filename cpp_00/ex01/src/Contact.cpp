#include "../includes/Contact.hpp"

Contact::Contact(void) : _name(""), _surname(""), _nickname(""), _secret(""), _phone_number("")
{}

Contact::~Contact(void){}

// ************************************************************************** //
//                               SETTERS                                      //
// ************************************************************************** //

bool	Contact::set_name(const std::string name)
{
	if (name.empty())
		return (false);
	_name = name;
	return (true);
}

bool	Contact::set_surname(const std::string surname)
{
	if (surname.empty())
		return (false);
	_surname = surname;
	return (true);
}

bool	Contact::set_nickname(const std::string nickname)
{
	if (nickname.empty())
		return (false);
	_nickname = nickname;
	return (true);
}

bool	Contact::set_secret(const std::string secret)
{
	if (secret.empty())
		return (false);
	_secret = secret;
	return (true);
}

bool	Contact::set_phone_number(const std::string phone_number)
{
	if (phone_number.empty())
		return (false);
	_phone_number = phone_number;
	return (true);
}

// ************************************************************************** //
//                               GETTERS                                      //
// ************************************************************************** //

std::string	Contact::get_name(void) const {return (_name);}
std::string	Contact::get_surname(void) const {return (_surname);}
std::string	Contact::get_nickname(void) const {return (_nickname);}
std::string	Contact::get_secret(void) const {return (_secret);}
std::string	Contact::get_phone_number(void) const {return (_phone_number);}

// ************************************************************************** //
//                               OPERATOR OVERWRITING                         //
// ************************************************************************** //

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
    os << "Contact: " << std::endl;
	os << "\tName: " << contact.get_name() << std::endl;
	os << "\tSurname: " << contact.get_surname() << std::endl;
	os << "\tNickname: " << contact.get_nickname() << std::endl;
	os << "\tDarkest secret: " << contact.get_secret() << std::endl;
	os << "\tPhone number: " << contact.get_phone_number() << std::endl;
    return os;
}
