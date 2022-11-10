/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:46:26 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/10 10:48:21 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
# include <X11/X.h>

# define W_WIDTH 600
# define W_HEIGHT 400

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
} t_data;

int		handle_key(int keysym, t_data *data);
void	window_init(t_data *p_mlx);

#endif