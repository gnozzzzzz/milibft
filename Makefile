NAME = a.exe
FILES = libftprintf
SRC_DIR = carpetac
OBJ_DIR = carpetao
CFILES = $(addsuffix .c,$(FILES))
OFILES = $(addsuffix .o,$(FILES))
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: a.exe

a.exe: .\libft\libft.a
	gcc .\libftprintf.c -L.\libft -lft

.\libft\libft.a:
	$(MAKE) -C libft all
	$(MAKE) clean
	
clean:
	$(MAKE) -C libft clean

.PHONY:  all clean fclean re

#gcc -c .\libftprintf.c .\ftprintffuncs.c
#ar rcs libftprintf.a .\ftprintffuncs.o .\libftprintf.o
#gcc unmain.c -L. -lftprintf -Ilibft -Llibft -lft