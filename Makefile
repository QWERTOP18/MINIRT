NAME		:= miniRT
CC			:= cc
FRAMEWORKS	:= -lmlx -lXext -lX11 -lm
CFLAGS		:= -Wall -Wextra -Werror -O2
OUT_DIR		:= objs
INCS_DIR	:= incs
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= minilibx
MLX			:= $(MLX_DIR)/libmlx.a

IDFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS 		:= $(addprefix srcs/, main.c system.c hook_handler.c)

OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)



all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX_DIR) $(FRAMEWORKS) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP $(IDFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OUT_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
	
sub:
	git submodule update --init --recursive

subup:
	git submodule update --remote

minirm:
	rm -rf $(MLX_DIR)

norm:
	@norminette $(SRCS) $(INCS_DIR)


.PHONY: all clean fclean re sub sub-update norm debug

-include $(DEPS)