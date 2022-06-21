# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 15:05:25 by sgmira            #+#    #+#              #
#    Updated: 2022/06/18 23:22:15 by sgmira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS	= check_death.c				\
		philosophers.c				\
		philo_utils1.c				\
		ft_split.c					\
		arg_check.c					\
		philo_utils2.c				\
		philo_utils3.c				\
		philo_utils4.c				\

OBJS	= $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:  clean
	rm -rf $(NAME)

re: fclean all