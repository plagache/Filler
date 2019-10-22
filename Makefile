NAME= libftprintf.a

SRC = ft_printf.c\
	  pwidth.c\
	  pflags.c\
	  pwidth.c\
	  plenmodifier.c\
	  pprecision.c\
	  func_selector.c\
	  global_tools.c\
	  int.c\
	  int_tools.c\
	  unsigned.c\
	  unsigned_tools.c\
	  octal.c\
	  octal_tools.c\
	  percent.c\
	  char.c\
	  hexa.c\
	  hexa_tools.c\
	  hexa_upper.c\
	  string.c\
	  float.c\
	  float_tools.c\
	  double.c\
	  double_tools.c\
	  ldouble.c\
	  ldouble_tools.c\
	  address_tools.c\
	  address.c\
	  special.c\
	  special_tools.c\

CFLAGS= -Wall -Werror -Wextra

HEADERPATH= includes

LHEADERPATH= Libft/includes

OBJDIR= obj

OBJ= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C Libft/ --no-print-directory
		@ar -rs Libft/libft.a $(OBJ) 
		@cp Libft/libft.a .
		@mv libft.a libftprintf.a
		@echo "printf lib builded"

obj/%.o : srcs/%.c
	@mkdir -p $(OBJDIR)
	@gcc $(CFLAGS) -I $(HEADERPATH) -I $(LHEADERPATH) -o $@ -c $<

clean:
		@rm -rf $(OBJDIR)
		@make clean -C Libft/ --no-print-directory
		@echo "printf objects cleaned"

fclean:
		@rm -rf $(OBJDIR)
		@rm -rf $(NAME)
		@make fclean -C Libft/ --no-print-directory
		@echo "printf lib cleaned"

re: fclean all

.PHONY: clean all fclean re
