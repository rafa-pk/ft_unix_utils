/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:10:09 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/08/19 15:55:28 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	ft_cat(char *filename)
{
	int		fd;
	int		byte_count;
	char	buff[BUFF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (handle_errors(filename, errno));
	byte_count = read(fd, buff, BUFF_SIZE);
	while (byte_count > 0)
	{
		write(1, buff, byte_count);
		byte_count = read(fd, buff, BUFF_SIZE);
	}
	if (byte_count < 0)
		return (handle_errors(filename, errno));
	close (fd);
	return (0);
}
