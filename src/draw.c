/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:31 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/21 01:24:35 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#define zoom 0.5
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

int draw(t_data *data)
{
	int loop = 0;
	int cor;
	while (data->var.y<W_HEIGHT)
	{
		data->var.x = 0;
		data->var.i = f_map(data->var.y, 0, W_HEIGHT, -1.5, 1.5);
		while (data->var.x<W_WIDTH)
		{
			data->var.r = f_map(data->var.x, 0, W_HEIGHT, -1.5, 1.5);
			cor = 1;
			loop = 0;
			while (++loop < 50)
			{
				data->var.z = pow(data->var.r, 2) - pow(data->var.i, 2);
				data->var.z2 = (2*data->var.r*data->var.i);
				if (data->var.z + data->var.z2 >= 1)
				{
					cor = 0;
					break;
				}
				data->var.r = data->var.z;
				data->var.i = data->var.z2;
			}
			if(cor)
				img_pix_put(&data->img, data->var.x, data->var.y, 0XFF00);
			data->var.x++;
		}
		data->var.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}