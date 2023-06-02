# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:20:40 by rrouille          #+#    #+#              #
#    Updated: 2023/02/18 14:29:03 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
##
#Arguments

NAME	= pipex

###############
##

# Folders
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes/

# COLORS
# Text styles
BOLD		= \033[1m
DIM			= \033[2m
UNDERLINE	= \033[4m
REVERSE		= \033[7m
# Colors
GRAY		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
# Background colors
BG_GREY		= \033[40m
BG_RED		= \033[41m
BG_GREEN	= \033[42m
BG_YELLOW	= \033[43m
BG_BLUE		= \033[44m
BG_PURPLE	= \033[45m
BG_CYAN		= \033[46m
BG_WHITE	= \033[47m
# Formating
HIDE_CURSOR	= \033[?25l
SHOW_CURSOR	= \033[?25h
MOVE_UP		= \033[1A
ERASE		= \033[K
# End
RESET		= \033[0m

# Sources
SRCS	= ${shell find ${SRCDIR} -name '*.c' ! -name '*/*.c'}

OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCS:%.c=%.o))
CFLAGS	= -Werror -Wall -Wextra -g
CC		= gcc
RM		= rm -rf
MAKE 	= make
MKDIR	= mkdir

# Progression bar
START			=		echo "${YELLOW}\nStart of program compilation\n${RESET}"
END_COMP		=		echo "${GREEN}\nEnd of compilation${RESET}"
S_OBJS			=		echo "${RED}Suppression des objets\n${RESET}"
S_NAME			=		echo "${RED}Suppression du programme${RESET}"
CHARG_LINE		=		echo "${BG_GREEN} ${RESET}\c"
BS_N			=		echo "\n"

# First rule
all:		draw ${NAME}

draw:
	@echo "${CYAN}                                                             "
	@echo "██████╗ ██╗██████╗ ███████╗██╗  ██╗    ██╗  ██╗██████╗       "
	@echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ██║  ██║╚════██╗      "
	@echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝     ███████║ █████╔╝      "
	@echo "██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ╚════██║██╔═══╝       "
	@echo "██║     ██║██║     ███████╗██╔╝ ██╗         ██║███████╗      "
	@echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝         ╚═╝╚══════╝      "
	@echo "                                                             "
	@echo "██████╗ ██████╗  ██████╗ ██╗   ██╗██╗██╗     ██╗     ███████╗"
	@echo "██╔══██╗██╔══██╗██╔═══██╗██║   ██║██║██║     ██║     ██╔════╝"
	@echo "██████╔╝██████╔╝██║   ██║██║   ██║██║██║     ██║     █████╗  "
	@echo "██╔══██╗██╔══██╗██║   ██║██║   ██║██║██║     ██║     ██╔══╝  "
	@echo "██║  ██║██║  ██║╚██████╔╝╚██████╔╝██║███████╗███████╗███████╗"
	@echo "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝╚══════╝╚══════╝╚══════╝"
	@echo "                                                             ${RESET}"


${OBJDIR}/%.o : ${SRCDIR}/%.c lib
			@$(CC) -I ${HDRDIR} -c $< -o $@

lib :
			@if [ -d mylib ]; then \
				echo "${GREEN}Program already exists, updating it.${RESET}"; \
			else \
				git clone https://github.com/rphlr/mylib --quiet; \
				make -C mylib; \
			fi
			@${MKDIR} -p ${OBJDIR}
			@${START}

$(NAME): $(OBJS)
			@for i in $(OBJS) mylib/objs/*/*.o; do \
			${CHARG_LINE}; \
			done; \
			echo ""; \
			$(CC) $(CFLAGS) $(OBJS) mylib/objs/*/*.o -o $(NAME)
			@${END_COMP}
			@echo "\n${GREEN}${BOLD}${UNDERLINE}PROGRAM READY !${RESET}"

# Git repo maker
git: fclean
			@git add *
			@echo "${CYAN}Added files to git !"
			@git commit -m "Auto-commit"
			@echo "${BLUE}Commited !"
			@git push
			@echo "${GREEN}All changed are now on github!${RESET}"

clean:
			@$(S_OBJS)
			@$(RM) $(OBJDIR) mylib outfile output output.txt

fclean: clean
			@$(S_NAME)
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re