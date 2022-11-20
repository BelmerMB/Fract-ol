/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:45 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/14 11:31:01 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	f_map(double x, double in_min, double in_max, double out_min, double out_max) {
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}