NAME = push_swap
#
NAME_B = checker
#
SRCS =	main.c lists_init.c string_utils.c \
		commands_swap_push.c lists_utils.c indexation.c \
		commands_basic.c commands_rotate.c commands_rev_rotate.c \
		check_for_sort.c sort_small.c sort_medium.c \
		sort_large.c sort_basic.c
#
SRCS_B =	checker_bonus.c lists_init_bonus.c string_utils_bonus.c \
		commands_swap_push_bonus.c lists_utils_bonus.c indexation_bonus.c \
		commands_basic_bonus.c commands_rotate_bonus.c \
		commands_rev_rotate_bonus.c check_for_sort_bonus.c sort_small_bonus.c \
		sort_medium_bonus.c sort_large_bonus.c sort_basic_bonus.c
#
HEADER = push_swap.h
OBJ = $(patsubst %.c, %.o, $(SRCS))
OBJ_B = $(patsubst %.c, %.o, $(SRCS_B))
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
#
.PHONY : all clean fclean re bonus
#
all : $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $@
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
bonus : $(NAME_B)
#
$(NAME_B) : $(OBJ_B) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_B) -o $@
#
clean :
	rm -f $(OBJ) $(OBJ_B)
#
fclean : clean
	$(RM) $(NAME) $(NAME_B)
#
re : fclean all