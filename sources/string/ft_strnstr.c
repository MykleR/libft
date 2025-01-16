/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:10 by mrouves           #+#    #+#             */
/*   Updated: 2025/01/16 16:52:31 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	i = -1;
	while (len && big[++i] && little_len <= len && i <= len - little_len)
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)(big + i));
	return (NULL);
}
