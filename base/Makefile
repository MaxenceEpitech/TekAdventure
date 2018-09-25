##
## Makefile for wolf3D in /home/JB.Melet/Projets/Graphical/wolf3d
## 
## Made by JeanBaptiste Melet
## Login   <JB.Melet@epitech.net>
## 
## Started on  Mon May  1 16:54:51 2017 JeanBaptiste Melet
## Last update Wed Aug 30 23:38:02 2017 jean-baptiste
##

NAME	=	tekadventure

RM	=	rm -f

CC	=	gcc

CFLAGS	+=	-O3 -Wall -Wextra -I ./include

LIB	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm

FULL	=	-lc_graph_prog_full -lm

SRC	=	src/main.c			\
		src/menu.c			\
		src/choices_menu.c		\
		src/my_put_pixel.c		\
		src/my_draw_line.c		\
		src/load_materials.c		\
		src/begin_game.c		\
		src/close_free.c		\
		src/base/bed.c			\
		src/base/computer.c		\
		src/base/console.c		\
		src/base/dashboard.c		\
		src/base/decontamination.c	\
		src/base/interactions.c		\
		src/base/load_base.c		\
		src/base/move_around.c		\
		src/base/gif_base.c		\
		src/base/gif_utils.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

JB:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(FULL)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean re
