
#	Serv ressources.
SRCSSERV	:=	main.c\
				utils.c\
				buffer_manage.c

SRCSSERV_D	:=	srcs/server/

OBJSSERV		=	$(SRCSSERV:%.c=$(OBJSSERV_D)%.o)

OBJSSERV_D		:=	.objs/serv


#	Client ressources.
SRCSCLIENT	:=	main.c\
				utils.c

SRCSCLIENT_D	:=	srcs/client/

OBJSCLIENT		=	$(SRCSCLIENT:%.c=$(OBJSCLIENT_D)%.o)

OBJSCLIENT_D		:=	.objs/client

#	ALl
HEAD		:=	minitalk.h

HEAD_D		:=	./incs/

OBJS_D		:= .objs/

LIB_D		:= ./ft_printf

HEAD_A		:=	$(addprefix $(HEAD_D), $(HEAD))

NAMESERV	:=	server

NAMECLIENT		:= client

LIB_A		:=	ft_printf/libftprintf.a


########################################################################################################################
#                                                        FLAGS                                                         #
########################################################################################################################
CC		:=	cc

RM		:=	rm -rf
#-
CFLAGS	:=	-Wall -Wextra -Werror -I$(HEAD_D) -I$(LIB_D)

all			:	$(NAMESERV) $(NAMECLIENT)


$(NAMESERV)		:	$(OBJSSERV_D) $(OBJSSERV) $(LIB_A)
				$(CC) $(CFLAGS) -o $(NAMESERV) $(OBJSSERV) -L./ft_printf -lftprintf


$(LIB_A)	:
				make -C ft_printf/

$(OBJSSERV)		:	$(OBJSSERV_D)%.o: $(SRCSSERV_D)%.c $(HEAD_A)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJSSERV_D)	:
				mkdir -p $(OBJSSERV_D)
##--------------------------------------------------------------------------------#
$(NAMECLIENT)		:	$(OBJSCLIENT_D) $(OBJSCLIENT) $(LIB_A)
				$(CC) $(CFLAGS) -o $(NAMECLIENT) $(OBJSCLIENT) -L./ft_printf -lftprintf

$(OBJSCLIENT)		:	$(OBJSCLIENT_D)%.o: $(SRCSCLIENT_D)%.c $(HEAD_A)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJSCLIENT_D)	:
				mkdir -p $(OBJSCLIENT_D)

clean		:
				$(RM) $(OBJSSERV) $(OBJSCLIENT)
				$(RM) $(OBJSSERV_D) $(OBJSCLIENT_D) $(OBJS_D)
				make -C ft_printf/ clean


fclean		:	clean
				$(RM) $(NAMESERV) $(NAMECLIENT)
				make -C ft_printf/ fclean

re			:	fclean all

.PHONY		:	all clean fclean re