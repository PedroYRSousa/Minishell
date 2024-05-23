NAME					=	libft.a

INC_DIR					=	-I./includes

CC						=	gcc

CFLAGS					=	-Wall -Wextra -Werror -g ${INC_DIR}

SOURCES					=	\
							./src/checkers/ft_isalnum.c \
							./src/checkers/ft_isalpha.c \
							./src/checkers/ft_isascii.c \
							./src/checkers/ft_isdigit.c \
							./src/checkers/ft_isprint.c \
							./src/checkers/ft_islower.c \
							./src/checkers/ft_isupper.c \
							./src/conversors/ft_atoi.c \
							./src/conversors/ft_itoa.c \
							./src/conversors/ft_tolower.c \
							./src/conversors/ft_toupper.c \
							./src/memory/ft_bzero.c \
							./src/memory/ft_calloc.c \
							./src/memory/ft_memccpy.c \
							./src/memory/ft_memchr.c \
							./src/memory/ft_memcmp.c \
							./src/memory/ft_memcpy.c \
							./src/memory/ft_memmove.c \
							./src/memory/ft_memset.c \
							./src/string/ft_replace.c \
							./src/string/ft_strcatchr.c \
							./src/string/ft_split.c \
							./src/string/ft_strchr.c \
							./src/string/ft_strdup.c \
							./src/string/ft_strjoin.c \
							./src/string/ft_strlcat.c \
							./src/string/ft_strlcpy.c \
							./src/string/ft_strlen.c \
							./src/string/ft_strmapi.c \
							./src/string/ft_strcmp.c \
							./src/string/ft_strncmp.c \
							./src/string/ft_strnstr.c \
							./src/string/ft_strrchr.c \
							./src/string/ft_strtrim.c \
							./src/string/ft_substr.c \
							./src/string/ft_substrstr.c \
							./src/writers/ft_putchar_fd.c \
							./src/writers/ft_putendl_fd.c \
							./src/writers/ft_putnbr_fd.c \
							./src/writers/ft_putstr_fd.c \
							./src/matrix/ft_addmatrix.c \
							./src/matrix/ft_clearmatrix.c \
							./src/matrix/ft_creatematrix.c \
							./src/matrix/ft_countmatrix.c \
							
OBJS_DIR				=	./objs

OBJS					=	$(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):	${OBJS}
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n\033[0;32mDone !"
	@echo -n "\033[0m"

%.o:		%.c
	@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -rf ${OBJS}

fclean:		clean
	@rm -f $(NAME)

re:			fclean	all

.PHONY:		all		clean	fclean	re