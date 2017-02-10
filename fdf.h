/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:06:59 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/10 16:27:41 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "./libft/libft.h"
# include "mlx.h"

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

#endif