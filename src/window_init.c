/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:34 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/23 11:26:21 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void window_init(t_data *p_mlx)
{
	p_mlx->mlx = mlx_init();
	p_mlx->win = mlx_new_window(p_mlx->mlx, W_WIDTH, W_HEIGHT, "fractal");
	p_mlx->img.mlx_img = mlx_new_image(p_mlx->mlx, W_WIDTH, W_HEIGHT);
	p_mlx->img.addr = mlx_get_data_addr(p_mlx->img.mlx_img, &p_mlx->img.bpp,
	&p_mlx->img.line_len, &p_mlx->img.endian);
}

void var_init(t_num *var)
{
	var->x = 0;
	var->y = 0;
	var->r = 0;
	var->i = 0;
	var->interations = 100;
	var->scale = 1.5;
}