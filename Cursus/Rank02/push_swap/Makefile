# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:20:40 by rrouille          #+#    #+#              #
#    Updated: 2023/05/17 12:13:44 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME			= push_swap
NAMEBNS			= rrouille_checker

# Arguments passed to the executable
ARGS			= $(filter-out $@,$(MAKECMDGOALS))
PRINT_SCREEN	= YES

# Directories
SRCSDIR			= srcs/main
OBJSDIR			= objs/main
HDRDIR			= includes/
SRCSBNSDIR		= srcs/bonus
OBJSBNSDIR		= objs/bonus

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
SRCSBNS			= $(shell find $(SRCSBNSDIR) -type f -name '*.c')
OBJSBNS			= ${patsubst ${SRCSBNSDIR}%,${OBJSBNSDIR}%,${SRCSBNS:%.c=%.o}}
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
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Build rule for bonus object files
${OBJSBNSDIR}/%.o : ${SRCSBNSDIR}/%.c lib
			@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Linking rule
${NAME}: ${OBJS}
			@${CHARG_LINE}
			@for i in ${OBJS} $(C_NOT_LAST); do \
				${CHARG_LINE}; \
			done;
			@${CHARG_LINE} ${C_LAST};
			@${CC} ${CFLAGS} ${OBJS} mylib/objs/*/*.o -o ${NAME}
			@${END_COMP}
			@sleep 0.5

# Run the program
run:	clear ${NAME}
#	@$(call shuffle_animation)
			@echo "${CLEAR}${GREEN}🔧 Operations completed: 🔧${ENDCOLOR}"
			@./${NAME} ${ARGS}
r:		clear ${NAME}
			@echo "${CLEAR}${GREEN}🔧 Operations completed: 🔧${ENDCOLOR}"
			@./${NAME} ${ARGS}
rl:		clear ${NAME}
			@echo "${CLEAR}${GREEN}🔧 Number of line of the push_swap program: 🔧${ENDCOLOR}"
			@./${NAME} ${ARGS} | wc -l

# Launch the visualizer
view:	draw_viewer
			@cp ./${NAME} visualizer/${NAME} && visualizer/visualizer
v:		view

# Tests
test:
			@cd tester && bash loop.sh ${ARGS}
t:
			@cd tester && bash loop.sh ${ARGS}
basic-test:
			@cd tester && bash basic_test.sh
bt:		basic-test

# Check if the program is correct
check:	clear ${NAME}
			@echo "${CLEAR}${GREEN}✨ Result of checker: ✨${ENDCOLOR}"
			@./${NAME} ${ARGS} | ./checker_Mac ${ARGS}
c:		clear ${NAME}
			@echo "${CLEAR}${GREEN}✨ Result of checker: ✨${ENDCOLOR}"
			@./${NAME} ${ARGS} | ./checker_Mac ${ARGS}

# Bonus
bonus:	draw_bonus ${OBJSBNS}
			@if [ -z "$(BONUS_OBJS)" ]; then \
				echo "${RED}⚠️ Sorry, bonuses are not available yet... ⚠️\n${RESET}"; \
			else \
				${CHARG_LINE}; \
				for i in ${OBJSBNS} $(C_NOT_LAST); do \
					${CHARG_LINE}; \
				done; \
				${CHARG_LINE} ${C_LAST}; \
				${CC} ${CFLAGS} ${OBJSBNS} mylib/objs/*/*.o -o ${NAMEBNS}; \
				${END_COMP}; \
			fi
			@sleep 0.3
b:		bonus


###############################################################################
#                   ↓↓↓↓↓           CLEANING           ↓↓↓↓↓                  #
###############################################################################

# Clean object files and executable
clean:
			@echo "${CLEAR}"
			@${S_OBJS}
			@${RM} objs/ mlx/ mylib visualizer/${NAME}
			@sleep 0.3
			@echo "${CLEAR}"
			@echo "${GREEN}✅ Simple clean completed! ✨\n"

