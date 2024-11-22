/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:38:49 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/10 12:47:27 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	if (!s || start > ft_strlen(s))
		return (ft_calloc(1, 1));
	length = ft_strlen(s + start);
	if (len > length)
		len = length;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = 0;
	return (result);
}
