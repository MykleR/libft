/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:21:48 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 00:33:03 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTION_H
# define COLLECTION_H

# include <libft_allocs.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_collection
{
	void		*data;
	uint32_t	mem;
	uint32_t	len;
	uint32_t	cap;
}	t_collection;

t_collection	*collection_instance(uint32_t mem, uint32_t cap);
bool			collection_create(t_collection *c, uint32_t mem, uint32_t cap);

void			collection_destroy(t_collection *c, void (*del)(void *));
void			collection_free(t_collection *c, void (*del)(void *));

void			*collection_get(t_collection *c, uint32_t index);
void			collection_set(t_collection *c, uint32_t index, void *ptr);
void			collection_replace(t_collection *c, uint32_t index,
					void *ptr, void (*del)(void *));
void			collection_clear(t_collection *c, void (*del)(void *));
void			collection_iter(t_collection *c, void *arg,
					void (*iter)(void *, void *));

void			collection_append(t_collection *c, void *ptr);
void			collection_insert(t_collection *c, void *ptr, uint32_t index);

void			collection_rplast(t_collection *c, uint32_t index,
					void (*del)(void *));
void			collection_remove(t_collection *c, uint32_t index,
					void (*del)(void *));
void			collection_vanish(t_collection *c, uint32_t index,
					void (*del)(void *));

#endif
