/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_instance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:37:53 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 13:28:46 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

static inline bool	collection_fill(t_collection *c, uint32_t mem,
						uint32_t cap, t_free f)
{
	c->len = 0;
	c->cap = cap;
	c->mem = mem;
	c->free_f = f;
	c->data = ft_calloc(mem, cap);
	return (c->data != NULL);
}

bool	collection_create(t_collection *c, uint32_t mem,
			uint32_t cap, t_free f)
{
	return (c && mem && cap && collection_fill(c, mem, cap, f));
}

t_collection	*collection_instance(uint32_t mem, uint32_t cap, t_free f)
{
	t_collection	*res;

	res = alloc_m(sizeof(t_collection));
	if (__builtin_expect(mem && cap && res
			&& collection_fill(res, mem, cap, f), 1))
		return (res);
	alloc_f(res);
	return (NULL);
}

void	collection_destroy(t_collection *c)
{
	uint32_t	i;

	if (__builtin_expect(!c || !c->data, 0))
		return ;
	i = -1;
	while (c->free_f && ++i < c->cap)
		if (*(void **)(c->data + c->mem * i))
			c->free_f(*(void **)(c->data + c->mem * i));
	alloc_f(c->data);
	c->cap = 0;
	c->len = 0;
	c->mem = 0;
	c->data = 0;
}

void	collection_free(t_collection *c)
{
	if (__builtin_expect(!c || !c->data, 0))
		return ;
	collection_destroy(c);
	alloc_f(c);
}
