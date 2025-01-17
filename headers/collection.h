/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:21:48 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/17 14:44:32 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTION_H
# define COLLECTION_H

# include <libft_allocs.h>
# include <stdbool.h>
# include <stdint.h>

typedef void	(*t_free)(void *);

typedef struct s_collection
{
	void		*data;
	t_free		free_f;
	uint32_t	mem;
	uint32_t	len;
	uint32_t	cap;
}	t_collection;

t_collection	*collection_instance(uint32_t mem, uint32_t cap, t_free f);
bool			collection_create(t_collection *c, uint32_t mem,
					uint32_t cap, t_free f);

void			collection_destroy(t_collection *c);
void			collection_free(t_collection *c);

void			collection_clear(t_collection *c);
void			*collection_get(t_collection *c, uint32_t i);
void			collection_set(t_collection *c, uint32_t i, void *p);
void			collection_replace(t_collection *c, uint32_t i, void *p);
void			collection_iter(t_collection *c, void *arg,
					void (*iter)(void *, void *));

void			collection_append(t_collection *c, void *p);
void			collection_insert(t_collection *c, void *p, uint32_t i);

void			collection_rplast(t_collection *c, uint32_t i);
void			collection_remove(t_collection *c, uint32_t i);
void			collection_vanish(t_collection *c, uint32_t i);

#endif
