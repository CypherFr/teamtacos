##
## EPITECH PROJECT, 2022
## SYN calendar
## File description:
## Makefile
##

CC			=	gcc

NAME		=	calendar

CFLAGS		=	-I include

LDFLAGS		=	 -L librarys

SRCS		=	src/main.c 		\
				src/employee.c 	\

RM			=	rm -f

OBJ			=	$(SRCS:.c=.o)

ZIP 		=	tar

ZIPFLAGS 	=	-cvvf

UNZIP 		=	tar

UNZIPFLAGS 	=	-xvf

BCK_DIR 	=	backup

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

archive:
	$(ZIP) $(ZIPFLAGS) $(BCK_DIR)/archive $(SRCS)

revert:
	$(UNZIP) $(UNZIPFLAGS) $(BCK_DIR)/archive

num:
	rm -rf $(NAME).zip

delete:
	rm -rf $(BCK_DIR)/archive
