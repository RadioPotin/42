# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 16:19:27 by saneveu           #+#    #+#              #
#    Updated: 2019/05/25 06:53:27 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

# src / obj files
SRC		= 	main.c \
			parsing.c \
			tools.c \
			setup.c \
			draw.c \
			event.c \
			calcul.c \
			event_ft.c \
			color.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror

# mlx library
MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx
MLX_LNK	= -L ./minilibx -l mlx -lXext -lX11 -L/usr/X11/lib -lXext -lX11 ##-framework OpenGL -framework AppKit ##

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./srcs/
INCDIR	= ./include/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "-->	Object-Compile"

$(FT_LIB):
	@make -C $(FT)
	@echo "=====	libft	====="
	@echo "\33[1;32mOk\33[0m"

$(MLX_LIB):
	@make -C $(MLX)
	@echo "=====	MiniLibX   ====="
	@echo "\33[1;32mOk\33[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "\33[1;5;32mit's good\33[0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "=====	Objects		====="
	@echo "\33[33mClean.\33[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "=====	Everything	====="
	@echo "\33[33mClean.\33[0m"

re: fclean all
