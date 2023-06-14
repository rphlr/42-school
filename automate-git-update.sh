#!/bin/bash

# Define color codes for colored terminal output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${GREEN}Starting script to update all submodules and main repository...${NC}"

# For each submodule, recursively...
echo -e "${GREEN}Updating submodules...${NC}"
git submodule foreach --recursive ' 

    # Print current submodule
    echo -e "${RED}Working on submodule: $path${NC}"

    # Try to switch to the main branch. If the main branch does not exist (which could happen in a detached HEAD state),
    # create and switch to a new main branch
    git checkout main || git checkout -b main && 

    # Add all changes in the current submodule
    git add . && 

    # Commit with the message "Submodule updated"
    git commit -m "Submodule updated" && 

    # Push the changes to the main branch of the submodule
    git push origin main || 

    # If the previous commands fail (i.e., there are no changes to commit), display the message "No change to commit" and proceed to the next submodule
    echo -e "${RED}No change to commit in submodule: $path${NC}" 
'

# Add all changes in the main repository
echo -e "${GREEN}Updating main repository...${NC}"
git add .

# Commit with the message "Submodules updated"
git commit -m "Submodules updated"

# Push the changes to the main branch of the main repository on GitHub
git push origin main

echo -e "${GREEN}Script execution completed.${NC}"
