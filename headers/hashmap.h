/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:23:11 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 17:19:55 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <collection.h>
# include <libft_string.h>

typedef t_collection	t_hm;

typedef struct s_hm_bucket
{
	t_collection	keys;
	t_collection	values;
}	t_hm_bucket;

uint32_t	hash(const char *data, int len);

bool		hm_create(t_hm *h, uint32_t cap, size_t mem, t_clear_info clear);
void		*hm_get(t_hm *h, const char *key);
void		hm_set(t_hm *h, const char *key, void *val);
#endif
