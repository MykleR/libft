/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_allocs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:31:30 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 12:38:24 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ALLOCS_H
# define LIBFT_ALLOCS_H

# include <stdlib.h>
# include <stdint.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t nsize, size_t osize);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
