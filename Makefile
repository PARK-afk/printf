CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = ft_printf.h
SRCS = ft_printf.c ft_print_hex.c ft_print_unsigned.c ft_print_add.c ft_print_number.c ft_print_percent.c ft_print_string.c ft_print_unsigned.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rsc $@ $^

.c.o :
	$(CC) $(CFAGS) -I $(HEAD) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all re clean fclean
