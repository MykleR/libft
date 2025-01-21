/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:55:24 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 17:35:57 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define NB_BUCKETS 32

int	main(void)
{
	t_hm	hm;
	void	*data;

	hm_create(&hm, NB_BUCKETS, sizeof(char **),
		(t_clear_info){alloc_f, T_HEAP});
	hm_set(&hm, "bonjour", &((char *){ft_strdup("hola")}));
	data = hm_get(&hm, "bonjour");
	if (data)
		ft_printf("%s\n", *(char **)data);
	else
		ft_printf("null\n");
	collection_destroy(&hm);
}
