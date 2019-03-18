NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  src/core/main.c src/core/parser.c src/core/printer.c src/core/sort.c \
		src/entities/entry.c src/entities/folder.c \
		src/utils/ft_memcpy.c src/utils/ft_strcpy.c src/utils/ft_strjoin.c \
		src/utils/ft_strlen.c src/utils/ft_strcat.c src/utils/ft_strcmp.c
OBJSDIR = ./obj
SRCDIR = ./src
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all: $(NAME)
	
clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJS): $(OBJSDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) -I ./includes -o $@ $<	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)