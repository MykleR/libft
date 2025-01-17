/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection_deletion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:21:47 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 01:18:36 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <collection.h>

void	collection_vanish(t_collection *c, uint32_t index,
					void (*del)(void *))
{
	if (__builtin_expect(!c || !c->data || index >= c->cap || !c->len, 0))
		return ;
	c->len--;
	if (del && *(void **)(c->data + c->mem * index))
		del(*(void **)(c->data + c->mem * index));
	ft_memset(c->data + c->mem * index, 0, c->mem);
}

void	collection_rplast(t_collection *c, uint32_t index,
			void (*del)(void *))
{
	if (__builtin_expect(!c || !c->data || index >= c->len || !c->len, 0))
		return ;
	collection_vanish(c, index, del);
	if (index < c->len)
		ft_memmove(c->data + c->mem * index, c->data + c->mem * c->len, c->mem);
}

void	collection_remove(t_collection *c, uint32_t index,
			void (*del)(void *))
{
	if (__builtin_expect(!c || !c->data || index >= c->len || !c->len, 0))
		return ;
	collection_vanish(c, index, del);
	if (index < c->len)
		ft_memmove(c->data + c->mem * index, c->data + c->mem * (index + 1),
			c->mem * (c->len - index));
	ft_memset(c->data + c->mem * c->len, 0, c->mem);
}
