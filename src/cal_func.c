/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:45 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/22 12:58:39 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	f_map(double x, double i_min, double i_max, double o_min, double o_max)
{
	return ((x - i_min) * (o_max - o_min) / (i_max - i_min) + o_min);
}