/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_static_cache_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:59:32 by mykle             #+#    #+#             */
/*   Updated: 2025/03/26 13:02:34 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_allocs.h>
#include <unistd.h>
#include <fcntl.h>

int	*cache_get(void);

int	cached_dup(int oldfd)
{
	int	*cache;
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
	int	*cache;

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

int	cached_pipe(int pipefd[static 2])
{
	int	*cache;

	cache = cache_get();
	if (__builtin_expect(pipe(pipefd) == -1, 0))
		return (-1);
	if (__builtin_expect(pipefd[0] >= CACHE_FD_MAX, 0))
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	if (__builtin_expect(pipefd[1] >= CACHE_FD_MAX, 0))
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	cache[pipefd[0]] = pipefd[0];
	cache[pipefd[1]] = pipefd[1];
	return (0);
}
