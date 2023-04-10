#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class	PhoneBook{
private:
	Contact			_contacts[MAX_CONTACTS];
	unsigned int	_nb_contacts;
	unsigned int	_index_to_add;
public:
	PhoneBook(void);
	~PhoneBook(void);

	Contact				get_contact_at_index(const unsigned int index) const;
	int					execute_cmd(const std::string cmd);
	void				add_new_contact_from_input();
	void				print_contacts() const;
	unsigned int		get_nb_contacts() const;
	void				print_cell(std::string str) const;

	static void			get_user_input(std::string &input);
	static bool			is_wrong_cmd(const std::string &cmd);
	static void			print_wrong_cmd_msg(void);
	static std::string	get_input_to_add_contact(const std::string &prompt);
};
std::ostream& operator<<(std::ostream& os, const PhoneBook& phonebook);

// STRING MANIPULATION
void		str_trim(std::string &str,const char char_to_trim);
void		str_trim(std::string &str,const std::string chars_to_trim);
void		str_to_upper(std::string &str);
std::string	get_str_in_uppercase(const std::string str);


#endif