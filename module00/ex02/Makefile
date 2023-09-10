NAME = Account
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp \
		tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re