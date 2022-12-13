/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:44:59 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/13 13:30:25 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_data	p_mlx;

	args_check(&p_mlx, argc, argv);
	window_init(&p_mlx);
	var_init(&p_mlx.var);
	handle_hooks(&p_mlx);
	mlx_loop(p_mlx.mlx);
}
