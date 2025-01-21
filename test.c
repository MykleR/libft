/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:56:21 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/21 21:49:50 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	keyval_print(t_hm_bucket *bucket, uint32_t index)
{
	char	*key = *(char **)(collection_get(&bucket->keys, index));
	int		val = *(int *)(collection_get(&bucket->values, index));

	ft_printf("[\"%s\" : %d], ", key, val);
}

static void	__hashmap_iter(void *ptr, void *arg)
{
	t_hm_bucket	*bucket;
	uint32_t	i;

	(void) arg;
	bucket = ptr;
	i = -1;
	while (++i < bucket->keys.len)
		keyval_print(bucket, i);
}

int	main(void)
{
	t_hm	hm;

	hm_create(&hm, 32, sizeof(int), (t_clear_info){.func=0});
	hm_set(&hm, "Bonjour", &((int){0}));
	hm_set(&hm, "Hola", &((int){0}));
	hm_set(&hm, "Hola", &((int){10}));
	hm_set(&hm, "m", &((int){50}));
	hm_set(&hm, "salut", &((int){1000}));
	collection_iter(&hm, NULL, __hashmap_iter);
	collection_destroy(&hm);
}
