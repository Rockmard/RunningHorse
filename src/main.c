/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:01:09 by tpipi             #+#    #+#             */
/*   Updated: 2024/09/02 19:23:05 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/lib.h"

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_get_ascii(char *path)
{
	char	*ascii;
	char	*nl;
	int		fd;

	ascii = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (nl)
	{
		nl = get_next_line(fd);
		ascii = ft_strjoin(ascii, nl);
		free(nl);
	}
	close(fd);
	return (ascii);
}

char	*ft_get_path(int nb)
{
	char	*nb_in_char;
	char	*path;

	nb_in_char = malloc(sizeof(char) * 5);
	if (!nb_in_char)
		return (0);
	sprintf(nb_in_char, "%d", nb);
	path = ft_join("./ascii/h", nb_in_char);
	return (path);
}

int	main(void)
{
	int		nb_img;
	char	*path;
	char	*img_to_print;

	img_to_print = malloc(sizeof(char) * 5);
	if (!img_to_print)
		return (0);
	nb_img = 0;
	while (1)
	{
		free(img_to_print);
		path = ft_get_path(nb_img);
		if (!path)
			return (0);
		img_to_print = ft_get_ascii(path);
		free(path);
		printf("%s", img_to_print);
		usleep(75000);
		printf("\e[1;1H\e[2J");
		nb_img++;
		if (nb_img == 11)
			nb_img = 0;
	}
	printf("\e[1;1H\e[2J");
	return (1);
}
