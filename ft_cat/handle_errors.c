/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:07:53 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/08/19 15:52:53 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr(int fd, char *str, char *add)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	i = 0;
	while (add[i])
	{
		write(fd, &add[i], 1);
		i++;
	}
}

int	handle_errors(char *location, int error)
{
	write(2, "cat: ", 5);
	if (ft_strcmp(location, ""))
		ft_putstr(2, location, ": ");
	if (errno == ENOENT)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EISDIR)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EACCES)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EBADF)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EFBIG)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EIO)
		ft_putstr(2, strerror(errno), "\n");
	else if (errno == EINTR)
		ft_putstr(2, strerror(errno), "\n");
	else
		write(2, "Unexpected error\n", 17);
	return (1);
}
