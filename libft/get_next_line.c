/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguerrei < hguerrei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:56:45 by hguerrei          #+#    #+#             */
/*   Updated: 2025/02/10 14:04:07 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[0] || (read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (flagfunc(buffer))
			break ;
	}
	return (line);
}
