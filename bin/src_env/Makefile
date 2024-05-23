NAME					=	../env

LIBFT_DIR				=	../../libs/libft

INC_DIR					=	-I./includes -I../../libs/libft/includes

CC						=	gcc

CFLAGS					=	-Wall -Wextra -Werror -g ${INC_DIR}

LFLAGS					=	-Wall -Wextra -Werror -g -L${LIBFT_DIR} -lft

SOURCES					=	\
							./src/main.c \

OBJS					=	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\n\033[0;32mDone !"
	@echo -n "\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating env objects... %-33.33s\r" $@
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re