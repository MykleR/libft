/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:24 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 01:08:14 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	__hm_entry_iter(void *ptr, void *arg)
{
	t_hm_entry	*entry;

	(void) arg;
	entry = ptr;
	if (entry && entry->key)
		ft_printf("[%s : %d], ", entry->key, *(int *)entry->value);
}

void	__hm_iter(void *ptr, void *arg)
{
	collection_iter(*(t_collection **)ptr, arg, __hm_entry_iter);
}

int	main(void)
{
	t_collection hm;

	hm_create(&hm, 32);
	hm_set(&hm, "bonjour", &((int){10}));
	void *data = hm_get(&hm, "bonjour");
	if (data) ft_printf("%d\n", *(int *)data);
	else ft_printf("%p\n", data);
	collection_iter(&hm, NULL, __hm_iter);
	collection_destroy(&hm);
}
