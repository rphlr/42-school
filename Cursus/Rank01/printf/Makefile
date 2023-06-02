# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:27:55 by rrouille          #+#    #+#              #
#    Updated: 2022/11/28 16:30:22 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
LIBDIR		= lib
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes
BONUSDIR	= ${SRCDIR}/bonus

# Files
SRCS		= ${shell find ${SRCDIR} ! -name "exec.c" -name '*.c'}
OBJS		= ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
NAME		= libftprintf.a
TESTER		= exec

# Compilation
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Usefuls commands
RM			= rm -rf
MV			= mv
MKDIR		= mkdir -p

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

all:		${NAME}

# First rule
${NAME}:	${OBJS}
			@cp ${LIBDIR}/mylib.a .
			@mv mylib.a ${NAME}
			@${AR} ${NAME} ${OBJS}
			@echo "${GREEN}ft_printf compiled!${DEFCOLOR}"

# Compilation rule
${OBJDIR}/%.o: ${SRCDIR}/%.c
			@${MKDIR} ${BONUSDIR}
			@make -C ${LIBDIR}
			@${MKDIR} -p ${OBJDIR}
			@echo "${YELLOW}Compiling: $< ${DEFCOLOR}"
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Norminette
norm:
			@norminette -R CheckForbiddenSourceHeader

basics-tests:
			@echo "${BLUE}"
			@${CC} ${CFLAGS} ${SRCDIR}/*.c ${LIBDIR}/${SRCDIR}/*/*.c -I ${HDRDIR} -o ${TESTER}
			@echo "First test :"
			@./${TESTER} 0123456789 abcdefghijklmnopqrstuvwxyz
			@echo ""
			@echo "------------"
			@echo "Second test :"
			@./${TESTER} -2147483648 "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"
			@echo ""
			@echo "------------"
			@echo "Third test :"
			@./${TESTER} 2147483647 "@!$#%^&*()_+<> ?:\\\"{}|,./;[]'"
			@echo ""
			@echo "------------"
			@echo "Fourth test :"
			@./${TESTER} 23846324087324 "\t\n\v\f\r\0"
			@echo "${DEFCOLOR}"
			@echo "${YELLOW}Testing done.${DEFCOLOR}"
			@echo ""

test:
			@echo "${CYAN}Running the basic tests for the printf project..."
			@echo "For more test try \"make moretest\" or \"make mt\"..."
			@echo "...${DEFCOLOR}"
			@mv ${SRCDIR}/${TESTER}.test ${SRCDIR}/${TESTER}.c
			@make basics-tests
			@echo "${CYAN}Cleaning testing files...${DEFCOLOR}"
			@${RM} ${TESTER}
			@mv ${SRCDIR}/${TESTER}.c ${SRCDIR}/${TESTER}.test
			@echo "${GREEN}Testing files cleaned !${DEFCOLOR}"

moretest:
			@echo "${CYAN}Running the tests for the printf project..."
			@echo "...${DEFCOLOR}"
			@make
			@mv ${SRCDIR}/${TESTER}.test ${SRCDIR}/${TESTER}.c
			@make basics-tests
			@echo "${RED}Running francinette...${DEFCOLOR}"
			@echo ""
			@/Users/$(USER)/francinette/tester.sh
			@echo "${YELLOW}Testing done, well done.${DEFCOLOR}"
			@echo ""
			@echo "${CYAN}Cleaning testing files...${DEFCOLOR}"
			@${RM} ${TESTER}
			@make fclean
			@mv ${SRCDIR}/${TESTER}.c ${SRCDIR}/${TESTER}.test
			@echo "${GREEN}Testing files cleaned !${DEFCOLOR}"

mt:			moretest

# Cleaning
clean:
			@${RM} -rf ${OBJDIR}
			@make clean -C ${LIBDIR}
			@echo "${BLUE}ft_printf object files cleaned!${DEFCOLOR}"

fclean:		clean
			@${RM} -f ${NAME}
			@${RM} -f ${LIBDIR}/mylib.a
			@echo "${CYAN}printf executable files cleaned!"
			@echo "${CYAN}Library executable files cleaned !${DEFCOLOR}"

re:			fclean all
			@echo "${GREEN}Cleaned and rebuilt everything !${DEFCOLOR}"

.PHONY:		all clean fclean re norm
