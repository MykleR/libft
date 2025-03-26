/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_static_cache.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:17:03 by mykle             #+#    #+#             */
/*   Updated: 2025/03/26 12:10:48 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>
#include <unistd.h>
#include <fcntl.h>

static int *cache_get(void)
{
	static int	cache[CACHE_FD_MAX] = {-1};

	return (cache);
}

__attribute__((destructor))
static void	cache_destroy(void)
{
	int			*cache;
	uint32_t	index;

	cache = cache_get();
	index = -1;
	while (++index < CACHE_FD_MAX)
		cached_close(cache[index]);
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
	int *cache;

	cache = cache_get();
	if (__builtin_expect(fd < 0 || fd >= CACHE_FD_MAX || cache[fd] == -1, 0))
		return (-1);
	close(fd);
	cache[fd] = -1;
	return (0);
}

int	cached_dup(int oldfd)
{
	int *cache;
	int	newfd;

	cache = cache_get();
	newfd = dup(oldfd);
	if (__builtin_expect(newfd == -1, 0))
		return (-1);
	if (__builtin_expect(newfd >= CACHE_FD_MAX, 0))
	{
		close(newfd);
		return (-1);
	}
	cache[newfd] = newfd;
	return (newfd);
}

int	cached_dup2(int oldfd, int newfd)
{
	int *cache;

	cache = cache_get();
	if (__builtin_expect(newfd < 0 || newfd >= CACHE_FD_MAX, 0))
		return (-1);
	if (__builtin_expect(oldfd == newfd, 0))
		return (newfd);
	if (__builtin_expect(cache[newfd] != -1, 0))
		cached_close(newfd);
	if (__builtin_expect(dup2(oldfd, newfd) == -1, 0))
		return (-1);
	cache[newfd] = newfd;
	return (newfd);
}
