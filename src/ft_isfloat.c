/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:50:40 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/29 13:08:25 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_isnumber(const char *str)
{
	int	verify;

	verify = 0;
	if (str[ft_strlen(str) - 1] == '.')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '.')
		return (0);
	while (*str)
	{
		if (*str == '.')
			verify++;
		if (verify > 1)
			return (0);
		if (!ft_isdigit(*str) && *str != '.' && *str)
			return (0);
		str++;
	}
	return (1);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	decimal;

	sign = 1;
	result = 0;
	decimal = 0.1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str++))
		result *= 10 + (*str - '0');
	while (ft_isdigit(*str))
	{
		result += (*str++ - '0') * decimal;
		decimal /= 10;
	}
	return (result * sign);
}
