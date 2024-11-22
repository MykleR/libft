/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:30 by mrouves           #+#    #+#             */
/*   Updated: 2024/10/10 12:54:52 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar_fd(*str++, fd);
}

int	ft_putstr_pfd(const char *s, int fd)
{
	int	len;

	if (!s)
		return (ft_putstr_pfd("(null)", fd));
	len = write(fd, s, ft_strlen(s));
	return (len * (len > 0));
}
