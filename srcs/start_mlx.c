/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:00:35 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/14 18:14:16 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			start_mlx(t_map map)
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1200, 1200, "FDF");
	trace_line(map, mlx);
	put_dot(map, mlx);
	mlx_loop(mlx.mlx);
	return (1);
}
