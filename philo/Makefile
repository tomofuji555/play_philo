# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:11:14 by tofujiwa          #+#    #+#              #
#    Updated: 2024/06/08 17:32:41 by tofujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
#-fsanitize=thread
CFLAGS =  -Wall -Wextra -Werror
PFLAGS = -lpthread
SRCS = main.c init_share.c init_philo.c init_fork.c init_exec.c utils.c \
		create_thread.c free.c run.c run_utils.c check_dead.c libft.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
