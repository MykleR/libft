/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_instance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:37:53 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 01:18:04 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

static inline bool	collection_fill(t_collection *c, uint32_t mem, uint32_t cap)
{
	c->len = 0;
	c->cap = cap;
	c->mem = mem;
	c->data = ft_calloc(mem, cap);
	return (c->data != NULL);
}

bool	collection_create(t_collection *c, uint32_t mem, uint32_t cap)
{
	return (c && mem && cap && collection_fill(c, mem, cap));
}

t_collection	*collection_instance(uint32_t mem, uint32_t cap)
{
	t_collection	*res;

	res = alloc_m(sizeof(t_collection));
	if (__builtin_expect(mem && cap && res
			&& collection_fill(res, mem, cap), 1))
		return (res);
	alloc_f(res);
	return (NULL);
}

void	collection_destroy(t_collection *c, void (*del)(void *))
{
	uint32_t	i;

	if (__builtin_expect(!c || !c->data, 0))
		return ;
	i = -1;
	while (del && ++i < c->cap)
		if (*(void **)(c->data + c->mem * i))
			del(*(void **)(c->data + c->mem * i));
	alloc_f(c->data);
	c->cap = 0;
	c->len = 0;
	c->mem = 0;
	c->data = 0;
}

void	collection_free(t_collection *c, void (*del)(void *))
{
	if (__builtin_expect(!c || !c->data, 0))
		return ;
	collection_destroy(c, del);
	alloc_f(c);
}
