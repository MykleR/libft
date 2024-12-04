/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:34:18 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:15:06 by mrouves          ###   ########.fr       */
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
