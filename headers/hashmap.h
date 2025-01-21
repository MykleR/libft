/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:23:11 by mykle             #+#    #+#             */
/*   Updated: 2025/01/21 00:56:51 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <collection.h>
# include <libft_string.h>

typedef struct s_hm_entry
{
	const char	*key;
	void		*value;
}	t_hm_entry;

uint32_t	hash(const char *data, int len);
bool		hm_create(t_collection *h, uint32_t cap);
void		*hm_get(t_collection *h, const char *key);
void		hm_set(t_collection *h, const char *key, void *val);
#endif