# Clean everything
fclean: clean
			@${S_NAME}
			@${RM} ${NAME} tester/trace_loop/*
			@sleep 0.3
			@echo "${CLEAR}"
			@echo "${GREEN}✅ Deep clean completed! ✨"

###############################################################################
#                  ↓↓↓↓↓           UTILITIES           ↓↓↓↓↓                  #
###############################################################################

# Drawings
draw_begining:
			@echo "${CLEAR}${CYAN}         ██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗     ██╗  ██╗██████╗"
			@echo "         ██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗    ██║  ██║╚════██╗"
			@echo "         ██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝    ███████║ █████╔╝"
			@echo "         ██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝     ╚════██║██╔═══╝"
			@echo "         ██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║              ██║███████╗"
			@echo "         ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝              ╚═╝╚══════╝"
			@sleep 0.3
			@echo "${CLEAR}${GRAY}                                        ██████╗ ██╗   ██╗"
			@echo "                                        ██╔══██╗╚██╗ ██╔╝"
			@echo "                                        ██████╔╝ ╚████╔╝"
			@echo "                                        ██╔══██╗  ╚██╔╝"
			@echo "                                        ██████╔╝   ██║"
			@echo "                                        ╚═════╝    ╚═╝"
			@sleep 0.3
			@echo "${CLEAR}${GREEN}                ██████╗ ██████╗  ██████╗ ██╗   ██╗██╗██╗     ██╗     ███████╗"
			@echo "                ██╔══██╗██╔══██╗██╔═══██╗██║   ██║██║██║     ██║     ██╔════╝"
			@echo "                ██████╔╝██████╔╝██║   ██║██║   ██║██║██║     ██║     █████╗"
			@echo "                ██╔══██╗██╔══██╗██║   ██║██║   ██║██║██║     ██║     ██╔══╝"
			@echo "                ██║  ██║██║  ██║╚██████╔╝╚██████╔╝██║███████╗███████╗███████╗"
			@echo "                ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝╚══════╝╚══════╝╚══════╝"
			@sleep 0.3
			@echo "${CLEAR}"

draw_bonus:
			@echo "${CLEAR}"
			@echo "${BLUE}"
			@echo "                         ###         ###      ###    \`#    \`##+    .#\'         :##:       \'##"
			@sleep 0.01
			@echo "               :;;;;;;;;;\`@@#  ;;;;;;\`@@# ;;; @@\`;;;\`#\`;;:\`#@#\`;;:.+\`.;;;;;;;;,;@@:   ,;;.+@@"
			@sleep 0.01
			@echo "               ;;;\` ;;;;; @@\`;;;;;;;;;\`@@ ;;; @@ ;;;\`#\`;;;\`@@#\`;;:.+\`;;: .;;;;,;@@:   ,;;.+@@"
			@sleep 0.01
			@echo "              ;;;\`#@\`;;;\`#\` ;;;;;;;;;; @ ;;;; @\`;;;\`#\`;;;\`@@#\`;;:.+.;;:,@\'.;;,:@@:   ,;;.\'@@."
			@sleep 0.01
			@echo "              ;;;\`#@\`;;; @ ;;;   ;;;;; @ ;;;;; ;;;; # ;;;\`@@#\`;;:.+\`;;:,@\'    :@@:   ,;;.\'@@."
			@sleep 0.01
			@echo "             :;;\`#@\`;;;\`#\`;;; @@@ ;;; @ ;;;;;;;;;;\`#\`;;;\`@@#\`;;;.+\`;;:,@@\'          ,;;.\'@@."
			@sleep 0.01
			@echo "             :;;;\` ;;;; @ ;;; @@@ ;;; @ ;;;;;;;;;; @ ;;;\`@@#\`;;;.+\`;;;:     :@@:    ,;;.\'@@."
			@sleep 0.01
			@echo "            :;;;;;;;;; # ;;; @@@ ;;; @ ;;;;;;;;;;\`@ ;;;\`@@#\`;;;\`+\`;;;;;;;;;,:@@;   ,;;.\'@@."
			@sleep 0.01
			@echo "            ;;;\` ;;;;; # ;;; @@@ ;;; @ ;;;;;;;;;; @ ;;;\`@@#\`;;;\`+     .;;;;,:@@:   ,;;.\'@@."
			@sleep 0.01
			@echo "           :;;\`#@\`;;; #\`;;; @@@ ;;; @ ;;;;;;;;;; @ ;;;\`@@#\`;;;\`@@+     .;;,:@@;   ,;;.\'@@,"
			@sleep 0.01
			@echo "           :;;\`#@\`;;; #\`;;; @@@ ;;; @ ;;;;;;;;;; @ ;;;\`@@#\`;;;\`@@+     .;;,:@@;   ,;;.\'@@,"
			@sleep 0.01
			@echo "          :;;\`#@\`;;;\`#\`;;; @@@ ;;; @ ;;;; ;;;;; @ ;;;\`@@#\`;;;\`@@+     .;;,:@@;   ,;;.\'@@,"
			@sleep 0.01
			@echo "          :;;\`#@\`;;; #\`;;;;   ;;;; @ ;;; @ ;;;; @ ;;;\`@@#\`;;;\`#    .@+.;;,:@@;       \'@@,"
			@sleep 0.01
			@echo "         :;;;;\` ;;;\`#\`;;;;;;;;;;  @ ;;; @@ ;;; @ ;;;;;  \`;;;\`#\`;;;;: .;;:,@@;"
			@sleep 0.01
			@echo "         :;;;;;;;;;\`#@\`;;;;;;;; @@@ ;;; @@ ;;; @ ;;;;;;;;;;;\`#\`;;;;;;;;: ,@@;"
			@sleep 0.01
			@echo "        :;;;;;;;;;\`#@\`  ;;;;;; @@@ ;;; @@@ ;; @@@ ;;;;;;;; \`@#\`;;;;;;;:,@@\'        ;@@,"
			@sleep 0.01
			@echo "                  #@\`         @@@      @@@    @@@        \`@@#          ,@@\'        ;@@,"
			@sleep 0.3
			@echo "${ENDCOLOR}"

draw_viewer:
			@echo "${CLEAR}"
			@echo "${BLUE}?88   d8P  88b d8888b ?88   d8P  d8P d8888b  88bd88b"
			@echo "d88  d8P'  88Pd8b_,dP d88  d8P' d8P'd8b_,dP  88P'  \`"
			@echo "?8b ,88'  d88 88b     ?8b ,88b ,88' 88b     d88"
			@echo "\`?888P'  d88' \`?888P' \`?888P'888P'  \`?888P'd88'"    
			@echo "${ENDCOLOR}"

draw_ready:
			@echo "${CLEAR}${GREEN}${BOLD}                                                  +-+-+-+-+-+-+-+ +-+-+-+-+-+"
			@echo "                                                  |P|R|O|G|R|A|M| |R|E|A|D|Y|"
			@echo "                                                  +-+-+-+-+-+-+-+ +-+-+-+-+-+"
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
				echo ""; \
			fi
			@${MKDIR} ${OBJSDIR} ${OBJBNSDIR}

# Build rule for help function
help:
			@if [ "$(PRINT_SCREEN)" = "YES" ]; then \
				echo "${CLEAR}\c"; \
			fi
			@echo "${GRAY}🏃 Run ${ITALIC}\`./${NAME} <random number>\`${ENDCOLOR}${GRAY} to sort them. 🚀\n"
			@echo "${BOLD}${UNDERLINE}💡 TIPS: 💡${ENDCOLOR}${GRAY}"
			@echo "\t- You can also use ${ITALIC}\`make run <random number>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make r <random number>\`${ENDCOLOR}${GRAY} to try it out."
			@echo "\t- Check the program with the school tester using ${ITALIC}\`make check <random number>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make c <random number>\`${ENDCOLOR}${GRAY}."
			@echo "\t- Use a simple tester with ${ITALIC}\`make test <size of stack> <number of tests>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make t <size of stack> <number of tests>\`${ENDCOLOR}${GRAY}."
			@echo "\t- Use a basic tester with ${ITALIC}\`make basic-test\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make bt\`${ENDCOLOR}${GRAY}."
			@echo "\t- Use a viewer with ${ITALIC}\`make view\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make v\`${ENDCOLOR}${GRAY}."
			@echo "\t- Check for memory leaks with ${ITALIC}\`make leaks <random number>\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make l <random number>\`${ENDCOLOR}${GRAY}."
			@echo "\t- Check the 42 norm with ${ITALIC}\`make norm\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make n\`${ENDCOLOR}${GRAY}."
			@echo ""
			@echo "\t- Bonus? Try it with ${ITALIC}\`make bonus\`${ENDCOLOR}${GRAY} or ${ITALIC}\`make b\`${ENDCOLOR}${GRAY} 🌟."
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
			@git commit -m "💻 Auto-commit"
			@echo "${BLUE}✅ Changes committed! ✔️"
			@git push
			@echo "${GREEN}✅ All changes are now on GitHub! 🚀${ENDCOLOR}"

# Dummy target to prevent arguments with dashes from being interpreted as targets
%:
			@:

# Clear the screen
clear:
			@echo "${CLEAR}\c"

# Rebuild the program
re: fclean all

.PHONY: all clean fclean re run basic-test test 
