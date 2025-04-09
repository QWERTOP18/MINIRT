# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 14:08:51 by ymizukam          #+#    #+#              #
#    Updated: 2025/04/09 22:24:47 by ymizukam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ./miniRT
CC			:= cc
FRAMEWORKS	:= -lmlx -lXext -lX11 -lm
CFLAGS		:= -O2 -fPIE -Wall -Wextra #-Werror
DFLAGS      := -DGEN#-DNOINPUT -DDEBUG
VALGRIND    := valgrind -q#--leak-check=full --show-leak-kinds=all --track-origins=yes



SRCS :=  $(shell find srcs -type f -name "*.c") \
         $(shell find vector -type f -name "*.c") \
		 $(shell find list -type f -name "*.c") \
		 $(shell find console -type f -name "*.c") \
         $(shell find debug -type f -name "*.c")



OUT_DIR		:= objs
INCS_DIR	:= incs

VECTOR_DIR  := vector
LIST_DIR    := list

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= minilibx
MLX			:= $(MLX_DIR)/libmlx.a 

IFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(VECTOR_DIR) -I$(LIST_DIR) -Ilibbmp/includes


OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

COMPILE     := $(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS)


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(COMPILE) $(OBJS) $(LIBFT) -L$(MLX_DIR) $(FRAMEWORKS) -o $@

$(LIBFT): | $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR):
	git clone https://github.com/QWERTOP18/LIBFT.git $(LIBFT_DIR)

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

gen: fclean
	$(MAKE) DFLAGS='-DGEN' all
	# $(NAME) sample.rt 2>/dev/null

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
	@norminette $(shell find srcs -type f -name "*.c") \
         $(shell find vector -type f -name "*.c") \
		 $(shell find list -type f -name "*.c") \
		 $(shell find console -type f -name "*.c") \
	     $(INCS_DIR) | grep -v "Comment is invalid in this scope" | grep -v "IMPLICIT_VAR_TYPE" | grep -v "OK!"

func: all


.PHONY: all clean fclean re sub sub-update norm debug

-include $(DEPS)