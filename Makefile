#______command and their flags______#
RM = rm -rf
CFLAGS = #-Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm
CC = gcc
AR = ar -crs
INCLUDES = includes

#______directories______#
OBJ_DIR = obj
SRC_DIR = src
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______mandatory and bonus files______#
FILES = main.c exit.c inputs.c

#______patterns and substitutions______#
SOURCES = $(FILES:%.c=$(SRC_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


#______static library name______#
NAME = cub
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< $(MLXFLAGS) -o $@


$(LIB)/%.a:
	$(MAKE) all -C $(LIB)

re: fclean all

all: $(NAME)

#______cleaning______#
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean
fclean: clean
	$(RM) $(NAME)
