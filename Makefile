# Compiler and flags
NAME			:=	GrabAChicken
CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra
RM				:=	rm -f
SRC_DIR			:=	./src
LIBFT_DIR		:=	./src/libft/
LIBFT			:=	./src/libft/libft.a
DEF_COLOUR		:=	\033[0;39m
GREEN			:=	\033[1;92m

# OS-specific flags
ifeq ($(shell uname), Linux)
	MLX_DIR		:=	./minilibx-linux/
	MLX_URL		:=	https://github.com/42Paris/minilibx-linux.git
	MLX			:=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS	:=	 -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	MLX_DIR		:=	./minilibx_macos/
	MLX			:=	$(MLX_DIR)/libmlx.a
	INCLUDES	:=	-I/opt/X11/include -Imlx
	MLX_FLAGS	:=	-I/opt/X11/include -I/lib/minilibx_macos/ -lft -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Sources and Objects
SRCS		:=	$(addprefix $(SRC_DIR)/, errors.c free_memory.c game_initialization.c key_hook.c main.c \
								map_creation.c map_rendering.c map_valid_path.c map_validation.c \
								moves.c sprites_initialization.c win_screen_rendering.c )

OBJS		:=	$(SRCS:.c=.o)


all : $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN) $(NAME) ✔︎ $(DEF_COLOUR)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
ifeq ($(shell uname), Linux)
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_URL) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN) minilibx-linux installed! ✔︎ $(DEF_COLOUR)"
else
	@echo "$(GREEN) minilibx-macos already installed! ✔︎ $(DEF_COLOUR)"
endif

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Object files removed!$(DEF_COLOUR)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"

re: fclean all

.PHONY: clean fclean re all
