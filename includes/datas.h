/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:48:19 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/21 00:36:57 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAS_H
#define DATAS_H

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
	double	z;
	double	z2;
}	t_num;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_num	var;
} t_data;

#endif