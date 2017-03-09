##
## Makefile for Makefile in /home/naji_m/rendu/PSU_2015_malloc/v2
## 
## Made by naji moncef
## Login   <naji_m@epitech.net>
## 
## Started on  Wed Feb 10 23:10:54 2016 naji moncef
## Last update Sat Feb 13 02:56:00 2016 Avel Docquin
##

CC	= gcc

RM	= rm -f

NAME	= libmy_malloc.so

SRC	= malloc.c \
	 show_alloc_mem.c \
	 free.c \
	 realloc.c \
	 block.c 

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra

$(NAME):$(OBJ) 
	$(CC) -c $(CFLAGS) -fpic $(SRC) && $(CC) -shared -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
