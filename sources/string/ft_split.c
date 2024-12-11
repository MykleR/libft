/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:04:22 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/11 14:22:38 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_separate(char const *s, char c, char **save)
{
	char const	*start;
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		count += *s != 0;
		start = s;
		while (*s && *s != c)
			s++;
		if (!(*start) || !save)
			continue ;
		save[count - 1] = ft_substr(start, 0, s - start);
		if (!save[count - 1])
			return (0);
	}
	return (count);
}

void	ft_split_free(char **s)
{
	char	**start;

	start = s;
	while (*s)
		free(*s++);
	free(start);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_separate(s, c, 0);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[len] = NULL;
	if (ft_separate(s, c, result) == len)
		return (result);
	ft_split_free(result);
	return (NULL);
}
