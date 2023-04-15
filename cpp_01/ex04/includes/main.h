#ifndef MAIN_H
#	define MAIN_H

#include <iostream>
#include <fstream>

bool	input_check(int argc, char **argv);
bool	file_to_ifstream(std::string file_name, std::ifstream& ifs);
bool	file_to_ofstream(std::string file_name, std::ofstream& ofs);
bool	replace_str_from_ifstream(std::ifstream &ifs, std::ofstream& ofs
								, std::string& remove, std::string& add);


#endif