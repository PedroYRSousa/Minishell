BIN_DIR			=	./bin
BIN_ENV_DIR		=	${BIN_DIR}/src_env
BIN_PWD_DIR		=	${BIN_DIR}/src_pwd
BIN_ECHO_DIR	=	${BIN_DIR}/src_echo

SRC_DIR			=	./src
ENV_DIR			=	${SRC_DIR}/env
INFO_DIR		=	${SRC_DIR}/info
UTIL_DIR		=	${SRC_DIR}/util
BLOCK_DIR		=	${SRC_DIR}/block
SYNTAX_DIR		=	${SRC_DIR}/syntax
PARSER_DIR		=	${SRC_DIR}/parser
ERROR_DIR		=	${SRC_DIR}/ms_error
EXECUTOR_DIR	=	${SRC_DIR}/executor
EXPANSOR_DIR	=	${SRC_DIR}/expansor
RESOLVER_DIR	=	${SRC_DIR}/resolver

UTIL_FILES		=	${UTIL_DIR}/skip_quotes.c \
					${UTIL_DIR}/remove_quotes.c
SRC_FILES		=	${SRC_DIR}/main.c
ERROR_FILES		=	${ERROR_DIR}/show_error_syntax.c \
					${ERROR_DIR}/show_error_execve.c \
					${ERROR_DIR}/show_warning_here_doc.c \
					${ERROR_DIR}/show_error_command_not_found.c
SYNTAX_FILES	=	${SYNTAX_DIR}/syntax.c
ENV_FILES		=	${ENV_DIR}/get_env.c\
					${ENV_DIR}/add_env.c \
					${ENV_DIR}/set_env.c \
					${ENV_DIR}/load_env.c \
					${ENV_DIR}/get_envs.c \
					${ENV_DIR}/clear_env.c \
					${ENV_DIR}/unset_env.c \
					${ENV_DIR}/create_env.c \
					${ENV_DIR}/remove_env.c \
					${ENV_DIR}/get_instance_env.c
BLOCK_FILES		=	${BLOCK_DIR}/add_block.c \
					${BLOCK_DIR}/show_blocks.c \
					${BLOCK_DIR}/create_block.c \
					${BLOCK_DIR}/clear_blocks.c \
					${BLOCK_DIR}/get_instance_block.c \
						${BLOCK_DIR}/command/add_argument.c \
						${BLOCK_DIR}/command/create_command.c \
						${BLOCK_DIR}/command/add_redirection.c \
							${BLOCK_DIR}/command/redirection/create_redirection.c
INFO_FILES		=	${INFO_DIR}/load_info.c \
					${INFO_DIR}/reset_fds.c \
					${INFO_DIR}/clear_info.c \
					${INFO_DIR}/get_instance_info.c
PARSER_FILES	=	${PARSER_DIR}/parser.c
EXECUTOR_FILES	=	${EXECUTOR_DIR}/executor.c \
					${EXECUTOR_DIR}/ms_cd.c \
					${EXECUTOR_DIR}/ms_exit.c \
					${EXECUTOR_DIR}/ms_unset.c \
					${EXECUTOR_DIR}/ms_export.c \
					${EXECUTOR_DIR}/exec_here_doc.c \
					${EXECUTOR_DIR}/exec_redirections.c
EXPANSOR_FILES	=	${EXPANSOR_DIR}/expansor.c
RESOLVER_FILES	=	${RESOLVER_DIR}/resolver.c

#	Config compile

NAME			=	minishell

LIBFT_DIR		=	./libs/libft

INC_DIR			=	-I./includes -I${LIBFT_DIR}/includes

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g ${INC_DIR}

LFLAGS			=	-Wall -Wextra -Werror -g -L${LIBFT_DIR} -lft -lreadline

SOURCES			=	\
					${SRC_FILES} \
					${ENV_FILES} \
					${UTIL_FILES} \
					${INFO_FILES} \
					${BLOCK_FILES} \
					${ERROR_FILES} \
					${SYNTAX_FILES} \
					${PARSER_FILES} \
					${EXECUTOR_FILES} \
					${EXPANSOR_FILES} \
					${RESOLVER_FILES} \

OBJS			=	$(SOURCES:.c=.o)

#	######

#	Commands

all: libft echo env pwd $(NAME)

$(NAME): ${OBJS}
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\n\033[0;32mDone !"
	@echo -n "\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@make fclean --no-print-directory -C ${LIBFT_DIR}
	@make fclean --no-print-directory -C ${BIN_ECHO_DIR}
	@make fclean --no-print-directory -C ${BIN_ENV_DIR}
	@make fclean --no-print-directory -C ${BIN_PWD_DIR}
	@rm -f $(NAME)

re: fclean all

libft:
	@clear;
	@make --no-print-directory -C ${LIBFT_DIR}

echo:
	@make --no-print-directory -C ${BIN_ECHO_DIR}

pwd:
	@make --no-print-directory -C ${BIN_PWD_DIR}

env:
	@make --no-print-directory -C ${BIN_ENV_DIR}

test:
	clear && make re && valgrind --leak-check=full --show-reachable=yes --suppressions=./supp/readline.supp ./minishell 2> teste.txt

.PHONY: all clean fclean re libft echo pwd env test

#	######