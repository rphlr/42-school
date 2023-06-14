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

function startMessage() {
    printf "${BOLD}${BLUE}Starting script to update all submodules and main repository...${NC}\n"
}

function updateSubmodules() {
    printf "${BOLD}${YELLOW}Updating submodules...${NC}\n"
    git submodule foreach --recursive '
        printf "${ITALIC}${PURPLE}Working on submodule: $path${NC}\n"
        git checkout main || git checkout -b main
        if git diff-index --quiet HEAD --; then
            printf "${RED}No change to commit in submodule: $path 🙅‍♂️${NC}\n" 
        else
            git add . && 
            git commit -m "Submodule updated" && 
            git push origin main
        fi
    '
}

function updateMainRepo() {
    printf "${BOLD}${YELLOW}Updating main repository...${NC}\n"
    git add .
    git commit -m "Submodules updated"
    git push origin main
}

function endMessage() {
    printf "${BOLD}${GREEN}Script execution completed 🎉${NC}\n"
}

startMessage
updateSubmodules
updateMainRepo
endMessage
