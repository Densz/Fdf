/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:06:01 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/14 18:56:32 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char			*read_file(char *argv)
{
	int				fd;
	char			*line;
	char			*tab;
	char			*tmp;

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

int					main(int argc, char **argv)
{
	char			*s;
	t_mlx			mlx;

	s = NULL;
	if (argc != 2)
		ft_printf("usage: fdf input_file\n");
	else
	{
		s = read_file(argv[1]);
		printf("Print tab :\n%s\n", s);
		mlx = ft_fdf_parsing(s);
		printf("y = 2 - x = 3  z = %d\n", mlx.data[2][3].z);
	}
	return (0);
}
