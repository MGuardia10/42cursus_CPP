################################################################################
# COMPILER OPTIONS
################################################################################

NAME		=	PmergeMe
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

# COLORS
RED		=		\033[91;1m
GREEN	=		\033[92;1m
YELLOW	=		\033[93;1m
BLUE	=		\033[94;1m
PINK	=		\033[95;1m
CLEAR	=		\033[0m

################################################################################
# SOURCE FILES
################################################################################

# SOURCE
SRC			=	main.cpp \
				PmergeMe.cpp
				
# OBJECTS
OBJ_DIR		=	objs/
OBJ_FILES	=	$(SRC:%.cpp=$(OBJ_DIR)%.o)

################################################################################
# MAKEFILE RULES
################################################################################

all:	$(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)Compiling $(NAME)...$(CLEAR)"
	$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[$(NAME) --> OK]$(CLEAR)"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)Removing compiled files...$(CLEAR)"
	$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Object files removed correctly$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Removing binary files...$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Object files and binary removed correctly$(CLEAR)"

re: fclean all

.PHONY:	all clean fclean re

leaks: all
	@leaks -q --atExit -- ./$(NAME) 541325 2315 32 1243 56 463

linux: all
	@./$(NAME) `shuf -i 1-100000 -n 3000 | tr '\n' ' '`

macos: all
	@./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`