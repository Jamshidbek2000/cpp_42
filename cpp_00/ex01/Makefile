NAME = phonebook
CC = g++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		=	main \
			str_manipulation \
			Contact \
			PhoneBook \
			

HEADERS	=	includes/Contact.hpp \
			includes/PhoneBook.hpp \

SRC_DIR = src/
OBJ_DIR = objects/

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME) 

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
.PHONY: all clean fclean re