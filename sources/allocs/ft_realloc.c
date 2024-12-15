/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:56:57 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/15 16:45:27 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

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

void	*dc_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	if (__builtin_expect(!ptr, 0))
		return (dc_malloc(new_size));
	if (__builtin_expect(old_size >= new_size, 0))
		return (ptr);
	result = dc_malloc(new_size);
	ft_memcpy(result, ptr, old_size);
	dc_free(ptr);
	return (result);
}

void	*sc_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	if (__builtin_expect(!ptr, 0))
		return (sc_malloc(new_size));
	if (__builtin_expect(old_size >= new_size, 0))
		return (ptr);
	result = sc_malloc(new_size);
	ft_memcpy(result, ptr, old_size);
	sc_free(ptr);
	return (result);
}
