/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:03:06 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:14:36 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_prints.h>

static int	ft_putptr(uintptr_t ptr, int fd)
{
	if (!ptr)
		return (ft_putstr_pfd("(nil)", fd));
	return (ft_putstr_pfd("0x", fd) + ft_putnbr_base_fd(ptr, 16, LHEX, fd));
}

static int	ft_handle(const char c, va_list args, int fd)
{
	if (c == '%')
		return (ft_putchar_pfd('%', fd));
	if (c == 'c')
		return (ft_putchar_pfd(va_arg(args, int), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pfd(va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_pfd(va_arg(args, char *), fd));
	if (c == 'p')
		return (ft_putptr(va_arg(args, uintptr_t), fd));
	if (c == 'u')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 10, DEC, fd));
	if (c == 'x')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 16, LHEX, fd));
	if (c == 'X')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 16, UHEX, fd));
	return (-1);
}

static int	ft_percent(const char **format, va_list args, int fd)
{
	int		handled;
	char	next;

	next = (*format)[1];
	handled = ft_handle(next, args, fd);
	if (handled < 0)
		return (ft_putchar_pfd('%', fd));
	(*format)++;
	return (handled);
}

static int	ft_parse(const char *format, va_list args, int fd)
{
	int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
			printed += ft_percent(&format, args, fd);
		else
			printed += ft_putchar_pfd(*format, fd);
		format++;
	}
	return (printed);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		printed;

	if (!format || fd < 0)
		return (-1);
	va_start(args, format);
	printed = ft_parse(format, args, fd);
	va_end(args);
	return (printed);
}
