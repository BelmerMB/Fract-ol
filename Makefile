NAME =		fractol
HEADER =	./includes
SRC_DIR =	./src
OBJ_DIR =	./objects
LIBFT_DIR =	./printf
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)

SRC_FILES =	cal_func.c draw.c window_init.c handle_keys.c fractol.c handle_args.c \
ft_isfloat.c


SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
CFLAGS =	-g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re