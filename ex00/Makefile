#CXX is short for CPP Compiler
CXX:=c++
NAME:=prg
SRCS:=main.cpp
OBJS:= ${SRCS:.cpp=.o} 
CPPFLAGS:=-Wall -Wextra -Werror -std=c++98 

all: $(NAME) easyfind.hpp

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

go: 
	make all
	./$(NAME)

ergo: 
	make re
	./$(NAME)


.PHONY: all clean fclean re go ergo
