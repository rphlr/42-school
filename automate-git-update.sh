#!/bin/bash

# Récupérer le répertoire parent du script
base_dir=$(dirname "$0")

# Récupérer la liste des sous-modules
submodules=$(git config --file .gitmodules --get-regexp path | awk '{ print $2 }')

# Parcourir chaque sous-module
for submodule in $submodules; do
    echo "Entering '$submodule'"
    # Se déplacer dans le sous-module
    cd "$base_dir/$submodule" || continue
    # Ajouter les modifications
    git add -A
    # Vérifier s'il y a des modifications
    if git diff --cached --quiet; then
        echo "No changes in '$submodule'"
    else
        # Commit les modifications
        git commit -m "Update submodule"
        # Pousse les modifications vers la branche correspondante
        git push origin HEAD
    fi
    # Revenir au répertoire parent
    cd "$base_dir"
done
