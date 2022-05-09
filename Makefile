CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
STLFLAG = -DSTL_CONTAINERS

INCLUDES = -I./header

HEADER =	header/iterator.hpp				\
			header/map.hpp					\
			header/set.hpp					\
			header/stack.hpp				\
			header/tree.hpp					\
			header/type_traits.hpp			\
			header/utility.hpp				\
			header/vector.hpp				\

SRCS =		src/main.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = containers
MAIN2 = containers_stl

RM = rm -rf

all:    $(MAIN)

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

stl: $(OBJS)
		$(CC) $(CFLAGS) -D STL_CONTAINERS -c $(SRCS) -o $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN2) $(OBJS)

%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $<  -o $@ $(INCLUDES)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(MAIN)
		$(RM) $(MAIN2)

re: fclean all

.PHONY: all clean fclean re stl