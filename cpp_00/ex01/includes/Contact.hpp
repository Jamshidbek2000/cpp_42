#ifndef CONTACT_HPP
#	define CONTACT_HPP

#include <iostream>

class	Contact{
private:
	std::string _name;
	std::string _surname;
	std::string _nickname;
	std::string _secret;
	std::string _phone_number;

public:
	Contact(void);
	~Contact(void);

	std::string get_name(void) const;
	std::string get_surname(void) const;
	std::string get_nickname(void) const;
	std::string get_secret(void) const;
	std::string get_phone_number(void) const;

	bool		set_name(const std::string name);
	bool		set_surname(const std::string surname);
	bool		set_nickname(const std::string nickname);
	bool		set_secret(const std::string secret);
	bool		set_phone_number(const std::string phone_number);
};

std::ostream& operator<<(std::ostream& os, const Contact& contact); 

#endif