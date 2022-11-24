/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:33 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/24 18:30:44 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int handle_key(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
		destroy_all(data);
	else if (keysym == XK_Page_Up)
	{
		data->var.scale -= 0.1;
		f_fractal(data);
	}
	else if (keysym == XK_Page_Down)
	{
		data->var.scale += 0.1;
		f_fractal(data);
	}
	return (0);
}