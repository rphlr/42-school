# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/20 14:25:31 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
SRCDIR		= srcs
OBJDIR		= ../objs
HDRDIR		= ../includes

# Files
SRCS		= ${shell find ${SRCDIR} -name '*.c'}
OBJS		= ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
NAME		= mylib.a

# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Usefuls commands
RM			= rm -rf
MV			= mv
MKDIR		= mkdir

# Archive
AR			= ar rcs

# Colors
DEFCOLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

#Sources
FTISDIR		= is
FTMEMDIR	= mem
FTPUTDIR	= put
FTTODIR		= to
FTSTRDIR	= str
FTLSTDIR	= lst
FTMATHDIR	= math
FTPRINTDIR	= print

# First rule
all:		${NAME}

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@ranlib ${NAME}
			@echo "${GREEN}Libft compiled!${DEFCOLOR}"

${OBJDIR}%.o : ${SRCDIR}%.c
			@mkdir -p ${OBJDIR}
			@mkdir -p ${OBJDIR}/${FTISDIR}
			@mkdir -p ${OBJDIR}/${FTMEMDIR}
			@mkdir -p ${OBJDIR}/${FTPUTDIR}
			@mkdir -p ${OBJDIR}/${FTTODIR}
			@mkdir -p ${OBJDIR}/${FTSTRDIR}
			@mkdir -p ${OBJDIR}/${FTLSTDIR}
			@mkdir -p ${OBJDIR}/${FTMATHDIR}
			@mkdir -p ${OBJDIR}/${FTPRINTDIR}
			@echo "${YELLOW}Compiling: $< ${DEFCOLOR}"
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Norminette
norm:
			@norminette -R CheckForbiddenSourceHeader

# Cleaning
clean:
			@${RM} ${OBJDIR}
			@echo "${BLUE}Library objects files cleaned!${DEFCOLOR}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${CYAN}Library executable files cleaned!${DEFCOLOR}"

re:			fclean all
			@echo "${GREEN}Cleaned and rebuilt the library correctly !${DEFCOLOR}"

.PHONY:		all clean fclean re norm
