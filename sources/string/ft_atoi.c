/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:18 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/12 22:23:26 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	sign = (*s != '-') - (*s == '-');
	s += (*s == '-' || *s == '+');
	while (ft_isdigit(*s))
		result = (result << 3) + (result << 1) + (*s++) - '0';
	return (result * sign);
}

bool	ft_safe_atoi(const char *s, int32_t	*out)
{
	uint64_t	convert;
	int8_t		sign;

	if (__builtin_expect(!out || !s || !(*s), 0))
		return (false);
	convert = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	sign = (*s != '-') - (*s == '-');
	s += (*s == '-' || *s == '+');
	if (!(*s))
		return (false);
	while (*s)
	{
		convert = (convert << 1) + (convert << 3) + (*s) - '0';
		if (!ft_isdigit(*s++) || convert - (sign < 0) > INT32_MAX)
			return (false);
	}
	*out = convert * sign;
	return (true);
}
