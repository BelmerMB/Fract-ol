/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:46:26 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/24 18:25:36 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>
#include "./datas.h"
#include <unistd.h>
#include <stdio.h>

# define W_WIDTH 800
# define W_HEIGHT 800

int		handle_key(int keysym, t_data *data);
int		f_fractal(t_data *data);
int		f_mandelbrot(t_num *var, int x, int y);
int		f_julia(t_num *var, int x, int y);
void	window_init(t_data *p_mlx);
void	var_init(t_num *var);
double	f_map(double x, double i_min, double i_max, double o_min, double o_max);

#endif