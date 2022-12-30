/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:33 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/13 14:36:38 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	destroy_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static int	handle_key(int key, t_data *data)
{
	if(key == ESC)
		destroy_all(data);
	else 
	return (0);
}

static int	handle_mouse(int key, int x, int y, t_data *data)
{
	if (key == SCROLL_DOWN && data->var.scale <= 5.0)
	{
		data->var.scale *= 1.1;
		f_fractal(data);
	}
	else if (key == SCROLL_UP && data->var.scale >= 0.001)
	{
		data->var.scale *= 0.9;
		f_fractal(data);
	}
	return (0);
}

int	handle_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, destroy_all, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop_hook(data->mlx, f_fractal, data);
	return (0);
}