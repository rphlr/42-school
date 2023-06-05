# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2023/02/06 19:24:25 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
##
#Arguments

NAME	= fractol

###############
##

# Folders
SRCDIR		= srcs
OBJDIR		= objs
HDRDIR		= includes/

# Colors
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
ENDCOLOR	= \033[0m
BG_G		= \033[42m

#Sources

SRCS	= ${shell find ${SRCDIR} -name '*.c' ! -name '*/*.c'}

OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCS:%.c=%.o))
# OBJS	= ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o} # $(filter-out $(SRCDIR)%,$(SRCS:%.c=$(OBJDIR)%.o))
CFLAGS	= -Werror -Wall -Wextra -g
CC		= gcc
RM		= rm -rf
MAKE 	= make
MKDIR	= mkdir

# Progression bar
START			=		echo "${YELLOW}Start of program compilation\n${ENDCOLOR}"
END_COMP		=		echo "${GREEN}\nEnd of compilation${ENDCOLOR}"
S_OBJS			=		echo "${RED}Suppression des objets\n${ENDCOLOR}"
S_NAME			=		echo "${RED}Suppression du programme${ENDCOLOR}"
CHARG_LINE		=		echo "${BG_G} ${ENDCOLOR}\c"
BS_N			=		echo "\n"

# $(info SRCDIR = $(SRCDIR))
# $(info OBJDIR = $(OBJDIR))
# $(info SRCS = $(SRCS))
# $(info OBJS = $(OBJS))

# Progress bar
PROGRESS_BAR_LENGTH = 50

# First rule
all:		${NAME}

progress-bar:
	@echo "Start of program compilation\n"
	@for i in `seq 1 $(PROGRESS_BAR_LENGTH)`; do \
		printf "\r${BG_G} ${ENDCOLOR}"; \
		for j in `seq 1 $$i`; do \
			printf "${BG_G} ${ENDCOLOR}"; \
		done; \
		for j in `seq $$i $(PROGRESS_BAR_LENGTH)`; do \
			printf " "; \
		done; \
		printf " %.0f%%" $$((100 * $$i / $(PROGRESS_BAR_LENGTH))); \
		sleep 0.1; \
	done; \
	printf "\n\nEnd of compilation\n\n";

${OBJDIR}/%.o : ${SRCDIR}/%.c lib
#			@cp mlx/mlx.h ${HDRDIR}
			@$(CC) $(CFLAGS) -I ${HDRDIR} -c $< -o $@

lib :
			@tar -xf minilibx_mms_20200219_beta.tgz
			@mv -f minilibx_mms_20200219 mlx
			@git clone https://github.com/rphlr/mylib --quiet
			@make -C mylib
#			mv -f mylib/$(SRCDIR)/* $(SRCDIR)
#			@cp -f mylib/$(HDRDIR)* $(HDRDIR)
#			@mv mylib/mylib.a .
			@echo "\n"
			@${MKDIR} -p ${OBJDIR}
#			mv mylib/${OBJDIR}/* ${OBJDIR}
#			${RM} mylib

$(NAME): $(OBJS)
			@$(MAKE) -s -C mlx > /dev/null 2>&1
## -C change directory
			@cp mlx/libmlx.dylib .
## copy libmlx dans le fichier ou l on est
#			@$(CC) $(CFLAGS) $(OBJS) mylib/objs/*/*.o -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@for i in $(OBJS) mylib/objs/*/*.o; do \
			${CHARG_LINE}; \
			done; \
			echo ""; \
			$(CC) $(CFLAGS) $(OBJS) mylib/objs/*/*.o -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#			@pv $(OBJS) mylib/objs/*/*.o | $(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@${END_COMP}

run: re
			@./fractol

# Git repo maker
git: fclean
			@git add *
			@echo "${CYAN}Added files to git !"
			@git commit -m "Auto-commit"
			@echo "${BLUE}Commited !"
			@git push
			@echo "${GREEN}All changed are now on github!${ENDCOLOR}"

clean:
			@$(S_OBJS)
			@$(RM) $(OBJDIR) mlx/ $(SRCDIR)/*/ $(HDRDIR)mylib.h libmlx.dylib mylib mylib.a ${HDRDIR}mlx.h

fclean: clean
			@$(S_NAME)
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

