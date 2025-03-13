/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:56:45 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/13 04:22:01 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(result + len_s1, s2, len_s2 + 1);
	return (result);
}

char	*ft_strjoins(const char **strings, int n, const char *sep)
{
	char	*result;
	int		i;
	int		len;
	int		sep_len;

	len = 1;
	i = -1;
	if (!strings || !sep || n <= 0)
		return (NULL);
	sep_len = ft_strlen(sep);
	while (++i < n)
		len += ft_strlen(strings[i]);
	len += sep_len * (n - 1);
	result = ft_calloc(len, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if (strings[i])
			ft_strlcat(result, strings[i], len);
		if (i < n - 1)
			ft_strlcat(result, sep, len);
	}
	return (result);
}
