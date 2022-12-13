/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:11:31 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/13 13:43:52 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void args_check(t_data *data, int argc, char **argv)
{
	if(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		data->fractal_ptr = f_mandelbrot;
	}
	else
	{
		ft_printf("Invalid arguments\n");
		exit(0);
	}
}