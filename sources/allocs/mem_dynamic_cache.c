/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dynamic_cache.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:49:42 by mykle             #+#    #+#             */
/*   Updated: 2024/12/09 20:36:38 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>

static t_mem_dynamic_cache	*cache_get(int init)
{
	static t_mem_dynamic_cache	cache = {0};

	if (__builtin_expect(cache.cap || !init, 1))
		return (&cache);
	cache.allocs = ft_calloc(CACHE_DYNAMIC_INIT, sizeof(void *));
	if (!cache.allocs)
		exit(1);
	cache.cap = CACHE_DYNAMIC_INIT;
	return (&cache);
}

__attribute__((destructor))
static void	cache_destroy(void)
{
	t_mem_dynamic_cache	*cache;
	uint32_t			index;

	cache = cache_get(0);
	index = -1;
	while (++index < cache->cap)
		free(cache->allocs[index]);
	cache->len = 0;
	cache->cap = 0;
	free(cache->allocs);
	cache->allocs = NULL;
}

static void	cache_realloc(t_mem_dynamic_cache *cache)
{
	void		**new_allocs;
	uint32_t	i;
	uint32_t	j;

	if (__builtin_expect((((uint32_t)(cache->cap << 1)) >> 1) != cache->cap, 0))
		exit(1);
	new_allocs = ft_calloc(cache->cap << 1, sizeof(void *));
	if (__builtin_expect(!new_allocs, 0))
		exit(1);
	cache->cap <<= 1;
	i = -1;
	while (++i < cache->len)
	{
		j = ((uintptr_t)cache->allocs[i]) & (cache->cap - 1);
		while (new_allocs[j] != 0)
			j = (j + 1) & (cache->cap - 1);
		new_allocs[j] = (cache->allocs[i]);
	}
	free(cache->allocs);
	cache->allocs = new_allocs;
}

void	*dc_malloc(size_t size)
{
	t_mem_dynamic_cache	*cache;
	void				*ptr;
	size_t				index;

	ptr = malloc(size);
	if (__builtin_expect(!ptr, 0))
		exit(1);
	cache = cache_get(1);
	if (__builtin_expect(cache->len >= cache->cap, 0))
		cache_realloc(cache);
	index = ((uintptr_t)ptr) & (cache->cap - 1);
	while (cache->allocs[index] != 0)
		index = (index + 1) & (cache->cap - 1);
	cache->allocs[index] = ptr;
	cache->len ++;
	return (ptr);
}

void	dc_free(void *ptr)
{
	t_mem_dynamic_cache	*cache;
	size_t				index;
	size_t				start;

	cache = cache_get(0);
	if (__builtin_expect(!ptr || !cache->len, 0))
		return ;
	index = ((uintptr_t)ptr) & (cache->cap - 1);
	start = index;
	while (cache->allocs[index] != ptr)
	{
		index = (index + 1) & (cache->cap - 1);
		if (index == start)
			return ;
	}
	free(cache->allocs[index]);
	cache->allocs[index] = NULL;
	cache->len--;
}
