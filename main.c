/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:44:59 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/10 10:58:13 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include <stdio.h>

int main()
{
	t_data	p_mlx;

	window_init(&p_mlx);
	//mlx_loop_hook();
	mlx_hook(p_mlx.win, KeyPress, KeyPressMask, handle_key, &p_mlx);
	mlx_loop(p_mlx.mlx);
}
