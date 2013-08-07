NAME=		fdf

RM=		@rm -f

CC=		gcc

SRC=		main.c			\
		get_file.c		\
		file_get_contents.c	\
		put_pixel.c		\
		free_map.c		\
		tools/my_getnbr_base.c	\
		tools/my_pow.c		\
		tools/my_strlen.c	\
		tools/my_strncpy.c

OBJ=		$(SRC:.c=.o)

CFLAGS+=	-W -Wextra -Wall -pedantic -ansi -g

LDFLAGS+=	-lmlx -lX11 -lXext

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
