# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 15:42:37 by akhourba          #+#    #+#              #
#    Updated: 2019/04/11 20:29:14 by akhourba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = akhourba.filler
SRC = *.c
OBJ = *.o

all: $(NAME)

$(NAME):
		@make -C libft
		@gcc -c -Wall -Wextra -Werror $(SRC) -I includes -I libft/includes
		@gcc  -Wall -Wextra -Werror libft/libft.a $(OBJ) -I includes -I libft/includes -o $(NAME)
clean:
		@make clean -C libft
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C libft
		@rm -rf $(NAME)
re: fclean all
