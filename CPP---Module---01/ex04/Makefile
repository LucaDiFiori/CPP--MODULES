NAME = losers
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *.replace

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)