/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:22:48 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 00:56:59 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hashmap.h>

bool	hm_create(t_collection *h, uint32_t cap)
{
	uint32_t		i;

	cap--;
	cap |= cap >> 1;
	cap |= cap >> 2;
	cap |= cap >> 4;
	cap |= cap >> 8;
	cap |= cap >> 16;
	cap++;
	if (__builtin_expect(!h || !cap, 0))
		return (false);
	if (!collection_create(h, sizeof(t_collection **), cap,
			(void (*)(void *))collection_free))
		return (false);
	i = -1;
	while (++i < cap)
		collection_append(h, &((t_collection *){
				collection_instance(sizeof(t_hm_entry), 2, NULL)}));
	return (true);
}

void	*hm_get(t_collection *h, const char *key)
{
	t_collection	*query;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return (NULL);
	index = hash(key, ft_strlen(key)) & (h->cap - 1);
	query = *(((t_collection **)h->data) + index);
	index = 0;
	while (index < query->len && ft_strcmp(
			(((t_hm_entry *)query->data) + index)->key, key))
		index++;
	if (__builtin_expect(index < query->len, 1))
		return ((((t_hm_entry *)query->data) + index)->value);
	return (NULL);
}

void	hm_set(t_collection *h, const char *key, void *val)
{
	t_collection	*query;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return ;
	index = hash(key, ft_strlen(key)) & (h->cap - 1);
	query = *(((t_collection **)h->data) + index);
	index = 0;
	while (index < query->len && ft_strcmp(
			(((t_hm_entry *)query->data) + index)->key, key))
		index++;
	if (index >= query->len)
		collection_append(query, &((t_hm_entry){key, val}));
	(((t_hm_entry *)query->data) + index)->value = val;
}
