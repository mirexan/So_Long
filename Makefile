## VARIABLES ##

NAME = so_long
HEADERS = so_long.h
##SRCS_DIR = SRCS_LIBFT
PRINTF_DIR = ft_printf
GNL_DIR = ft_getNextLine

## ARCHIVOS FUENTE ##

SRCS =  $(PRINTF_DIR)/char_handler.c $(PRINTF_DIR)/ft_puthex.c $(PRINTF_DIR)/Libft_src/ft_putchar_fd.c \
		$(PRINTF_DIR)/pointer_handler.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/Libft_src/ft_putstr_fd.c \
		$(PRINTF_DIR)/ft_putdec.c $(PRINTF_DIR)/str_handler.c main_so_long.c $(GNL_DIR)/get_next_line_bonus.c\
		$(PRINTF_DIR)/Libft_src/ft_itoa.c $(PRINTF_DIR)/Libft_src/ft_strlen.c  \
		$(GNL_DIR)/get_next_line_utils_bonus.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

## COMPILAR EJECUTABLE ##

all : $(NAME)

$(NAME) : $(OBJS) Makefile $(HEADERS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME)


## COMPILAR OBJETOS ##

%.o: %.c $(HEADERS) Makefile
		gcc $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re