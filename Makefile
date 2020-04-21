# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plagache <plagache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 01:45:58 by plagache          #+#    #+#              #
#    Updated: 2020/04/21 16:26:25 by plagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= plagache.filler

SRC=	main.c\
		get_info.c\
		read.c\
		tools.c\
		map.c\
		heat_map.c\
		score.c\
		offset.c\

SRCS = $(addprefix srcs/,$(SRC))

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

LIBDIR= libft

OBJDIR= out

LIBA= $(LIBDIR)/libft.a

CFLAGS= -Wall -Werror -Wextra
CFLAGS+= -g -fsanitize=address -fno-omit-frame-pointer

HEADER = includes

LIB_HEADER = $(LIBDIR)/includes

CC = clang

BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"
PURPLE = "\\033[35m"

LNECLR = "\\33[2K\\r"

all: $(NAME)

$(NAME): $(OBJ)
	make -s -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA)
	printf "$(LNECLR)$(GREEN)filler build complete$(WHITE)\n"

out/%.o: srcs/%.c $(HEADER) $(LIB_HEADER)
	mkdir -p out
	printf "$(LNECLR)$(NAME): $<"
	$(CC) -I $(HEADER) -I $(LIB_HEADER) -I $(LIBDIR) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) -rf $(OBJDIR)
		printf "$(LNECLR)$(PURPLE)filler objects cleaned$(WHITE)\n"
		make clean -C $(LIBDIR)

fclean:
		make fclean -s -C $(LIBDIR)
		$(RM) -f $(NAME)
		$(RM) -rf $(OBJDIR)
		printf "$(LNECLR)$(PURPLE)filler objects cleaned$(WHITE)\n"
		printf "$(LNECLR)$(RED)filler project cleaned$(WHITE)\n"

re: fclean all
	printf "$(BLUE)re filler done$(WHITE)\n"

.PHONY: all clean fclean re
.SILENT: all clean fclean re out/%.o $(NAME) $(OBJ)
