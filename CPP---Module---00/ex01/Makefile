NAME = phonebook
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard src/*.cpp) \
		main.cpp
OBJ_DIR = obj
OBJ = $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)