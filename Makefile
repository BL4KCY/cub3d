#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Ofast#-fsanitize=address#-Ofast
MLXFLAGS = -lmlx -lXext -lX11 -lm 
AR = ar -crs

#______directories______#
OBJ_DIR = obj
SRC_LGC_DIR = src/logic
SRC_PARS_DIR = src/parsing
INCLUDES = inc
LIB_INCLUDES = libft

#______mandatory and bonus files______#
FILES_EXEC = exit.c inputs.c rendering.c draw.c init.c\
		convert.c raycasting.c horizontal_cast.c vertical_cast.c\
		draw_utils.c image_updating.c rendering3d.c init_textures.c
FILES_PARS = main.c bfs.c helper_functions.c pars_map_holdercd.c enqueue.c\
		pars_map_holdercd_cont.c ft_pars_for_each.c pars_c_Floor.c\
		pars_texturs.c get_next_line.c pars_c_floor_utils.c 


#______patterns and substitutions______#
SOURCES = $(FILES_EXEC:%.c=$(SRC_LGC_DIR)/%.c) $(FILES_PARS:%.c=$(SRC_PARS_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_LGC_DIR)%.c=$(OBJ_DIR)%.o)
HEADERS = $(INCLUDES)/cub3d.h $(LIB_INCLUDES)/libft.h $(INCLUDES)/structs.h $(INCLUDES)/macros.h


#______static library name______#
NAME = cub3D
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_LGC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@


$(LIB)/%.a:
	$(MAKE) all -C $(LIB)

re: fclean all

all: $(NAME)

run: all
	./$(NAME) maps/map.cub

#______cleaning______#
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean
fclean: clean
	$(RM) $(NAME)

.SECONDARY: $(OBJECTS) $(LIB)/libft.a