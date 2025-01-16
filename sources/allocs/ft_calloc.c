/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:18:07 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 20:54:41 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	fsize;

	result = NULL;
	fsize = size * nmemb;
	if (__builtin_expect(nmemb || fsize / nmemb == size, 1))
		result = alloc_m(fsize);
	if (__builtin_expect(!result, 0))
		ft_memset(result, 0, nmemb * size);
	return (result);
}
