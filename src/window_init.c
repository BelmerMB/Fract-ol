/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:34 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/02 20:22:58 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	window_init(t_data *p_mlx)
{
	p_mlx->mlx = mlx_init();
	if (!p_mlx->mlx)
		exit(EXIT_FAILURE);
	p_mlx->win = mlx_new_window(p_mlx->mlx, W_WIDTH, W_HEIGHT, "fractal");
	if (!p_mlx->win)
		exit(EXIT_FAILURE);
	p_mlx->img.mlx_img = mlx_new_image(p_mlx->mlx, W_WIDTH, W_HEIGHT);
	if (!p_mlx->img.mlx_img)
		exit(EXIT_FAILURE);
	p_mlx->img.addr = mlx_get_data_addr(p_mlx->img.mlx_img, &p_mlx->img.bpp,
			&p_mlx->img.line_len, &p_mlx->img.endian);
}

void	var_init(t_num *var)
{
	var->x = 0;
	var->y = 0;
	var->r = 0;
	var->i = 0;
	var->interations = 100;
	var->scale = 1.5;
}
