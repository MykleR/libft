/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:39:24 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:10:51 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H

# include <stdbool.h>
# include <libft_allocs.h>

# define ARRAY_LIST_INIT 32

typedef struct s_array_list
{
	void		*data;
	uint32_t	len;
	uint32_t	cap;
	uint8_t		mem;
}	t_array_list;

void	array_list_destroy(t_array_list *list);
void	array_list_remove(t_array_list *list, uint32_t index);
void	array_list_insert(t_array_list *list, void *ptr);
void	*array_list_get(t_array_list *list, uint32_t index);
bool	array_list_create(t_array_list *list, uint8_t memsize);

#endif
