/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:11:31 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/07 03:34:49 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	erro_msg(void);

void	args_check(t_data *data, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		data->fractal_ptr = f_mandelbrot;
	}
	else if ((argc == 4) && (!ft_strncmp(argv[1], "julia", 6)))
	{
		if (ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
		{
			data->fractal_ptr = f_julia;
			data->var.r_const = ft_atof(argv[2]);
			data->var.i_const = ft_atof(argv[3]);
		}
		else
			erro_msg();
	}
	else
		erro_msg();
}

static void	erro_msg(void)
{
	ft_printf("\033[0;31mInvalid arguments\033[0m\n");
	ft_printf("Try: \"\033[0;32mmandelbrot\033[0m\"\n");
	ft_printf("Or:  \"\033[0;32mjulia -0.8 0.156\033[0m\" or others values\n");
	exit(0);
}
