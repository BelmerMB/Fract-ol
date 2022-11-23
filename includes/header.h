/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:46:26 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/23 10:17:27 by emetras-         ###   ########.fr       */
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

# define W_WIDTH 600
# define W_HEIGHT 600

int		handle_key(int keysym, t_data *data);
int		f_fractal	(t_data *data);
void	window_init(t_data *p_mlx);
void	var_init(t_num *var);
double	f_map(double x, double i_min, double i_max, double o_min, double o_max);

#endif