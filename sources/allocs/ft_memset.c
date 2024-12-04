/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:31:57 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:12:18 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	val;

	mem = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*mem++ = val;
	return (s);
}
