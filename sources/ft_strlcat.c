/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:32:59 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/10 15:45:01 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_length;
	size_t		src_length;
	char		*ptr;

	if ((!dst || !src) && !size)
		return (size);
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size <= dst_length)
		return (size + src_length);
	ptr = dst + dst_length;
	while (*src && (size_t)(ptr - dst) < size - 1)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst_length + src_length);
}
