/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:27:29 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/24 17:27:31 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t len)
{
	void	*ptr;

	ptr = malloc(count * len);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * len);
	return (ptr);
}
