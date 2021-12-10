# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:26:23 by khee-seo          #+#    #+#              #
#    Updated: 2021/12/10 15:19:10 by khee-seo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
THREAD= -lpthread
SRCS= main.c \
	  init.c \
	  running.c \
	  utils.c

OBJS= $(SRCS:.c=.o)

NAME= philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) $(SRCS) -o $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
