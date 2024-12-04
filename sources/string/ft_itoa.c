/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:34:27 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:15:47 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

static size_t	ft_putnbr(unsigned int n, char *save)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count = ft_putnbr(n / 10, save);
	save[count] = (n % 10) + '0';
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	result[12];

	ft_memset(result, 0, 12);
	result[0] = '-';
	ft_putnbr(n * ((n >= 0) - (n < 0)), result + (n < 0));
	return (ft_strdup(result));
}
