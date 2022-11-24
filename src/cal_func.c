/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:45 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/24 16:21:28 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

double	f_map(double x, double i_min, double i_max, double o_min, double o_max)
{
	return ((x - i_min) * (o_max - o_min) / (i_max - i_min) + o_min);
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

int	f_julia(t_num *var, int x, int y)
{
	int	index;

	index = 0;
	var->r_ant = f_map(x, 0, W_HEIGHT, -var->scale, var->scale);
	var->i_ant = f_map(y, 0, W_WIDTH, -var->scale, var->scale);
	var->r_const = -0.75;
	var->i_const =  0.07;
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