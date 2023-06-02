/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:08:06 by marvin            #+#    #+#             */
/*   Updated: 2023/04/09 09:08:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// GAME CONSTANTS
# define TILE 64
# define COLLISION_MARGIN 15
# define COLLISION_THRESHOLD -5
# define ENEMY_MOVE_SPEED 10
# define ESC_KEY 53
# define KEY_DOWN 125
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_Q 12
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_D 2
# define KEY_R 15
# define MOVE_SPEED 25

// COLORS
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define WHITE "\e[37m"
# define RESET "\e[0m"
# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"

// MESSAGES DISPLAYED IN THE GAME
# define PROG_NAME "so_long by rrouille"
# define MOVE_COUNT_TEXT "Number of moves: "
# define MEAL_COUNT_TEXT "Number of sushis eaten: "

// MESSAGES DISPLAYED IN THE TERMINAL
# define DEATH_MESSAGE "❌\tToo close to the enemy! You died haha! 💀\n"
# define VICTORY_MESSAGE "✅\tYou won! (That was a piece of cake...) 🎉\n"
# define SUSHI_MSG "✅\tYum, delicious sushi that slaps! 😋🍣\n"
# define SUSHI_DUNG_MESSAGE "⚠️\tI told you, you'd turn into a cow's dung! 🐄💩\n"
# define PLAYER_NOT_FOUND "❌\tPlayer position not found!\n"
# define NEXT_LEVEL_LOADING "🔄\tLoading next level...\n"
# define MEMORY_ERROR "⚠️\tAllocation memomy error"
# define NO_ENEMY "✅\tNo emeny found!\n"
# define FILENAME "✅\tCorrectly loaded %s\n"
# define GAME_FINISHED "🏁\tCongratulations! You've finished the game. 🎉\n"
# define NEXT_MAP_NAME "🗺\tNext map name: %s\n"
# define ARGS "ℹ️\tUsage: %s <map_name>.ber\n"
# define WRONG_MAP_NAME "❌\tInvalid map name: %s is not in the right format.\n"
# define MAP_DOESNT_EXISTS "❌\tMap %s does not exist!\n"
# define MAP_NOT_VALID "❌\tMap %s is not valid!\n"
# define ELEMENTS_NOT_VALID "❌\tThe map contains invalid elements. 🚫🌟\n"
# define PATH_NOT_VALID "❌\tThe map's path is not valid. 🚶‍♂️❌\n"
# define SUSHI_STATS_MSG "⚠️\t%d sushis consumed! Cut it out... 🍱🙅‍♂️\n"
# define SUSHI_EXPLO_MSG "⚠️\t%d sushi(s) consumed! You'll blow up! 💥🍣💀\n"
# define SUSHI_DUNG_MSG "⚠️\tI told you, you'd turn into cow dung! 🐄💩\n"
# define RESURRECTION_MSG "🤸🏼‍♂️\tResurrected! Welcome back Jesus! 🌞😎\n"
# define PLAYER_LOSER_MSG "❌\t3 resurrections, no win? Game over, loser! 💩🎮\n"
# define NOT_CLOSED_WALL "❌\tMap is not rectangle or closed by walls. 🧱\n"
# define IMAGE_ERROR "❌\tError loading image...\n"
# define NEXT_LEVEL_NOT_FOUND "❌\tNext level not found: %s\n"

// # define KEY_A 0
// # define KEY_S 1
// # define KEY_W 13
// # define KEY_SPACE 49

#endif