# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/12/23 20:06:35 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Folders
SRCDIR		= ./
OBJDIR		= ./
HDRDIR		= ./

#Sources\
FTISDIR		= is\
FTMEMDIR	= mem\
FTPUTDIR	= put\
FTTODIR		= to\
FTSTRDIR	= str\
FTLSTDIR	= lst\
FTMATHDIR	= math\
FTPRINTDIR	= print

# Files
SRCS		= ${shell find ${SRCDIR} ! -name "*_bonus.c" -name '*.c'}
SRCS_BONUS	= ${shell find ${SRCDIR} -name '*_bonus.c' -name '*.c'}
OBJS		= ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
OBJS_BONUS	= ${SRCS_BONUS:${SRCDIR}%.c=${OBJDIR}%.o}
NAME		= libft.a
# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Usefuls commands
RM			= rm -f
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

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@ranlib ${NAME}
			@echo "${GREEN}Libft compiled!${DEFCOLOR}"

${OBJDIR}%.o : ${SRCDIR}%.c
			@echo "${YELLOW}Compiling: $< ${DEFCOLOR}"
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

all:		${NAME}

# Compiling bonuses
bonus:		${OBJS} ${OBJS_BONUS}
			@${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

# Norminette
norm:
			@echo "${GREEN}"
			@norminette -R CheckForbiddenSourceHeader
			@echo "${DEFCOLOR}"

# Testing library
test:
			@echo "${CYAN}Compiling library without bonuses..."
			@echo "...${DEFCOLOR}"
			@make
			@echo "${CYAN}Compiling library with bonuses..."
			@echo "...${DEFCOLOR}"
			@make bonus
			@echo "${CYAN}Basic cleaning..."
			@echo "...${DEFCOLOR}"
			@make clean
			@echo "${CYAN}Deep cleaning..."
			@echo "...${DEFCOLOR}"
			@make fclean
			@echo "${CYAN}Compiling library with bonuses again..."
			@echo "...${DEFCOLOR}"
			@make bonus
			@echo "${CYAN}Recompiling library again..."
			@echo "...${DEFCOLOR}"
			@make re
			@echo "${CYAN}Deep cleaning..."
			@echo "...${DEFCOLOR}"
			@make fclean
			@echo "${RED}Running francinette...${DEFCOLOR}"
			@echo ""
			@/Users/$(USER)/francinette/tester.sh
			@echo "...${DEFCOLOR}"
			@echo "${RED}Running francinette with strict option...${DEFCOLOR}"
			@echo ""
			@/Users/$(USER)/francinette/tester.sh --strict
			@echo "...${DEFCOLOR}"
			@echo "${GREEN}Testing Done congrats !${DEFCOLOR}"

# Cleaning
clean:
			@${RM} ${shell find ${SRCDIR} -name '*.o'}
			@echo "${BLUE}Library objects files cleaned!${DEFCOLOR}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${CYAN}Library executable files cleaned!${DEFCOLOR}"

# Recompiling
re:			fclean all
			@echo "${GREEN}Cleaned and rebuilt the library correctly !${DEFCOLOR}"

.PHONY:		all clean fclean re norm
