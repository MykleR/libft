/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:18:07 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/17 12:16:28 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	fsize;

	fsize = size * nmemb;
	if (nmemb && fsize / nmemb != size)
		return (NULL);
	result = malloc(fsize);
	if (result)
		ft_bzero(result, nmemb * size);
	return (result);
}
