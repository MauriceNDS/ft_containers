CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I./header

HEADER =	header/iterator.hpp				\
			header/utility.hpp				\
			header/vector.hpp		

SRCS =		src/main.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = containers

RM = rm -rf

all:    $(MAIN)

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $<  -o $@ $(INCLUDES)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(MAIN)

re: fclean all

.PHONY: all clean fclean re