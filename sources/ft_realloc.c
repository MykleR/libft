/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:56:57 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/03 21:57:19 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	if (__builtin_expect(!ptr, 0))
		return (malloc(new_size));
	if (__builtin_expect(old_size >= new_size, 0))
		return (ptr);
	result = malloc(new_size);
	if (__builtin_expect(result != NULL, 1))
		ft_memcpy(result, ptr, old_size);
	free(ptr);
	return (result);
}
