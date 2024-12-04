/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:33 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/10 15:53:48 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*start;
	size_t		index;

	start = src;
	while (*src)
	{
		index = src - start;
		if (size && index < size - 1)
			*dst++ = *src;
		src++;
	}
	if (size)
		*dst = '\0';
	return (src - start);
}
