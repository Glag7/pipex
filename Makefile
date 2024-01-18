NAME = pipex

COMP = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      utils.c \
      start.c \
      special_split.c \
      check_quotes.c \
      pipex.c \
      pipex_misc.c

SRC_BONUS = main_bonus.c \
      utils_bonus.c \
      start_bonus.c \
      here_doc_bonus.c \
      gen_file_bonus.c \
      special_split_bonus.c \
      check_quotes_bonus.c \
      pipex_bonus.c \
      pipex_misc_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : libft.a $(NAME)

libft.a :
	@make -C libft str arr file print
	@mv libft/libft.a libft.a

bonus : libft.a $(OBJ_BONUS)
	@$(COMP) $(CFLAGS) $^ libft.a -o $(NAME)

$(NAME) : $(OBJ)
	@$(COMP) $(CFLAGS) $^ libft.a -o $@

%.o : %.c
	@$(COMP) $(CFLAGS) -c $^ -o $@

clean :
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.a

re : fclean all

.PHONY: all fclean clean re bonus
