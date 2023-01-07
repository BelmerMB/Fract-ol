/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:48:19 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/07 02:30:55 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAS_H
# define DATAS_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	double	x;
	double	y;
	double	r;
	double	i;
	double	r_ant;
	double	i_ant;
	double	r_const;
	double	i_const;
	int		interations;
	double	scale;
}	t_num;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_num	var;
	int		(*fractal_ptr)(t_num *var, int x, int y);
}	t_data;

typedef struct s_map
{
	double	x;
	double	i_min;
	double	i_max;
	double	o_min;
	double	o_max;
}	t_map;

#endif