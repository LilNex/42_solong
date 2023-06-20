NAME = so_long
NAME_BONUS = so_long_bonus

GNL = includes/gnl/get_next_line_bonus.c includes/gnl/get_next_line_utils_bonus.c
LIB_DIR = includes/libft
LIB = $(LIB_DIR)/libft.a
# SRC = so_long.c init.c gameplay.c assets/assets.c assets/map.c assets/map_validator.c

MANDATORY_SRCDIR = mandatory_src
MANDATORY_SRC = $(shell find $(MANDATORY_SRCDIR) -type f -name '*.c')
MANDATORY_HDRS = $(MANDATORY_SRCDIR)/$(NAME).h

MANDATORY_OBJDIR = obj
MANDATORY_OBJECTS = $(patsubst %.c, $(MANDATORY_OBJDIR)/%.o, $(MANDATORY_SRC))

BONUS_SRCDIR = bonus_src
BONUS_SRC = $(shell find $(BONUS_SRCDIR) -type f -name '*.c')
BONUS_HDRS = $(BONUS_SRCDIR)/$(NAME_BONUS).h

BONUS_OBJDIR = obj
BONUS_OBJECTS = $(patsubst %.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRC))

CC = cc
CFLAGS += -Wall -Wextra -Werror 
# -fsanitize=address

all: $(NAME) $(MANDATORY_HDRS)

$(LIB):
	make -C $(LIB_DIR)
	make -C $(LIB_DIR) clean

mandatory: $(NAME)

$(NAME): $(MANDATORY_OBJECTS) $(LIB) $(GNL)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(MANDATORY_OBJDIR)/%.o: %.c $(LIB) $(MANDATORY_HDRS)
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJECTS) $(LIB) $(GNL)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(BONUS_OBJDIR)/%.o: %.c $(LIB) $(BONUS_HDRS) 
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(MANDATORY_OBJDIR)
	rm -rf $(BONUS_OBJDIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
