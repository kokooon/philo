# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 11:44:11 by gmarzull          #+#    #+#              #
#    Updated: 2022/10/25 14:45:15 by gmarzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo

ALL		= 	main init check functions philo
SRC		= 	$(addsuffix .c, $(ALL))

OBJS	= 	${SRC:.c=.o}

HEADER	= 	philo.h

CC		= 	gcc

FLAGS	= 	-Wall -Wextra -Werror -Werror -Wextra -Wall
LINKER	=	 -fsanitize=address

all:		$(NAME)

.c.o:	
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			$(CC) $(FLAGS) -lpthread -o $(NAME) $(OBJS)

clean:	
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re