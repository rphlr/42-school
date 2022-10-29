# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/10/28 17:27:55 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_strchr.c ft_isascii.c ft_strrchr.c \
			ft_isprint.c ft_strncmp.c ft_strlen.c ft_memchr.c ft_memset.c ft_memcmp.c ft_memcpy.c ft_strnstr.c ft_memmove.c \
			ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bzero.c
SRCS_BONUS	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
			ft_lstnew_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c
#SRCS_MINE	= ft_memalloc.c
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
#OBJS_MINE	= ${SRCS_MINE:.c=.o}
NAME		= libft.a
HEADER		= libft.h
CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= @rm -f

${NAME}:	${OBJS} ${HEADER}
			@ar rcs ${NAME} ${OBJS}

all:		 ${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

#mine:		${OBJS} ${OBJS_BONUS} ${OBJS_MINE}
#			ar rcs ${NAME} ${OBJS_BONUS} ${OBJS_MINE}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re .c.o