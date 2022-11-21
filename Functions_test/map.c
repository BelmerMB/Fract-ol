/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:32:34 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/20 23:01:11 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	f_map(double x, double in_min, double in_max, double out_min, double out_max);

int main()
{
	int x = 0;
	while (++x <= 50)
	{
		printf("Original: %d Map: %f, O_denovo %f \n", x, f_map(x, 0, 600, -2.0, 2.0), f_map(f_map(x, 0, 600, -2.0, 2.0), -2.0, 2.0, 0, 600));	
	}
	return (0);
}

double	f_map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}