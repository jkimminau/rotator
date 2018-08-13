NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_strncpy.c\
       ft_strcmp.c\
        ft_memdel.c\
        ft_isprint.c\
        ft_toupper.c\
        ft_strncmp.c\
        ft_strclr.c\
        ft_memcpy.c\
        ft_islower.c\
        ft_tolower.c\
        ft_strncat.c\
        ft_strchr.c\
        ft_memcmp.c\
        ft_isdigit.c\
        ft_strtrim.c\
        ft_strmapi.c\
        ft_strcat.c\
        ft_memchr.c\
        ft_isascii.c\
        ft_strsub.c\
        ft_strmap.c\
        ft_putstr_fd.c\
        ft_memccpy.c\
        ft_isalpha.c\
        ft_strstr.c\
        ft_strlen.c\
        ft_putstr.c\
        ft_memalloc.c\
        ft_isalnum.c\
        ft_strsplit.c\
        ft_strlcat.c\
        ft_putnbr_fd.c\
        ft_lstnew.c\
        ft_bzero.c\
        ft_strjoin.c\
        ft_putnbr.c\
        ft_lstmap.c\
        ft_atoi.c\
        ft_strrchr.c\
        ft_striteri.c\
        ft_putendl_fd.c\
        ft_lstiter.c\
        ft_striter.c\
        ft_putendl.c\
        ft_lstdelone.c\
        ft_strnstr.c\
        ft_strequ.c\
        ft_putchar_fd.c\
        ft_lstdel.c\
        ft_strnew.c\
        ft_strdup.c\
        ft_putchar.c\
        ft_lstadd.c\
        ft_strnequ.c\
        ft_strdel.c\
        ft_memset.c\
        ft_itoa.c\
        ft_strndup.c\
        ft_strcpy.c\
        ft_memmove.c\
        ft_isupper.c\
		ft_gnl.c\

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = libft.h

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -I$(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS) *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
