/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:06:01 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/10 16:56:11 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_count_line(char *s)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int			ft_count_column(char *s)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == ' ')
		{
			count++;
			while (s[i] == ' ')
				i++;
		}
		i++;
	}
	return (count + 1);
}

int			**ft_get_coord(char *s)
{
	int			count_line;
	int			count_column;
	int			**coord;
	int			i;
	int			j;

	i = 0;
	j = 0;
	count_line = ft_count_line(s);
	count_column = ft_count_column(s);
	printf("Count line = %d\n", count_line);
	printf("Count column = %d\n", count_column);
	coord = (int **)malloc(sizeof(int *) * count_line);
	return (coord);
}

char		*read_file(char *argv)
{
	int			fd;
	char		*line;
	char		*tab;
	char		*tmp;

	tab = ft_strnew(0);
	if (!(fd = open(argv, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = tab;
		tab = ft_strjoin(tmp, line);
		free(tmp);
		tmp = tab;
		tab = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	return (tab);
}

int			main(int argc, char **argv)
{
	char		*s;
	int			**coord;

	s = NULL;
	coord = NULL;
	if (argc != 2)
		ft_printf("-> Il manque le fichier\n");
	else
	{
		s = read_file(argv[1]);
		coord = ft_get_coord(s);
		ft_printf("%s", s);
	}
	return (0);
}