## VARIABLES ##

NAME = so_long
HEADERS = so_long.h

##DIRECTORIOS & LIB

PRINTF_DIR = ft_printf
GNL_DIR = ft_getNextLine
SL_DIR = so_long_functions
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

## ARCHIVOS FUENTE ##

SRCS =  $(PRINTF_DIR)/char_handler.c $(PRINTF_DIR)/ft_puthex.c $(PRINTF_DIR)/Libft_src/ft_putchar_fd.c \
		$(PRINTF_DIR)/pointer_handler.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/Libft_src/ft_putstr_fd.c \
		$(PRINTF_DIR)/ft_putdec.c $(PRINTF_DIR)/str_handler.c main_so_long.c $(GNL_DIR)/get_next_line_bonus.c\
		$(PRINTF_DIR)/Libft_src/ft_itoa.c $(PRINTF_DIR)/Libft_src/ft_strlen.c $(SL_DIR)/read_maps.c\
		$(GNL_DIR)/get_next_line_utils_bonus.c $(SL_DIR)/check_map.c $(SL_DIR)/init_window.c \
		$(SL_DIR)/load_draw_map.c $(SL_DIR)/hooks.c $(SL_DIR)/moves.c $(SL_DIR)/draw_player.c \
		$(SL_DIR)/is_reachable.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

## COMPILAR EJECUTABLE ##

all : $(NAME)

$(MLXX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME) : $(OBJS) Makefile $(HEADERS) $(MLX_LIB)
		gcc $(CFLAGS) $(OBJS) $(MLX_FLAGS)-o $(NAME)


## COMPILAR OBJETOS ##

%.o: %.c $(HEADERS)
		gcc $(CFLAGS) -c $< -o $@

## PHONYS ##

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
