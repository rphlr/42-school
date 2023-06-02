/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:45:31 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/04 12:45:31 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/**
* @notice	This function checks if the value sent to him is a printed character.
* @param	int		The value to check.
* @return	int		Returns 1 if true or 0 if false.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
