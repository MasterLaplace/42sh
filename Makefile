##
## EPITECH PROJECT, 2022
## B-PSU-210-REN-2-1-42sh-guillaume.papineau
## File description:
## Makefile
##

-include .env
export

BUILTINS = builtins/

OPERATOR = operators/

LINK = link/

SCRIPT = script/

INIT = init/

ENV = env/

ALIAS = alias/

VAR = var/

BOT = bot/

MAN = man/

HISTORY = history/

CLOSE = close/

SRC_DIR = src/

SRC =	$(SRC_DIR)$(BUILTINS)handling_builtin.c		\
		$(SRC_DIR)$(BUILTINS)builtin_cd.c			\
		$(SRC_DIR)$(BUILTINS)builtin_exit.c			\
		$(SRC_DIR)$(BUILTINS)builtin_meme.c			\
		$(SRC_DIR)$(BUILTINS)$(ENV)builtin_env.c		\
		$(SRC_DIR)$(BUILTINS)$(ENV)builtin_setenv.c		\
		$(SRC_DIR)$(BUILTINS)$(ENV)builtin_unsetenv.c	\
		$(SRC_DIR)$(BUILTINS)$(ALIAS)add_alias.c		\
		$(SRC_DIR)$(BUILTINS)$(ALIAS)check_alias.c		\
		$(SRC_DIR)$(BUILTINS)$(ALIAS)print_alias.c		\
		$(SRC_DIR)$(BUILTINS)$(ALIAS)norm.c				\
		$(SRC_DIR)$(BUILTINS)$(VAR)add_var.c		\
		$(SRC_DIR)$(BUILTINS)$(VAR)check_var.c		\
		$(SRC_DIR)$(BUILTINS)$(VAR)print_var.c		\
		$(SRC_DIR)$(BUILTINS)$(BOT)activate.c		\
		$(SRC_DIR)$(BUILTINS)$(BOT)data.c			\
		$(SRC_DIR)$(BUILTINS)$(BOT)talk.c			\
		$(SRC_DIR)$(BUILTINS)$(BOT)add_tree.c		\
		$(SRC_DIR)$(BUILTINS)$(BOT)print_tree.c		\
		$(SRC_DIR)$(BUILTINS)$(MAN)handling_man.c		\
		$(SRC_DIR)$(BUILTINS)$(MAN)preset_man.c			\
		$(SRC_DIR)$(BUILTINS)$(HISTORY)add_command.c		\
		$(SRC_DIR)$(BUILTINS)$(HISTORY)print_history.c		\
		$(SRC_DIR)$(BUILTINS)$(HISTORY)check_reminder.c		\
		$(SRC_DIR)$(BUILTINS)$(HISTORY)check_two_reminder.c	\
		$(SRC_DIR)$(LINK)append_link.c				\
		$(SRC_DIR)$(LINK)create_link.c				\
		$(SRC_DIR)$(LINK)remove_link.c				\
		$(SRC_DIR)$(OPERATOR)create_chunks.c		\
		$(SRC_DIR)$(OPERATOR)handling_operators.c	\
		$(SRC_DIR)$(OPERATOR)parth_string.c			\
		$(SRC_DIR)$(OPERATOR)redirection.c			\
		$(SRC_DIR)$(OPERATOR)pipe.c					\
		$(SRC_DIR)$(SCRIPT)get_file.c				\
		$(SRC_DIR)$(SCRIPT)handle_script.c			\
		$(SRC_DIR)$(INIT)init_sh.c					\
		$(SRC_DIR)$(CLOSE)free_sh.c					\
		$(SRC_DIR)$(CLOSE)clean_sh.c				\
		$(SRC_DIR)prompt.c							\
		$(SRC_DIR)style.c							\
		$(SRC_DIR)parthing.c						\
		$(SRC_DIR)error.c							\
		$(SRC_DIR)flags_sh.c						\

SRC_MAIN = $(SRC_DIR)core.c

OBJ =	$(SRC:.c=.o) $(SRC_MAIN:.c=.o)

NAME =	42sh

INCLUDE = -I ./includes

LIB = ./lib/my

LIB_ALL = -L $(LIB) -l my

CURSE = -lncurses

CFLAGS =	$(FLAGS) -W $(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C $(LIB) $(NO_PRINT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB_ALL) $(CURSE) \
	&& $(ECHO) $(BOLD) $(GREEN) "☻ GOOD" $(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED) "Ø ERROR" $(DEFAULT) && exit 1)

clean:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) *#
	@cd $(LIB) && make clean $(NO_PRINT)
	@$(RM) *~
	@$(RM) *#
	@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIB) && make fclean $(NO_PRINT)
	@$(RM) *.gcda
	@$(RM) *.gcno
	@$(RM) vgcore.*
	@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re: fclean all

debug:	CFLAGS += -g
debug:	clean $(OBJ)
	@make debug -C $(LIB) $(NO_PRINT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB_ALL)

%.o: 	%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)" [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)" [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d/ -f 1 | rev && $(ECHO) -n $(DEFAULT)

update:
	@git pull

.PHONY: all re clean fclean debug %.o
