/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:46:26 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/13 11:56:15 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "./datas.h"
#include "../printf/header/ft_printf.h"

# define ESC 65307
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define W_WIDTH 800
# define W_HEIGHT 800

int		f_fractal(t_data *data);
int		f_mandelbrot(t_num *var, int x, int y);
int		f_julia(t_num *var, int x, int y);
void	window_init(t_data *p_mlx);
void	var_init(t_num *var);
double	f_map(double x, double i_min, double i_max, double o_min, double o_max);
int		handle_hooks(t_data *data);

#endif
