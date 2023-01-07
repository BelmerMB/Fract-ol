/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:45 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/07 03:30:07 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

double	f_map(t_map data)
{
	return ((data.x - data.i_min) * (data.o_max - data.o_min)
		/ (data.i_max - data.i_min) + data.o_min);
}

int	f_mandelbrot(t_num *var, int x, int y)
{
	int	index;

	index = 0;
	var->r_ant = f_map((t_map){x, 0, W_HEIGHT, -var->scale, var->scale});
	var->i_ant = f_map((t_map){y, 0, W_HEIGHT, -var->scale, var->scale});
	var->r_const = var->r_ant;
	var->i_const = var->i_ant;
	while (index++ < var->interations)
	{
		var->r = ((var->r_ant * var->r_ant) - (var->i_ant * var->i_ant));
		var->i = (2 * var->r_ant * var->i_ant);
		var->r_ant = var->r + var->r_const;
		var->i_ant = var->i + var->i_const;
		if (var->r_ant + var->i_ant > 4)
			return (index);
	}
	return (0);
}

int	f_julia(t_num *var, int x, int y)
{
	int	index;

	index = 0;
	var->r_ant = f_map((t_map){x, 0, W_HEIGHT, -var->scale, var->scale});
	var->i_ant = f_map((t_map){y, 0, W_HEIGHT, -var->scale, var->scale});
	while (index++ < var->interations)
	{
		var->r = ((var->r_ant * var->r_ant) - (var->i_ant * var->i_ant));
		var->i = (2 * var->r_ant * var->i_ant);
		var->r_ant = var->r + var->r_const;
		var->i_ant = var->i + var->i_const;
		if (var->r_ant + var->i_ant > 4)
			return (index);
	}
	return (0);
}
