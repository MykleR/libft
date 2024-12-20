/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_allocs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:31:30 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/15 16:35:31 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALLOCS_H
# define LIBFT_ALLOCS_H

# include <stdlib.h>
# include <stdint.h>

# define CACHE_STATIC_MAX 0x10000
# define CACHE_DYNAMIC_INIT 0x1000

typedef struct s_mem_dynamic_cache
{
	void		**allocs;
	uint32_t	cap;
	uint32_t	len;
}	t_mem_dynamic_cache;

typedef struct s_mem_static_cache
{
	void		*allocs[CACHE_STATIC_MAX];
	uint32_t	len;
}	t_mem_static_cache;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t nsize, size_t osize);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*sc_malloc(size_t size);
void	*dc_malloc(size_t size);
void	sc_free(void *ptr);
void	dc_free(void *ptr);
void	*dc_realloc(void *ptr, size_t old_size, size_t new_size);
void	*sc_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
