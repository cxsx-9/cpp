CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(OBJS)

%.o: %.cpp 
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf a.out

re: fclean all

.PHONY: all clean fclean re