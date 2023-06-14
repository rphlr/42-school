#!/bin/bash

# Define color codes for colored terminal output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

function startMessage() {
    echo -e "${GREEN}Starting script to update all submodules and main repository...${NC}"
}

function updateSubmodules() {
    echo -e "${GREEN}Updating submodules...${NC}"
    git submodule foreach --recursive '
        echo -e "${RED}Working on submodule: $path${NC}"
        git checkout main || git checkout -b main && 
        git add . && 
        git commit -m "Submodule updated" && 
        git push origin main || 
        echo -e "${RED}No change to commit in submodule: $path${NC}" 
    '
}

function updateMainRepo() {
    echo -e "${GREEN}Updating main repository...${NC}"
    git add .
    git commit -m "Submodules updated"
    git push origin main
}

function endMessage() {
    echo -e "${GREEN}Script execution completed.${NC}"
}

startMessage
updateSubmodules
updateMainRepo
endMessage
