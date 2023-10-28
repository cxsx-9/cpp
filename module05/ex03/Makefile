NAME = Bureaucrat
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp	

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) *_target.txt
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re