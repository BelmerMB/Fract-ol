/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:31 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/07 03:22:24 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	f_fractal(t_data *data)
{
	int	color;

	data->var.y = 0;
	while (data->var.y++ < W_HEIGHT)
	{
		data->var.x = 0;
		while (data->var.x++ < W_WIDTH)
		{
			color = data->fractal_ptr(&data->var, data->var.x, data->var.y);
			if (color)
				img_pix_put(&data->img, data->var.x, data->var.y,
					f_map((t_map){color, 0, 49, 50, 0XFF}));
			else
				img_pix_put(&data->img, data->var.x, data->var.y, 0);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}
