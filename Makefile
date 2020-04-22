CC	=	gcc

CFLAGS	=	-W -Wall -Werror -I./include/

RM	=	rm -rf

LIBNAME =	libmy_malloc.so

SRCS	=	my_malloc.c	\
		my_calloc.c	\
		my_realloc.c	\
		my_free.c

OBJS	=	$(SRCS:.c=.o)


all:		$(LIBNAME)

$(LIBNAME):
		$(CC) $(CFLAGS) -c -fpic $(SRCS)
		$(CC) $(CFLAGS) -shared -o $(LIBNAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(LIBNAME)

re:		fclean all

.PHONY:		all clean fclean re
