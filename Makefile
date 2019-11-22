NAME= plagache.filler

SRC=	main.c\
		parsing.c\
		tools.c\
		check_pos.c\
		check_place.c\

SRCS = $(addprefix srcs/,$(SRC))

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

LIBDIR= libft

OBJDIR= out

LIBA= $(LIBDIR)/libft.a

CFLAGS= -Wall -Werror -Wextra

HEADER = includes/filler.h

CC = clang

all: $(NAME)

$(NAME): $(OBJ)
	make -s -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA)
	echo "filler build complete"

out/%.o : srcs/%.c
	mkdir -p out
	$(CC) -I $(LIBDIR) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) -rf $(OBJDIR)
		echo "filler objects cleaned"
		make clean -C $(LIBDIR)

fclean:
		make fclean -s -C $(LIBDIR)
		$(RM) -f $(NAME)
		$(RM) -rf $(OBJDIR)
		echo "filler objects cleaned"
		echo "filler project cleaned"

re: fclean all

.PHONY: all clean fcleanre
.SILENT: all clean fclean re
