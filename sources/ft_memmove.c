/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:24 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/10 09:57:07 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (!dst && !src)
		return (NULL);
	cdst = (unsigned char *)dst + n - 1;
	csrc = (unsigned char *)src + n - 1;
	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n--)
			*cdst-- = *csrc--;
	}
	return (dst);
}
