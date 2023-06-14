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
    echo -e "${BOLD}${BLUE}Starting script to update all submodules and main repository...${NC}"
}

function updateSubmodules() {
    echo -e "${BOLD}${YELLOW}Updating submodules...${NC}"
    git submodule foreach --recursive '
        echo -e "${ITALIC}${PURPLE}Working on submodule: $path${NC}"
        git checkout main || git checkout -b main && 
        git add . && 
        git commit -m "Submodule updated" && 
        git push origin main || 
        echo -e "${RED}No change to commit in submodule: $path 🙅‍♂️${NC}" 
    '
}

function updateMainRepo() {
    echo -e "${BOLD}${YELLOW}Updating main repository...${NC}"
    git add .
    git commit -m "Submodules updated"
    git push origin main
}

function endMessage() {
    echo -e "${BOLD}${GREEN}Script execution completed 🎉${NC}"
}

startMessage
updateSubmodules
updateMainRepo
endMessage
