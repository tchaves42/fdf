# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 09:31:25 by tchaves           #+#    #+#              #
#    Updated: 2024/03/08 09:31:27 by tchaves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft.a
MINILIBX = libmlx.a
SRCC_FILES =	fdf.c checks.c map.c utils.c bresenham.c display.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRC:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME) 

$(NAME) : $(OBJ)
		@make -C libft
		@make -C minilibx
		$(CC) $(CFLAGS)  $(OBJ) $(INCLUDE) libft/$(LIBFT) minilibx/$(MINILIBX) -o $(NAME)  -lX11 -lXext -lm

clean : 
		@make clean -C libft
		${RM} ${OBJ}


fclean : clean
		@make fclean -C libft
		@make clean -C minilibx
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
