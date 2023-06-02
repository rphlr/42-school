# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:16:34 by rrouille          #+#    #+#              #
#    Updated: 2023/05/23 16:41:21 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME			= so_long

# Arguments passed to the executable
ARGS			= $(filter-out $@,$(MAKECMDGOALS))
PRINT_SCREEN	= YES

# Directories
SRCSDIR			= srcs
OBJSDIR			= objs
HDRDIR			= includes/
PLAYERDIR		= player
ENEMYDIR		= enemy
MAPDIR			= map
UTILSDIR		= utils

# Colors for the terminal
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ENDCOLOR		= \033[0m

# Background colors
BG_G			= \033[42m
BG_R			= \033[41m
BG_Y			= \033[43m
BG_B			= \033[44m
BG_M			= \033[45m
BG_C			= \033[46m
BG_W			= \033[47m

# Text formatting
BOLD			= \033[1m
UNDERLINE		= \033[4m
ITALIC			= \033[3m
INVERTED		= \033[7m

# Clear screen
CLEAR			= \033c

# Sources
SRCS			= $(shell find $(SRCSDIR) -type f -name '*.c')
OBJS			= ${patsubst ${SRCSDIR}%,${OBJSDIR}%,${SRCS:%.c=%.o}}
CFLAGS			= -Werror -Wall -Wextra -g
CC				= gcc
RM				= rm -rf
MAKE			= make
MKDIR			= mkdir -p

# Operating System
OS				:= $(shell uname)

# Progress bar messages
START			= echo "${YELLOW}\n🚀 Start of program compilation 🚀${ENDCOLOR}"
END_COMP		= echo "${GREEN}\n\n✅ Compilation completed successfully! ✅${ENDCOLOR}"
S_OBJS			= echo "${RED}🧹 Cleaning objects... 🧹${ENDCOLOR}"
S_NAME			= echo "${RED}🧹 Cleaning program... 🧹${ENDCOLOR}"
CHARG_LINE		= echo "${BG_G} ${ENDCOLOR}\c" && sleep 0.05 
BS_N			= echo "\n"

# First rule
all:	 draw_begining ${NAME} draw_ready

# Build rule for object files
${OBJSDIR}/%.o : ${SRCSDIR}/%.c lib
			@$(MKDIR) ${OBJSDIR}
			@$(MKDIR) ${OBJSDIR}/${PLAYERDIR}
			@$(MKDIR) ${OBJSDIR}/${ENEMYDIR}
			@$(MKDIR) ${OBJSDIR}/${MAPDIR}
			@$(MKDIR) ${OBJSDIR}/${UTILSDIR}
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Linking rule
${NAME}: ${OBJS}
			@${CHARG_LINE}
			@for i in ${OBJS} $(C_NOT_LAST); do \
				${CHARG_LINE}; \
			done;
			@${CHARG_LINE} ${C_LAST};
			@if [ "$(OS)" = "Linux" ]; then \
				${CC} ${CFLAGS} ${OBJS} mylib/objs/*/*.o -L./mlx -lmlx -L/usr/lib -lXext -lX11 -lm -o ${NAME}; \
			else \
				${CC} ${CFLAGS} ${OBJS} mylib/objs/*/*.o -L./mlx -lmlx -L./mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}; \
			fi
			@${END_COMP}
			@sleep 0.5

# Play the game
play:	clear draw_running ${NAME}
			@echo "${CLEAR}${GREEN}🔧 Game logs: 🔧${ENDCOLOR}"
			@./${NAME} ${ARGS}
p:		clear ${NAME}
			@echo "${CLEAR}${GREEN}🔧 Game logs: 🔧${ENDCOLOR}"
			@./${NAME} ${ARGS}


###############################################################################
#                   ↓↓↓↓↓           CLEANING           ↓↓↓↓↓                  #
###############################################################################

# Clean object files and executable
clean:
			@echo "${CLEAR}\c"
			@${S_OBJS}
			@${RM} objs/ mlx/ mylib visualizer/${NAME}
			@sleep 0.3
			@echo "${CLEAR}\c"
			@echo "${GREEN}✅ Simple clean completed! ✨"

# Clean everything
fclean: clean
			@echo ""
			@${S_NAME}
			@${RM} ${NAME} tester/trace_loop/*
			@sleep 0.3
			@echo "${CLEAR}\c"
			@echo "${GREEN}✅ Deep clean completed! ✨"

###############################################################################
#                  ↓↓↓↓↓           UTILITIES           ↓↓↓↓↓                  #
###############################################################################

# Drawings
draw_begining:
			@echo "${CLEAR}${CYAN}\c"
			@cat ascii_art/prog_name
			@sleep 0.3
			@echo "${CLEAR}${GRAY}\c"
			@cat ascii_art/prog_by
			@sleep 0.3
			@echo "${CLEAR}${GREEN}\c"
			@cat ascii_art/prog_login
			@sleep 0.3
			@echo "${CLEAR}\c"

draw_running:
			@echo "${CLEAR}${BLUE}\c"
			@cat ascii_art/prog_running_1
			@sleep 0.5
			@echo "${CLEAR}${BLUE}\c"
			@cat ascii_art/prog_running_2
			@sleep 0.5
			@echo "${CLEAR}${BLUE}\c"
			@cat ascii_art/prog_running_3
			@sleep 0.5

draw_ready:
			@echo "${CLEAR}${GREEN}${BOLD}\c"
			@cat ascii_art/prog_ready
			@echo "${ENDCOLOR}"
			@make help PRINT_SCREEN=NO

# Build mylib dependency
lib:	clear
			@if [ -d mylib ]; then \
				echo "${GREEN}🎉 Program already exists, updating it. 🔄\n${RESET}"; \
				git -C mylib pull; \
				echo ""; \
				make -C mylib; \
				echo "\c"; \
				sleep 0.3; \
			else \
				git clone https://github.com/rphlr/mylib --quiet; \
				make -C mylib; \
				echo "\c"; \
				sleep 0.3; \
				${START}; \
			fi
			@if [ -d mlx ]; then \
				echo "${GREEN}MLX library found !${RESET}"; \
				${START}; \
				echo ""; \
			else \
				if [ "$(shell uname)" = "Linux" ]; then \
					$(MKDIR) mlx && tar -xzf minilibx-linux.tgz -C mlx --strip-components 1 > /dev/null 2>&1; \
				else \
					$(MKDIR) mlx && tar -xzf minilibx_opengl.tgz -C mlx --strip-components 1 > /dev/null 2>&1; \
				fi; \
				echo "\n${YELLOW}MLX library compilation...${RESET}"; \
				make -C mlx > /dev/null 2>&1; \
				echo "${GREEN}\nMLX library compiled !${RESET}"; \
				${START}; \
				echo ""; \
			fi

# Build rule for help function
help:
			@if [ "$(PRINT_SCREEN)" = "YES" ]; then \
				echo "${CLEAR}\c"; \
			fi
			@echo "${GRAY}🏃 Run ${ITALIC}\`./${NAME} <map_path>\`${ENDCOLOR}${GRAY} to sort them. 🚀\n"
			@echo "${BOLD}${UNDERLINE}💡 TIPS: 💡${ENDCOLOR}${GRAY}"
			@echo "\t- You can also use ${ITALIC}\`make play <map_path>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make p <map_path>\`${ENDCOLOR}${GRAY} to try it out."
			@echo "\t- Check for memory leaks with ${ITALIC}\`make leaks <map_path>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make l <map_path>\`${ENDCOLOR}${GRAY}."
			@echo "\t- Check the 42 norm with ${ITALIC}\`make norm\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make n\`${ENDCOLOR}${GRAY}."
			@echo ""
			@echo "${YELLOW}🌟 Use ${ITALIC}\`make help\`${ENDCOLOR}${YELLOW} or ${ITALIC}\`make h\`${ENDCOLOR}${YELLOW} to display these helpful tips. 🚀${ENDCOLOR}"
h:		help

# Norminette
norm:
			@norminette srcs && norminette includes
n:		norm

# Leaks
leaks:	clear ${NAME}
			@echo "${CLEAR}\c"
			@leaks -atExit -- ./${NAME} ${ARGS}
l:		clear ${NAME}
			@echo "${CLEAR}\c"
			@leaks -atExit -- ./${NAME} ${ARGS}

# Run the program with lldb
lldb:	clear ${NAME}
			@echo "${CLEAR}"
			@lldb ./${NAME} ${ARGS}
			@echo "${CLEAR}"

# Push the files to Git
git:	fclean
			@echo "${CLEAR}"
			@git add .
			@echo "${CYAN}✅ Added files to git! 📁"
			@git commit -m "$(ARGS)"
			@echo "${BLUE}✅ Changes committed! ✔️"
			@git push
			@echo "${GREEN}✅ All changes are now on GitHub! 🚀${ENDCOLOR}"

# Dummy target to prevent arguments with dashes from being interpreted as targets
%:
			@:

# Clear the screen
clear:😎
			@echo "${CLEAR}\c"

# Rebuild the program
re: fclean all

.PHONY: all clean fclean re run basic-test test 