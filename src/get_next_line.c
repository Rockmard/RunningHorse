/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:43:02 by tpipi             #+#    #+#             */
/*   Updated: 2024/09/02 17:54:04 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/get_next_line.h"

static void	get_buff(int fd, char *buff, int *read_val)
{
	*read_val = read(fd, buff, BUFFER_SIZE);
	if (*read_val > 0)
		buff[*read_val] = 0;
}

static int	end_of_line(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*stash = NULL;
	int			read_val;

	read_val = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (end_of_line(stash) == -1 && read_val > 0)
	{
		get_buff(fd, buff, &read_val);
		if (read_val > 0)
			stash = ft_strjoin(stash, buff);
	}
	if (end_of_line(stash) == -1)
		line = ft_strdup(stash, ft_strlen(stash), 0);
	else
		line = ft_strdup(stash, end_of_line(stash) + 1, 0);
	stash = ft_strcut(stash, end_of_line(stash) + 1);
	free(buff);
	if (ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
