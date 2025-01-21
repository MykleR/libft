/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:22:48 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 17:31:36 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hashmap.h>

static void	__bucket_clear(void *ptr)
{
	t_hm_bucket	*bucket;

	bucket = ptr;
	if (!bucket)
		return ;
	collection_destroy(&bucket->keys);
	collection_destroy(&bucket->values);
}

bool	hm_create(t_hm *h, uint32_t cap, size_t mem, t_clear_info info)
{
	static t_clear_info	keys_clr = {alloc_f, T_HEAP};
	static t_clear_info	bckt_clr = {__bucket_clear, T_STACK};
	t_hm_bucket			*bckt;
	bool				success;

	cap--;
	cap |= cap >> 1;
	cap |= cap >> 2;
	cap |= cap >> 4;
	cap |= cap >> 8;
	cap |= cap >> 16;
	cap++;
	if (__builtin_expect(!h || !cap || !mem, 0))
		return (false);
	success = collection_create(h, sizeof(t_hm_bucket), cap, bckt_clr);
	while (success && h->len < cap)
	{
		bckt = ((t_hm_bucket *)h->data) + h->len++;
		success &= collection_create(&bckt->keys, sizeof(void *), 2, keys_clr);
		success &= collection_create(&bckt->values, mem, 2, info);
	}
	if (!success)
		collection_destroy(h);
	return (success);
}

static inline uint32_t	hm_query(t_hm *h, const char *key,
							t_collection **out_keys, t_collection **out_vals)
{
	uint32_t		index;
	t_collection	*keys;
	t_collection	*vals;

	index = hash(key, ft_strlen(key)) & (h->cap - 1);
	keys = &(((t_hm_bucket *)h->data) + index)->keys;
	vals = &(((t_hm_bucket *)h->data) + index)->values;
	if (out_vals)
		*out_vals = vals;
	if (out_keys)
		*out_keys = keys;
	index = 0;
	while (index < keys->len && ft_strcmp(
			(*(char **)keys->data + index), key))
		index++;
	return (index);
}

void	*hm_get(t_hm *h, const char *key)
{
	t_collection	*vals;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return (NULL);
	index = hm_query(h, key, NULL, &vals);
	if (__builtin_expect(index < vals->len, 1))
		return (vals->data + h->mem * index);
	return (NULL);
}

void	hm_set(t_hm *h, const char *key, void *val)
{
	t_collection	*vals;
	t_collection	*keys;
	uint32_t		index;

	if (__builtin_expect(!h || !key, 0))
		return ;
	index = hm_query(h, key, &keys, &vals);
	if (index >= vals->len)
	{
		collection_append(vals, val);
		collection_append(keys, &((char *){ft_strdup(key)}));
	}
	else
		collection_replace(vals, index, val);
}
