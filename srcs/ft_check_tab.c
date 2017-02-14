/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:57:28 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/14 18:55:53 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void			ft_init_var(int *i, int *j, int *ind)
{
	*i = 0;
	*j = 0;
	*ind = -1;
}

static void			ft_get_coord(char *s, t_mlx *mlx)
{
	int			i;
	int			j;
	int			ind;

	ft_init_var(&i, &j, &ind);
	mlx->data = (t_data **)malloc(sizeof(t_data *) * mlx->lines);
	while (s[++ind] && i != mlx->lines)
	{
		if (j == 0)
			mlx->data[i] = (t_data *)malloc(sizeof(t_data) * mlx->col);
		if (ft_isdigit(s[ind]) || s[ind] == '-')
		{
			mlx->data[i][j].x = j;
			mlx->data[i][j].y = i;
			mlx->data[i][j].z = ft_atoi(&s[ind]);
			j++;
			if (j == mlx->col)
			{
				i++;
				j = 0;
			}
			while (ft_isdigit(s[ind]) || s[ind] == '-')
				ind++;
		}
	}
}

static void			ft_count_line(char *s, t_mlx *mlx)
{
	int				count;
	int				i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	mlx->lines = count;
}

static void			ft_count_column(char *s, t_mlx *mlx)
{
	int				count;
	int				count_tmp;
	int				i;

	count = 0;
	i = -1;
	count_tmp = 0;
	while (s[++i])
	{
		if (s[i] == '\n' && !count)
			count = count_tmp;
		if (s[i] == '\n' && count != count_tmp && count > 0)
			return ;
		if (s[i] == '\n')
			count_tmp = 0;
		if (ft_isdigit(s[i]) || s[i] == '-')
		{
			count_tmp++;
			while (ft_ishex(s[i]) || s[i] == '-' || s[i] == ',')
				i++;
			i--;
		}
	}
	mlx->col = count;
}

t_mlx				ft_fdf_parsing(char *s)
{
	t_mlx			mlx;

	mlx.col = 0;
	ft_count_line(s, &mlx);
	ft_count_column(s, &mlx);
	if (mlx.col == 0)
	{
		ft_printf("Wrong map | Error on map\n");
		exit(-1);
	}
	ft_get_coord(s, &mlx);
	return (mlx);
}
