/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_static_cache.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:17:03 by mykle             #+#    #+#             */
/*   Updated: 2025/03/26 13:09:02 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>
#include <unistd.h>
#include <fcntl.h>

int	*cache_get(void)
{
	static int	cache[CACHE_FD_MAX] = {-1};

	return (cache);
}

__attribute__((destructor))
static void	cache_destroy(void)
{
	cache_fd_clear();
}

void	cache_fd_clear(void)
{
	uint32_t	index;

	index = -1;
	while (++index < CACHE_FD_MAX)
		cached_close(index);
}

int	cached_open(const char *pathname, int flags, mode_t mode)
{
	int	*cache;
	int	fd;

	cache = cache_get();
	fd = open(pathname, flags, mode);
	if (__builtin_expect(fd == -1, 0))
		return (-1);
	if (__builtin_expect(fd >= CACHE_FD_MAX, 0))
	{
		close(fd);
		return (-1);
	}
	cache[fd] = fd;
	return (fd);
}

int	cached_close(int fd)
{
	int	*cache;

	cache = cache_get();
	if (__builtin_expect(fd < 0 || fd >= CACHE_FD_MAX || cache[fd] == -1, 0))
		return (-1);
	close(fd);
	cache[fd] = -1;
	return (0);
}
