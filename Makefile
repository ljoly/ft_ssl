# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 19:54:48 by ljoly             #+#    #+#              #
#    Updated: 2018/10/11 19:40:03 by ljoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC_SSL = main.c md5.c tables.c error.c get_format.c build_meta.c \
		handle_input.c print.c sha2.c bitwise_op.c \

SRC_PARSING = parser.c lexer.c read_fd.c state_a.c state_b.c state_c.c\

SSL_PATH = ./src/
PARSING_PATH = ./src/parsing/

SRCS = $(addprefix $(SSL_PATH), $(SRC_SSL)) \
		$(addprefix $(PARSING_PATH), $(SRC_PARSING)) \

OBJ = $(SRCS:.c=.o)


FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/
LIBFT_HEADER = ./libft/includes
HEADER = ./includes/

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): obj $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(HEADER) -L $(LIBFT) -lft
	@printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable $(NAME) ready !\x1B[37m\n"

obj:
	@make -C $(LIBFT)
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"

%.o: %.c
	gcc $(FLAGS) -I $(LIBFT) -I $(HEADER) -I $(LIBFT_HEADER) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)
	@printf "$(RED)[-]$(NC)Obj files deleted\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@printf "$(RED)[-]$(NC)Executable $(NAME) deleted\n"

re: fclean all

.PHONY: all clean fclean re
