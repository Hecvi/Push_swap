
CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc -g#-Wall -Wextra -Werror
SRC_DIR = srcs/
LIBFT_DIR = libft/
LIBFT_A = libft/libft.a
OBJ_DIR = obj/
PS_SRCS = push_swap.c check_data.c ft_split.c list.c free.c operations_one.c \
operations_two.c helper_functions.c helper_functions_2.c helper_functions_3.c \
helper_functions_4.c sort_usual.c sort.c
CHECKER_SRCS = checker.c check_data.c ft_split.c list.c free.c operations_one.c \
operations_two.c helper_functions.c helper_functions_2.c helper_functions_3.c \
helper_functions_4.c sort_usual.c sort.c

CHECKER_OBJ = ${CHECKER_SRCS:c=o}
PS_OBJ = ${PS_SRCS:c=o}

all: $(CHECKER) $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I libft/ -I include/ -c -o $@ $^

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	make -C libft/
	$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -I includes/ -o $(CHECKER)
	echo "\033[34m$(CHECKER)   was compiled\033[m"

$(PUSH_SWAP): $(LIBFT_A) $(addprefix $(OBJ_DIR), $(PS_OBJ)) libft/libft.a
	$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -o $(PUSH_SWAP)
	echo "\033[34m$(PUSH_SWAP) was compiled\033[m"

$(LIBFT_A):		FORCE
				make -C $(LIBFT_DIR)

FORCE:	;

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(CHECKER)
	echo "\033[31m$(CHECKER)   was deleted"
	rm -f $(PUSH_SWAP)
	echo "$(PUSH_SWAP) was deleted\033[m"

re: fclean all