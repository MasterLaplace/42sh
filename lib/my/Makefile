##
## EPITECH PROJECT, 2022
## B-PSU-210-REN-2-1-42sh-guillaume.papineau
## File description:
## Makefile
##

-include .env
export

PRINTF = my_printf/

SRC =	$(PRINTF)my_printf.c	\
		$(PRINTF)operat1.c		\
		$(PRINTF)operat2.c		\
		my_append.c			\
		my_choice.c			\
		my_clean_string.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_conv_bse.c		\
		my_count_char.c		\
		my_count_word.c		\
		my_cut.c			\
		my_getnbr.c			\
		my_index_char.c		\
		my_index_strncmp.c	\
		my_index_strndup.c	\
		my_init_seed.c		\
		my_is_prime.c		\
		my_isalpha.c		\
		my_islower.c		\
		my_isneg.c			\
		my_isnum.c			\
		my_isnumalpha.c		\
		my_isoperator.c		\
		my_issort.c			\
		my_isupper.c		\
		my_itoa.c			\
		my_max_len_tab.c	\
		my_openfile.c		\
		my_put_error.c		\
		my_putchar.c		\
		my_putnbr.c			\
		my_putnbrl.c		\
		my_putstr.c			\
		my_randint.c		\
		my_realloc.c		\
		my_reboot.c		\
		my_revstr.c			\
		my_set_limit.c		\
		my_sort_int_array.c	\
		my_strcat.c			\
		my_strcmp.c		\
		my_strcopy.c		\
		my_strdup.c			\
		my_strlen.c			\
		my_strlowcase.c		\
		my_strncmp.c		\
		my_strncopy.c		\
		my_strndup.c		\
		my_strupcase.c		\
		my_stwa.c			\
		my_suppr.c			\
		my_swap_str.c		\
		my_swap.c			\
		my_two_append.c		\
		my_two_count_char.c	\
		my_two_count_str.c	\
		my_two_cut.c		\
		my_two_dup.c		\
		my_two_free.c		\
		my_two_len.c		\
		my_two_put.c		\
		my_two_putnbr.c		\
		my_two_suppr.c		\
		my_char_in_list.c	\
		my_str_to_word_array.c		\
		my_str_to_word_array_m.c		\
		my_strtok.c	\
		my_meme.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

CFLAGS = -I ../../includes

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ) \
	&& $(ECHO) $(BOLD) $(GREEN) "☻ MY_GOOD" $(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED) "Ø MY_ERROR" $(DEFAULT) && exit 1)

clean:
	@$(RM) $(OBJ)
	@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN LIBMY "$(DEFAULT))

fclean: clean
	@$(RM) $(NAME)
	@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN LIBMY "$(DEFAULT))

re: fclean all

debug:	CFLAGS += -g
debug:	re

%.o:	%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)" [MY_OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)" [MY_KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d/ -f 1 | rev && $(ECHO) -n $(DEFAULT)
