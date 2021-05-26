NAME	= libftprintf.a

CC	= gcc
FLAGS	= -Wall -Wextra -Werror

LIBFT	= libft
DIR_S	= src
HEADER	= includes

SOURCES	= ft_printf.c parse.c utilities.c \
	  process_cs.c process_diouxp.c process_f.c

SRCS	= $(addprefix $(DIR_S)/, $(SOURCES))
OBJS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re:	fclean all

.PHONY:	all clean fclean re
