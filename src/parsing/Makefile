# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohammedmad <mohammedmad@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 17:07:12 by mohammedmad       #+#    #+#              #
#    Updated: 2024/09/09 18:08:33 by mohammedmad      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GET_NEXT_LINE = get_next_line

PARS_TEXTURES = parsing/ParsTextures

PARS_C_FLOR = parsing/Pars_C_Flor

PARS_MAP = parsing/ParsMap

PARS_UTILS = parsing/ParsingUtils

SRC = main.c\
	$(GET_NEXT_LINE)/get_next_line.c\
	$(PARS_TEXTURES)/pars_texturs.c\
	$(PARS_C_FLOR)/pars_c_Floor.c\
	$(PARS_C_FLOR)/pars_c_floor_utils.c\
	$(PARS_MAP)/bfs.c\
	$(PARS_MAP)/enqueue.c\
	$(PARS_MAP)/helper_functions.c\
	$(PARS_UTILS)/ft_pars_for_each.c\
	$(PARS_UTILS)/pars_map_holdercd.c\
	$(PARS_UTILS)/pars_map_holdercd_cont.c\

OBJ = $(SRC:.c=.o)

NAME = cub3d

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME) $(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make -s -C ./libft
	@echo "Libft done"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(LNAME)

clean:
	@make -s -C ./libft clean
	rm -f $(OBJ) $(OBJ_BONUS)
	@echo "Clean done"

fclean : clean
	@make -s -C ./libft fclean
	rm -f $(NAME) $(LNAME)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJ) $(OBJ_BONUS)
