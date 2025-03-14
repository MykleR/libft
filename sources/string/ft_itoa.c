/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:34:27 by mrouves           #+#    #+#             */
/*   Updated: 2025/03/14 02:26:26 by mykle            ###   ########.fr       */
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

void	ft_itoa_buf(int n, char buf[static 12])
{
	ft_memset(buf, 0, 12);
	buf[0] = '-';
	ft_putnbr(n * ((n >= 0) - (n < 0)), buf + (n < 0));
}

char	*ft_itoa(int n)
{
	char	result[12];

	ft_itoa_buf(n, result);
	return (ft_strdup(result));
}
