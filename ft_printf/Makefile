NAME	=	libftprintf.a

INC		=	ft_printf.h

SRC		=	ft_printf.c\
			ft_printf_function.c\
			ft_printf_base.c

OBJ_DIR	=	.objs

FLAGS	=	-Wall -Wextra -Werror -I .

OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all	:	$(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o : %.c $(INC)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) -rf $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re