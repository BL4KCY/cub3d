#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 #-Ofast
MLXFLAGS = -lmlx -lXext -lX11 -lm 

#______directories______#
OBJ_DIR = obj
SRC_LGC_DIR = src/logic
SRC_PARS_DIR = src/parsing
INCLUDES = inc
LIB_INCLUDES = libft
#______directories <bonus______#
OBJ_DIR_BNS = obj_bonus
SRC_LGC_DIR_BNS = src_bonus/logic
SRC_PARS_DIR_BNS = src_bonus/parsing
INCLUDES_BNS = inc_bonus

#______mandatory and bonus files______#
FILES_EXEC := exit.c inputs.c rendering.c draw.c init.c\
		convert.c raycasting.c horizontal_cast.c vertical_cast.c\
		draw_utils.c image_updating.c rendering3d.c init_textures.c
FILES_PARS := main.c bfs.c helper_functions.c pars_map_holdercd.c enqueue.c\
		pars_map_holdercd_cont.c ft_pars_for_each.c pars_c_Floor.c\
		pars_texturs.c get_next_line.c pars_c_floor_utils.c func_bonus.c


#______patterns and substitutions______#
SOURCES := $(addprefix $(SRC_LGC_DIR)/, $(FILES_EXEC)) $(addprefix $(SRC_PARS_DIR)/, $(FILES_PARS))
OBJECTS := $(patsubst $(SRC_LGC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
OBJECTS := $(patsubst $(SRC_PARS_DIR)/%.c, $(OBJ_DIR)/%.o, $(OBJECTS))
HEADERS := $(INCLUDES)/cub3d.h $(LIB_INCLUDES)/libft.h $(INCLUDES)/structs.h $(INCLUDES)/macros.h

#______patterns and substitutions <bonus>______#
SOURCES_BNS := $(addprefix $(SRC_LGC_DIR_BNS)/, $(FILES_EXEC)) $(addprefix $(SRC_PARS_DIR_BNS)/, $(FILES_PARS))
OBJECTS_BNS := $(patsubst $(SRC_LGC_DIR_BNS)/%.c, $(OBJ_DIR_BNS)/%.o, $(SOURCES_BNS))
OBJECTS_BNS := $(patsubst $(SRC_PARS_DIR_BNS)/%.c, $(OBJ_DIR_BNS)/%.o, $(OBJECTS_BNS))
HEADERS_BNS := $(INCLUDES_BNS)/cub3d.h $(LIB_INCLUDES)/libft.h $(INCLUDES_BNS)/structs.h $(INCLUDES_BNS)/macros.h

#______static library name______#
NAME = cub3D
BONUS_NAME = cub3D_bonus
LIB = libft

#______________Rules______________#
#______mandatory______#
all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

# impicit rule for logic mandatory
$(OBJ_DIR)/%.o: $(SRC_LGC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@
# impicit rule for parsing mandatory
$(OBJ_DIR)/%.o: $(SRC_PARS_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@
#______bonus______#
$(BONUS_NAME): $(OBJECTS_BNS) $(LIB)/libft.a
	$(CC) $(CFLAGS) $^ -I$(INCLUDES_BNS) -I$(LIB_INCLUDES) $(MLXFLAGS) -o $@

# impicit rule for logic bonus
$(OBJ_DIR_BNS)/%.o: $(SRC_LGC_DIR_BNS)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR_BNS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@
# impicit rule for parsing bonus
$(OBJ_DIR_BNS)/%.o: $(SRC_PARS_DIR_BNS)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR_BNS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIB_INCLUDES) -c $< -o $@

$(LIB)/%.a:
	@echo "Compiling libft"
	@$(MAKE) all -C $(LIB)
	@echo "Compiled libft"

re: fclean all


run: all
	./$(NAME) maps/map.cub

bonus: $(BONUS_NAME)
#______cleaning______#
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_DIR_BNS)
	@$(MAKE) -C $(LIB) fclean
	@echo "cleaned"
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "fcleaned"

.SECONDARY: