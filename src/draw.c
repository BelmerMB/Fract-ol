/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:31 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/23 11:28:55 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#define zoom 0.5

int	f_mandelbrot(t_num *var, int x, int y);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int f_fractal(t_data *data)
{
	int	cor;
	while (data->var.y++ < W_HEIGHT) //depois analiso com y=-1
	{
		data->var.x = 0;
		while (data->var.x++ < W_WIDTH)
		{
			cor = f_mandelbrot(&data->var, data->var.x, data->var.y);
			if(cor)
				img_pix_put(&data->img, data->var.x, data->var.y, f_map(cor, 0,49,50,0XFF));
			else
				img_pix_put(&data->img, data->var.x, data->var.y, 0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	f_mandelbrot(t_num *var, int x, int y)
{
	int	index;

	index = 0;
	var->r_ant = f_map(x, 0, W_HEIGHT, -var->scale, var->scale);
	var->i_ant = f_map(y, 0, W_WIDTH, -var->scale, var->scale);
	var->r_const = var->r_ant;
	var->i_const = var->i_ant;
	while (index++ < var->interations)
	{
		var->r = ((var->r_ant * var->r_ant) - (var->i_ant * var->i_ant));
		var->i = (2 * var->r_ant * var->i_ant);
		var->r_ant = var->r + var->r_const;
		var->i_ant = var->i + var->i_const;
		if (var->r_ant+var->i_ant > 4)
			return (index);
	}
	return (0);
}