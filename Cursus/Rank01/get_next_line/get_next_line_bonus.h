/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:03:48 by rrouille          #+#    #+#             */
/*   Updated: 2022/12/15 17:30:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*trim_last_list_element(t_list **lst);
char	*trim_last_list_element_helper(t_list *last, int i);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
bool	found_new_line(t_list *stash);
void	free_stash(t_list *stash);
void	append_buffer_to_stash(t_list **stash, char *buffer, int num_bytes);
void	generate_line(char **line, t_list *stash);

#endif
