cmake_minimum_required(VERSION 3.25)
project(42_school)

set(CMAKE_CXX_STANDARD 14)

include_directories(Cursus/Rank00/libft)
include_directories(Cursus/Rank01/ft_printf/includes)
include_directories(Cursus/Rank01/get_next_line)
include_directories(Cursus/Rank02/fract-ol/includes)
include_directories(Cursus/Rank02/pipex/includes)
include_directories(Cursus/Rank02/push_swap/includes)
include_directories(Cursus/Rank02/push_swap/tester/files/includes)
include_directories(Cursus/Rank02/push_swap/tester/files/libft)
include_directories(Cursus/Rank02/so_long/includes)
include_directories(Cursus/Rank03/Philosophers)
include_directories("Exams/Rank02/Level 3/ft_list_size")
include_directories("Exams/Rank02/Level 4/flood_fill")
include_directories("Exams/Rank02/Level 4/ft_list_foreach")
include_directories("Exams/Rank02/Level 4/sort_list")
include_directories(Piscine/C08/ex00)
include_directories(Piscine/C08/ex01)
include_directories(Piscine/C08/ex02)
include_directories(Piscine/C08/ex03)
include_directories(Piscine/RUSH02/ex00)
include_directories(Piscine/RUSH02/ex00/includes)

