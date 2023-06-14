#!/bin/bash

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

# Define formatting codes
BOLD='\033[1m'
ITALIC='\033[3m'
UNDERLINE='\033[4m'

function startMessage()
{
	printf "\n${BOLD}${BLUE}🚀 Starting script to update all submodules and main repository...${NC}\n"
}

function updateSubmodules()
{
	printf "\n${BOLD}${YELLOW}🔄 Updating submodules...${NC}\n"
	git submodule foreach --recursive '
		printf "\n\t'$ITALIC$PURPLE'📁 Working on submodule: %s'$NC'\n" "$path"
		git checkout main >/dev/null 2>&1 || git checkout -b main >/dev/null 2>&1
		if git diff-index --quiet HEAD --; then
			printf "\t'$RED'No changes to commit in submodule: %s 🙅‍♂️'$NC'\n" "$path"
		else
			git add . && 
			git commit -m "Submodule updated" && 
			git push origin main
			printf "\t'$GREEN'Successfully updated and pushed changes for submodule: %s ✅'$NC'\n" "$path"
		fi
	'
}

function updateMainRepo()
{
	printf "\n${BOLD}${YELLOW}🔄 Updating main repository...${NC}\n"
	if git diff-index --quiet HEAD --; then
		printf $RED"No changes to commit in main repo 🙅‍♂️\n"$NC
	else
		git add . && 
		git commit -m "Submodules updated" && 
		git push origin main
		printf $GREEN"Successfully updated and pushed changes for main repo ✅\n"$NC
	fi
}

function endMessage()
{
	printf "\n${BOLD}${GREEN}🏁 Script execution completed 🎉${NC}\n"
}

startMessage
updateSubmodules
updateMainRepo
endMessage