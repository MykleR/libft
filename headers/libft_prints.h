/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_prints.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:38 by mrouves           #+#    #+#             */
/*   Updated: 2024/12/04 13:13:56 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTS_H
# define LIBFT_PRINTS_H

# include <stdarg.h>
# include <unistd.h>
# include <libft_string.h>

# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define DEC "0123456789"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_putchar_pfd(char c, int fd);
int		ft_putnbr_pfd(int64_t n, int fd);
int		ft_putstr_pfd(const char *s, int fd);
int		ft_putnbr_base_fd(uint64_t n, uint8_t base, const char *table, int fd);
int		ft_printf(int fd, const char *s, ...);

#endif
