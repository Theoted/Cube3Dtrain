# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:51:24 by tdeville          #+#    #+#              #
#    Updated: 2022/10/07 10:41:46 by theodeville      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_strlen.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCS_B =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}


CC		= gcc
CFLAGS	= 

all: ${NAME}

%.o : %.c	libft.h	Makefile
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_B}
	ar rcs ${NAME} ${OBJS} ${OBJS_B}


clean:
	rm -f ${OBJS} ${OBJS_B}

fclean:	clean
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
