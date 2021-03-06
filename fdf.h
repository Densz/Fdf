/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:06:59 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/14 18:56:54 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "./libft/libft.h"
# include "mlx.h"

typedef struct		s_data
{
	int				x;
	int				y;
	int				z;
}					t_data;

typedef struct 		s_mlx
{
	int				lines;
	int				col;
	void			*mlx;
	void			*win;
	t_data			**data;
}					t_mlx;

t_mlx				ft_fdf_parsing(char *s);

#endif