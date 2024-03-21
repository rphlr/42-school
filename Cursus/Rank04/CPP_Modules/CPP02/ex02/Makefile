# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 13:26:15 by rrouille          #+#    #+#              #
#    Updated: 2023/12/21 15:51:28 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                             Makefile Configuration                           #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME			= zombie

# Arguments passed to the executable
ARGS			= $(filter-out $@,${MAKECMDGOALS})

# Directories for source and object files
SRCSDIR			= srcs
OBJSDIR			= objs
HDRDIR			= includes/

# Terminal color settings for output messages
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ENDCOLOR		= \033[0m

# Background colors for terminal
BG_G			= \033[42m
BG_R			= \033[41m
BG_Y			= \033[43m
BG_B			= \033[44m
BG_M			= \033[45m
BG_C			= \033[46m
BG_W			= \033[47m

# Text formatting options for output messages
BOLD			= \033[1m
UNDERLINE		= \033[4m
ITALIC			= \033[3m
INVERTED		= \033[7m

# Command to clear the screen
CLEAR		= \033c

# Source and object files
SRCS			= $(shell find ${SRCSDIR} -type f -name '*.cpp')
OBJS			= $(SRCS:${SRCSDIR}/%.cpp=${OBJSDIR}/%.o)
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
CXX				= c++
RM				= rm -rf
MAKE			= make
MKDIR			= mkdir -p

# **************************************************************************** #
#                           Compilation Rules                                  #
# **************************************************************************** #

# Rule to compile the entire program
all:			${NAME}

# Rule to compile the main executable
${NAME}:		${OBJS}
			@${MKDIR} ${OBJSDIR}
			@${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

# # Rule to compile object files
${OBJSDIR}/%.o:	${SRCSDIR}/%.cpp
			@echo "${CLEAR}\c"
			@echo "${YELLOW}⌛ Compiling $< into $@...${ENDCOLOR}"
			@${MKDIR} ${@D}
			@${CXX} ${CXXFLAGS} -I ${HDRDIR} -c $< -o $@
			@echo "${CLEAR}\c"
			@echo "${GREEN}✅ $< compiled into $@! ✨${ENDCOLOR}"

# Rebuild the entire project
re:				fclean .WAIT all

################################################################################
#                                 Github                                       #
################################################################################

# Rule to push changes to Git
push:			fclean
			@git add .
			@if [ -z "${ARGS}" ]; then \
				echo "${RED}❌ Please provide a commit message! ✨${ENDCOLOR}"; \
				exit 1; \
			fi
			@git commit -m "${ARGS}"
			@git push

# Rule to pull changes from Git
pull:
			@git pull

################################################################################
#                       Cleaning and Maintenance                               #
################################################################################

# Clean object files and executable
clean:
			@echo "${CLEAR}\c"
			@${RM} ${OBJSDIR}
			@echo "${GREEN}✅ Simple clean completed! ✨"

# Clean everything including the executable
fclean:			clean
			@echo ""
			@${RM} ${NAME}
			@echo "${CLEAR}\c"
			@echo "${GREEN}✅ Deep clean completed! ✨"

################################################################################
#                             Utility Rules                                    #
################################################################################

# Rule to check for memory leaks
leaks:			clear .WAIT ${NAME}
			@echo "${CLEAR}\c"
			@leaks -atExit -- ./${NAME} ${ARGS}
l:				clear ${NAME}
			@echo "${CLEAR}\c"
			@leaks -atExit -- ./${NAME} ${ARGS}

# Rule to run the program with lldb {debugger}
lldb:			clear .WAIT ${NAME}
			@echo "${CLEAR}"
			@lldb ./${NAME} ${ARGS}
			@echo "${CLEAR}"

# Rule to test the program with arguments
test: 			${NAME}
			@./${NAME} ${ARGS}

# Dummy target to prevent arguments from being interpreted as targets
%:
			@:

# Rule to clear the screen
clear:
			@echo "${CLEAR}\c"

.PHONY:			all clean fclean re test push pull leaks l lldb git clear