##
## Makefile for broggi_t in /home/broggi_t/rendu/ex_4
## 
## Made by broggi_t
## Login   <broggi_t@epitech.eu>
## 
## Started on  Thu May 22 12:02:21 2014 broggi_t
## Last update Thu May 22 12:36:44 2014 broggi_t
##

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

NAME	= sopipa

CFLAGS	+= -W -Wall -Wextra

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	cc -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
