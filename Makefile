NAME		:= ./miniRT
CC			:= cc
FRAMEWORKS	:= -lmlx -lXext -lX11 -lm
CFLAGS		:= -O2 -Wall -Wextra #-Werror
DFLAGS      := -DNOINPUT -DDEBUG
VALGRIND    := valgrind -q#--leak-check=full --show-leak-kinds=all --track-origins=yes



SRCS := $(wildcard srcs/*.c vector/*.c list/*.c debug/*.c console/*.c srcs/intersection/*.c)



OUT_DIR		:= objs
INCS_DIR	:= incs

VECTOR_DIR  := vector
LIST_DIR    := list

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= minilibx
MLX			:= $(MLX_DIR)/libmlx.a

IFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(VECTOR_DIR) -I$(LIST_DIR)


OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

COMPILE     := $(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(COMPILE) $(OBJS) $(LIBFT) -L$(MLX_DIR) $(FRAMEWORKS) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(COMPILE) -MMD -MP -c $< -o $@

clean:
	# $(MAKE) -C $(LIBFT_DIR) clean
	# $(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OUT_DIR)

fclean: clean
	# $(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all


run: $(NAME)
	$(NAME) sample.rt 2>/dev/null

log: $(NAME)
	$(NAME) sample.rt

val: $(NAME)
	$(VALGRIND) $(NAME) sample.rt 



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