#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 3

enum InputType
{
    TEXT,
    NUMBER
};

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
	void				search_contact(void) const;
	void				print_contacts() const;

	// GETTERS
	unsigned int		get_nb_contacts() const;

	// STATIC  FUNCTIONS
	static void			get_user_input(std::string &input);
	static bool			is_wrong_cmd(const std::string &cmd);
	static void			print_wrong_cmd_msg(void);
	static std::string	get_input_to_add_contact(const std::string &prompt, InputType input_type);

	// OPERATOR OVERWRITING
	void				print_cell(std::string str) const;
	void				print_columns(void) const;
};
std::ostream& operator<<(std::ostream& os, const PhoneBook& phonebook);

// STRING MANIPULATION
void		str_trim(std::string &str,const char char_to_trim);
void		str_trim(std::string &str,const std::string chars_to_trim);
void		str_to_upper(std::string &str);
std::string	get_str_in_uppercase(const std::string str);
bool		is_str_digits(const std::string& str);
std::string	int_to_str(int num);
int			str_to_int(std::string str);


#endif