add_executable(42_school
    Cursus/Rank00/libft/ft_atoi.c
    Cursus/Rank00/libft/ft_bzero.c
    Cursus/Rank00/libft/ft_calloc.c
    Cursus/Rank00/libft/ft_isalnum.c
    Cursus/Rank00/libft/ft_isalpha.c
    Cursus/Rank00/libft/ft_isascii.c
    Cursus/Rank00/libft/ft_isdigit.c
    Cursus/Rank00/libft/ft_isprint.c
    Cursus/Rank00/libft/ft_itoa.c
    Cursus/Rank00/libft/ft_lstadd_back_bonus.c
    Cursus/Rank00/libft/ft_lstadd_front_bonus.c
    Cursus/Rank00/libft/ft_lstclear_bonus.c
    Cursus/Rank00/libft/ft_lstdelone_bonus.c
    Cursus/Rank00/libft/ft_lstiter_bonus.c
    Cursus/Rank00/libft/ft_lstlast_bonus.c
    Cursus/Rank00/libft/ft_lstmap_bonus.c
    Cursus/Rank00/libft/ft_lstnew_bonus.c
    Cursus/Rank00/libft/ft_lstsize_bonus.c
    Cursus/Rank00/libft/ft_memchr.c
    Cursus/Rank00/libft/ft_memcmp.c
    Cursus/Rank00/libft/ft_memcpy.c
    Cursus/Rank00/libft/ft_memmove.c
    Cursus/Rank00/libft/ft_memset.c
    Cursus/Rank00/libft/ft_putchar_fd.c
    Cursus/Rank00/libft/ft_putendl_fd.c
    Cursus/Rank00/libft/ft_putnbr_fd.c
    Cursus/Rank00/libft/ft_putstr_fd.c
    Cursus/Rank00/libft/ft_split.c
    Cursus/Rank00/libft/ft_strchr.c
    Cursus/Rank00/libft/ft_strdup.c
    Cursus/Rank00/libft/ft_striteri.c
    Cursus/Rank00/libft/ft_strjoin.c
    Cursus/Rank00/libft/ft_strlcat.c
    Cursus/Rank00/libft/ft_strlcpy.c
    Cursus/Rank00/libft/ft_strlen.c
    Cursus/Rank00/libft/ft_strmapi.c
    Cursus/Rank00/libft/ft_strncmp.c
    Cursus/Rank00/libft/ft_strnstr.c
    Cursus/Rank00/libft/ft_strrchr.c
    Cursus/Rank00/libft/ft_strtrim.c
    Cursus/Rank00/libft/ft_substr.c
    Cursus/Rank00/libft/ft_tolower.c
    Cursus/Rank00/libft/ft_toupper.c
    Cursus/Rank00/libft/libft.h
    Cursus/Rank01/ft_printf/includes/ft_printf.h
    Cursus/Rank01/ft_printf/includes/ft_printf_bonus.h
    Cursus/Rank01/ft_printf/includes/mylib.h
    Cursus/Rank01/ft_printf/lib/srcs/is/ft_isalnum.c
    Cursus/Rank01/ft_printf/lib/srcs/is/ft_isalpha.c
    Cursus/Rank01/ft_printf/lib/srcs/is/ft_isascii.c
    Cursus/Rank01/ft_printf/lib/srcs/is/ft_isdigit.c
    Cursus/Rank01/ft_printf/lib/srcs/is/ft_isprint.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstadd_back.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstadd_front.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstclear.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstdelone.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstiter.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstlast.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstmap.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstnew.c
    Cursus/Rank01/ft_printf/lib/srcs/lst/ft_lstsize.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_factorial.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_fibonacci.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_find_next_prime.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_is_prime.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_power.c
    Cursus/Rank01/ft_printf/lib/srcs/math/ft_sqrt.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_bzero.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_calloc.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_memchr.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_memcmp.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_memcpy.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_memmove.c
    Cursus/Rank01/ft_printf/lib/srcs/mem/ft_memset.c
    Cursus/Rank01/ft_printf/lib/srcs/print/print_hex.c
    Cursus/Rank01/ft_printf/lib/srcs/print/print_nbr.c
    Cursus/Rank01/ft_printf/lib/srcs/print/print_prt.c
    Cursus/Rank01/ft_printf/lib/srcs/print/print_str.c
    Cursus/Rank01/ft_printf/lib/srcs/print/print_unsigned.c
    Cursus/Rank01/ft_printf/lib/srcs/put/ft_putchar_fd.c
    Cursus/Rank01/ft_printf/lib/srcs/put/ft_putendl_fd.c
    Cursus/Rank01/ft_printf/lib/srcs/put/ft_putnbr_fd.c
    Cursus/Rank01/ft_printf/lib/srcs/put/ft_putstr_fd.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_split.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strchr.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strdup.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_striteri.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strjoin.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strlcat.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strlcpy.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strlen.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strmapi.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strncmp.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strnstr.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strrchr.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_strtrim.c
    Cursus/Rank01/ft_printf/lib/srcs/str/ft_substr.c
    Cursus/Rank01/ft_printf/lib/srcs/to/ft_atoi.c
    Cursus/Rank01/ft_printf/lib/srcs/to/ft_itoa.c
    Cursus/Rank01/ft_printf/lib/srcs/to/ft_tolower.c
    Cursus/Rank01/ft_printf/lib/srcs/to/ft_toupper.c
    Cursus/Rank01/ft_printf/lib/srcs/to/ft_unsigned_itoa.c
    Cursus/Rank01/ft_printf/srcs/ft_printf.c
    Cursus/Rank01/get_next_line/get_next_line.c
    Cursus/Rank01/get_next_line/get_next_line.h
    Cursus/Rank01/get_next_line/get_next_line_bonus.c
    Cursus/Rank01/get_next_line/get_next_line_bonus.h
    Cursus/Rank01/get_next_line/get_next_line_utils.c
    Cursus/Rank01/get_next_line/get_next_line_utils_bonus.c
    Cursus/Rank02/fract-ol/includes/fractol.h
    Cursus/Rank02/fract-ol/srcs/main.c
    Cursus/Rank02/pipex/includes/pipex.h
    Cursus/Rank02/pipex/srcs/command.c
    Cursus/Rank02/pipex/srcs/env.c
    Cursus/Rank02/pipex/srcs/file.c
    Cursus/Rank02/pipex/srcs/free.c
    Cursus/Rank02/pipex/srcs/main.c
    Cursus/Rank02/push_swap/includes/push_swap.h
    Cursus/Rank02/push_swap/srcs/main/file_utils.c
    Cursus/Rank02/push_swap/srcs/main/main.c
    Cursus/Rank02/push_swap/srcs/main/printing.c
    Cursus/Rank02/push_swap/srcs/main/push_swap.c
    Cursus/Rank02/push_swap/srcs/main/quicksort.c
    Cursus/Rank02/push_swap/srcs/main/reverse_rotation.c
    Cursus/Rank02/push_swap/srcs/main/rotation.c
    Cursus/Rank02/push_swap/srcs/main/sorting_stack.c
    Cursus/Rank02/push_swap/srcs/main/stack_access.c
    Cursus/Rank02/push_swap/srcs/main/stack_operations.c
    Cursus/Rank02/push_swap/srcs/main/stack_utility.c
    Cursus/Rank02/push_swap/srcs/main/utils.c
    Cursus/Rank02/push_swap/tester/files/includes/utils.h
    Cursus/Rank02/push_swap/tester/files/libft/binary_search.c
    Cursus/Rank02/push_swap/tester/files/libft/deque.c
    Cursus/Rank02/push_swap/tester/files/libft/deque_utils.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_atoi.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_bzero.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_calloc.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isalnum.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isalpha.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isascii.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isdigit.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isprint.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_isspace.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_itoa.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstadd_back.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstadd_front.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstclear.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstdelone.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstfind.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstiter.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstlast.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstmap.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstnew.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_lstsize.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memccpy.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memchr.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memcmp.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memcpy.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memmove.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memory.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memory_utils.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_memset.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_minmax.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_putchar_fd.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_putendl_fd.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_putnbr_fd.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_putstr_fd.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_sort.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_split.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_sqrt.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strchr.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strdup.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strjoin.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strlcat.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strlcpy.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strlen.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strmapi.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strncmp.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strnstr.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strrchr.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_strtrim.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_substr.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_tolower.c
    Cursus/Rank02/push_swap/tester/files/libft/ft_toupper.c
    Cursus/Rank02/push_swap/tester/files/libft/get_next_line.c
    Cursus/Rank02/push_swap/tester/files/libft/get_next_line.h
    Cursus/Rank02/push_swap/tester/files/libft/get_next_line_sub.c
    Cursus/Rank02/push_swap/tester/files/libft/get_next_line_utils.c
    Cursus/Rank02/push_swap/tester/files/libft/libft.h
    Cursus/Rank02/push_swap/tester/files/srcs/bonus/bonus.c
    Cursus/Rank02/push_swap/tester/files/srcs/bonus/main.c
    Cursus/Rank02/push_swap/tester/files/srcs/checker/check.c
    Cursus/Rank02/push_swap/tester/files/srcs/checker/main.c
    Cursus/Rank02/push_swap/tester/files/srcs/radix/main.c
    Cursus/Rank02/push_swap/tester/files/srcs/radix/radix.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/operation1.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/operation2.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/operation3.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/operation4.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/parse.c
    Cursus/Rank02/push_swap/tester/files/srcs/share/utils.c
    Cursus/Rank02/push_swap/tester/files/algo.cpp
    Cursus/Rank02/push_swap/tester/files/gen.cpp
    Cursus/Rank02/push_swap/tester/files/main.cpp
    Cursus/Rank02/so_long/includes/macros.h
    Cursus/Rank02/so_long/includes/so_long.h
    Cursus/Rank02/so_long/includes/struct.h
    Cursus/Rank02/so_long/srcs/enemy/enemy.c
    Cursus/Rank02/so_long/srcs/enemy/enemy_animation.c
    Cursus/Rank02/so_long/srcs/enemy/enemy_destination.c
    Cursus/Rank02/so_long/srcs/enemy/enemy_movement.c
    Cursus/Rank02/so_long/srcs/map/element_position.c
    Cursus/Rank02/so_long/srcs/map/map.c
    Cursus/Rank02/so_long/srcs/map/map_checking.c
    Cursus/Rank02/so_long/srcs/map/map_creation.c
    Cursus/Rank02/so_long/srcs/map/map_drawing.c
    Cursus/Rank02/so_long/srcs/map/map_exit_drawing.c
    Cursus/Rank02/so_long/srcs/map/map_loading.c
    Cursus/Rank02/so_long/srcs/map/map_processing.c
    Cursus/Rank02/so_long/srcs/player/player.c
    Cursus/Rank02/so_long/srcs/player/player_action.c
    Cursus/Rank02/so_long/srcs/player/player_animation.c
    Cursus/Rank02/so_long/srcs/player/player_resurrection.c
    Cursus/Rank02/so_long/srcs/player/player_speed.c
    Cursus/Rank02/so_long/srcs/player/player_state_processing.c
    Cursus/Rank02/so_long/srcs/player/player_state_update.c
    Cursus/Rank02/so_long/srcs/utils/background_image.c
    Cursus/Rank02/so_long/srcs/utils/display.c
    Cursus/Rank02/so_long/srcs/utils/error_handling.c
    Cursus/Rank02/so_long/srcs/utils/images.c
    Cursus/Rank02/so_long/srcs/utils/initialization.c
    Cursus/Rank02/so_long/srcs/utils/key_handling.c
    Cursus/Rank02/so_long/srcs/utils/position_adjustment.c
    Cursus/Rank02/so_long/srcs/utils/process_entities.c
    Cursus/Rank02/so_long/srcs/utils/utils.c
    Cursus/Rank02/so_long/srcs/game.c
    Cursus/Rank03/Philosophers/philo_bonus/main.c
    Cursus/Rank03/Philosophers/main.c
    Cursus/Rank03/Philosophers/philosophers.h
    "Exams/Rank02/Level 1/first_word/first_word.c"
    "Exams/Rank02/Level 1/fizzbuzz/fizzbuzz.c"
    "Exams/Rank02/Level 1/ft_putstr/ft_putstr.c"
    "Exams/Rank02/Level 1/ft_strcpy/ft_strcpy.c"
    "Exams/Rank02/Level 1/ft_strlen/ft_strlen.c"
    "Exams/Rank02/Level 1/ft_swap/ft_swap.c"
    "Exams/Rank02/Level 1/repeat_alpha/repeat_alpha.c"
    "Exams/Rank02/Level 1/rev_print/rev_print.c"
    "Exams/Rank02/Level 1/rot_13/rot_13.c"
    "Exams/Rank02/Level 1/rotone/rotone.c"
    "Exams/Rank02/Level 1/search_and_replace/search_and_replace.c"
    "Exams/Rank02/Level 1/ulstr/ulstr.c"
    "Exams/Rank02/Level 2/alpha_mirror/alpha_mirror.c"
    "Exams/Rank02/Level 2/camel_to_snake/camel_to_snake.c"
    "Exams/Rank02/Level 2/do_op/do_op.c"
    "Exams/Rank02/Level 2/ft_atoi/ft_atoi.c"
    "Exams/Rank02/Level 2/ft_strcmp/ft_strcmp.c"
    "Exams/Rank02/Level 2/ft_strcspn/ft_strcspn.c"
    "Exams/Rank02/Level 2/ft_strdup/ft_strdup.c"
    "Exams/Rank02/Level 2/ft_strpbrk/ft_strpbrk.c"
    "Exams/Rank02/Level 2/ft_strrev/ft_strrev.c"
    "Exams/Rank02/Level 2/ft_strspn/ft_strspn.c"
    "Exams/Rank02/Level 2/inter/inter.c"
    "Exams/Rank02/Level 2/is_power_of_2/is_power_of_2.c"
    "Exams/Rank02/Level 2/last_word/last_word.c"
    "Exams/Rank02/Level 2/max/max.c"
    "Exams/Rank02/Level 2/print_bits/print_bits.c"
    "Exams/Rank02/Level 2/reverse_bits/reverse_bits.c"
    "Exams/Rank02/Level 2/snake_to_camel/snake_to_camel.c"
    "Exams/Rank02/Level 2/swap_bits/swap_bits.c"
    "Exams/Rank02/Level 2/union/union.c"
    "Exams/Rank02/Level 2/wdmatch/wdmatch.c"
    "Exams/Rank02/Level 3/add_prime_sum/add_prime_sum.c"
    "Exams/Rank02/Level 3/epur_str/epur_str.c"
    "Exams/Rank02/Level 3/expand_str/expand_str.c"
    "Exams/Rank02/Level 3/ft_atoi_base/ft_atoi_base.c"
    "Exams/Rank02/Level 3/ft_list_size/ft_list.h"
    "Exams/Rank02/Level 3/ft_list_size/ft_list_size.c"
    "Exams/Rank02/Level 3/ft_range/ft_range.c"
    "Exams/Rank02/Level 3/ft_rrange/ft_rrange.c"
    "Exams/Rank02/Level 3/hidenp/hidenp.c"
    "Exams/Rank02/Level 3/paramsum/paramsum.c"
    "Exams/Rank02/Level 3/pgcd/pgcd.c"
    "Exams/Rank02/Level 3/print_hex/print_hex.c"
    "Exams/Rank02/Level 3/rstr_capitalizer/rstr_capitalizer.c"
    "Exams/Rank02/Level 3/str_capitalizer/str_capitalizer.c"
    "Exams/Rank02/Level 3/tab_mult/tab_mult.c"
    "Exams/Rank02/Level 4/flood_fill/flood_fill.c"
    "Exams/Rank02/Level 4/flood_fill/flood_fill.h"
    "Exams/Rank02/Level 4/fprime/fprime.c"
    "Exams/Rank02/Level 4/ft_itoa/ft_itoa.c"
    "Exams/Rank02/Level 4/ft_list_foreach/ft_list.h"
    "Exams/Rank02/Level 4/ft_list_foreach/ft_list_foreach.c"
    "Exams/Rank02/Level 4/ft_list_remove_if/ft_list_remove_if.c"
    "Exams/Rank02/Level 4/ft_split/ft_split.c"
    "Exams/Rank02/Level 4/rev_wstr/rev_wstr.c"
    "Exams/Rank02/Level 4/rostring/rostring.c"
    "Exams/Rank02/Level 4/sort_int_tab/sort_int_tab.c"
    "Exams/Rank02/Level 4/sort_list/sort_list.c"
    "Exams/Rank02/Level 4/sort_list/sort_list.list.h"
    Piscine/C00/ex00/ft_putchar.c
    Piscine/C00/ex01/ft_print_alphabet.c
    Piscine/C00/ex02/ft_print_reverse_alphabet.c
    Piscine/C00/ex03/ft_print_numbers.c
    Piscine/C00/ex04/ft_is_negative.c
    Piscine/C00/ex05/ft_print_comb.c
    Piscine/C00/ex06/ft_print_comb2.c
    Piscine/C00/ex07/ft_putnbr.c
    Piscine/C00/ex08/ft_print_combn.c
    Piscine/C01/ex00/ft_ft.c
    Piscine/C01/ex01/ft_ultimate_ft.c
    Piscine/C01/ex02/ft_swap.c
    Piscine/C01/ex03/ft_div_mod.c
    Piscine/C01/ex04/ft_ultimate_div_mod.c
    Piscine/C01/ex05/ft_putstr.c
    Piscine/C01/ex06/ft_strlen.c
    Piscine/C01/ex07/ft_rev_int_tab.c
    Piscine/C01/ex08/ft_sort_int_tab.c
    Piscine/C02/ex00/ft_strcpy.c
    Piscine/C02/ex01/ft_strncpy.c
    Piscine/C02/ex02/ft_str_is_alpha.c
    Piscine/C02/ex03/ft_str_is_numeric.c
    Piscine/C02/ex04/ft_str_is_lowercase.c
    Piscine/C02/ex05/ft_str_is_uppercase.c
    Piscine/C02/ex06/ft_str_is_printable.c
    Piscine/C02/ex07/ft_strupcase.c
    Piscine/C02/ex08/ft_strlowcase.c
    Piscine/C02/ex09/ft_strcapitalize.c
    Piscine/C02/ex10/ft_strlcpy.c
    Piscine/C02/ex11/ft_putstr_non_printable.c
    Piscine/C03/ex00/ft_strcmp.c
    Piscine/C03/ex01/ft_strncmp.c
    Piscine/C03/ex02/ft_strcat.c
    Piscine/C03/ex03/ft_strncat.c
    Piscine/C03/ex04/ft_strstr.c
    Piscine/C03/ex05/ft_strlcat.c
    Piscine/C04/ex00/ft_strlen.c
    Piscine/C04/ex01/ft_putstr.c
    Piscine/C04/ex02/ft_putnbr.c
    Piscine/C04/ex03/ft_atoi.c
    Piscine/C04/ex04/ft_putnbr_base.c
    Piscine/C04/ex05/ft_atoi_base.c
    Piscine/C05/ex00/ft_iterative_factorial.c
    Piscine/C05/ex01/ft_recursive_factorial.c
    Piscine/C05/ex02/ft_iterative_power.c
    Piscine/C05/ex03/ft_recursive_power.c
    Piscine/C05/ex04/ft_fibonacci.c
    Piscine/C05/ex05/ft_sqrt.c
    Piscine/C05/ex06/ft_is_prime.c
    Piscine/C05/ex07/ft_find_next_prime.c
    Piscine/C06/ex00/ft_print_program_name.c
    Piscine/C06/ex01/ft_print_params.c
    Piscine/C06/ex02/ft_rev_params.c
    Piscine/C06/ex03/ft_sort_params.c
    Piscine/C07/ex00/ft_strdup.c
    Piscine/C07/ex01/ft_range.c
    Piscine/C07/ex02/ft_ultimate_range.c
    Piscine/C07/ex03/ft_strjoin.c
    Piscine/C08/ex00/ft.h
    Piscine/C08/ex01/ft_boolean.h
    Piscine/C08/ex02/ft_abs.h
    Piscine/C08/ex03/ft_point.h
    Piscine/C08/ex04/ft_strs_to_tab.c
    Piscine/C08/ex05/ft_show_tab.c
    Piscine/C09/ex00/ft_putchar.c
    Piscine/C09/ex00/ft_putstr.c
    Piscine/C09/ex00/ft_strcmp.c
    Piscine/C09/ex00/ft_strlen.c
    Piscine/C09/ex00/ft_swap.c
    Piscine/C09/ex02/ft_split.c
    Piscine/C11/ex00/ft_foreach.c
    Piscine/C11/ex01/ft_map.c
    Piscine/C11/ex02/ft_any.c
    Piscine/C11/ex03/ft_count_if.c
    Piscine/C11/ex04/ft_is_sort.c
    Piscine/RUSH00/ex00/ft_putchar.c
    Piscine/RUSH00/ex00/main.c
    Piscine/RUSH00/ex00/rush00.c
    Piscine/RUSH00/ex00/rush01.c
    Piscine/RUSH00/ex00/rush02.c
    Piscine/RUSH00/ex00/rush03.c
    Piscine/RUSH00/ex00/rush04.c
    Piscine/RUSH01/ex00/c_case_4_1.c
    Piscine/RUSH01/ex00/c_case_4_2.c
    Piscine/RUSH01/ex00/c_case_4_4_3.c
    Piscine/RUSH01/ex00/c_numbers.c
    Piscine/RUSH01/ex00/complet_column.c
    Piscine/RUSH01/ex00/decide_columns.c
    Piscine/RUSH02/ex00/includes/ft.h
    Piscine/RUSH02/ex00/srcs/convert_from0_to99.c
    Piscine/RUSH02/ex00/srcs/convert_from100.c
    Piscine/RUSH02/ex00/srcs/convert_write_number.c
    Piscine/RUSH02/ex00/srcs/create_dico.c
    Piscine/RUSH02/ex00/srcs/ft_putstr.c
    Piscine/RUSH02/ex00/srcs/ft_strlen.c
    Piscine/RUSH02/ex00/srcs/isvalid_arg.c
    Piscine/RUSH02/ex00/srcs/main.c
    Piscine/RUSH02/ex00/srcs/trim_arg.c
    Piscine/RUSH02/ex00/ft.h
    Piscine/RUSH02/ex00/ft_convert.c
    Piscine/RUSH02/ex00/ft_putstr.c
    Piscine/RUSH02/ex00/ft_search_ref.c
    Piscine/RUSH02/ex00/isvalid_arg.c
    Piscine/RUSH02/ex00/main.c
    Piscine/RUSH02/ex00/trim_arg.c)
