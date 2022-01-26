NAME := circlelist

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCS := main.c \
		addDLElement.c \
		createCircularList.c \
	
OBJ_DIR := ./objs/
OBJ_NAME := $(SRCS:.c=.o)
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_NAME))

.PHONY : all clean fclean re norm

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		@rm -rf $(OBJ_DIR)
		@echo "\x1b[31mCLEAN_ $(NAME)\x1b[0m"

fclean : clean
		@rm -f $(NAME)
		@echo "\x1b[31;101mFCLEAN_$(NAME)\x1b[0m"

re : fclean all
