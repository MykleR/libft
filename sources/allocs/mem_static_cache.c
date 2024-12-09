/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dynamic_cache.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:42 by mykle             #+#    #+#             */
/*   Updated: 2024/12/09 20:44:30 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

static t_mem_static_cache	*cache_get(void)
{
	static t_mem_static_cache	cache = {0};

	return (&cache);
}

__attribute__((destructor))
static void	cache_destroy(void)
{
	t_mem_static_cache	*cache;
	uint32_t			index;

	cache = cache_get();
	index = -1;
	while (++index < CACHE_STATIC_MAX)
	{
		free(cache->allocs[index]);
		cache->allocs[index] = NULL;
	}
	cache->len = 0;
}

void	*dc_malloc(size_t size)
{
	t_mem_static_cache	*cache;
	void				*ptr;
	size_t				index;

	cache = cache_get();
	if (__builtin_expect(cache->len >= CACHE_STATIC_MAX, 0))
		exit(1);
	ptr = malloc(size);
	if (__builtin_expect(!ptr, 0))
		exit(1);
	index = ((uintptr_t)ptr) & (CACHE_STATIC_MAX - 1);
	while (cache->allocs[index] != 0)
		index = (index + 1) & (CACHE_STATIC_MAX - 1);
	cache->allocs[index] = ptr;
	cache->len++;
	return (ptr);
}

void	dc_free(void *ptr)
{
	t_mem_static_cache	*cache;
	size_t				index;
	size_t				start;

	cache = cache_get();
	if (__builtin_expect(!ptr || !cache->len, 0))
		return ;
	index = ((uintptr_t)ptr) & (CACHE_STATIC_MAX - 1);
	start = index;
	while (cache->allocs[index] != ptr)
	{
		index = (index + 1) & (CACHE_STATIC_MAX - 1);
		if (index == start)
			return ;
	}
	free(cache->allocs[index]);
	cache->allocs[index] = NULL;
	cache->len--;
}
