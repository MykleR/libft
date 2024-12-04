/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:01 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:16:33 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strdup(const char *src)
{
	char	*result;
	size_t	len;

	len = ft_strlen(src);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, src, len);
	*(result + len) = '\0';
	return (result);
}
