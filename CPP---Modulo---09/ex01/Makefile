NAME = RPN

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	@echo "compiling $< to $@..."
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\033[92m$(NAME) was compiled! ♡ \033[0m"

all: $(NAME)

re: fclean
	@make all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)
