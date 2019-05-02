# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 15:42:37 by akhourba          #+#    #+#              #
#    Updated: 2019/04/30 16:01:33 by akhourba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu
SRC = *.c src/*.c
OBJ = *.o

INC = -I includes -I libft/includes
INC +=  -L lib/lib -l SDL2-2.0.0 -l SDL2_ttf
FLGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
		@make -C libft
		@gcc -c $(FLGS) $(SRC) -I includes -I libft/includes
		@gcc $(FLGS) $(OBJ) libft/libft.a  -o $(NAME) $(INC)
clean:
		@rm -rf $(OBJ)
		@make clean -C libft 
fclean: clean
		@make fclean -C libft 
		@rm -rf $(NAME)
re: fclean all
