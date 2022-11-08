/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:58:31 by emetras-          #+#    #+#             */
/*   Updated: 2022/11/08 14:34:48 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"
#include <stdio.h>
#include <math.h>

int print_img(t_data *data);

int main ()
{
	t_data p_mlx;

	p_mlx.mlx =mlx_init();
	p_mlx.win = mlx_new_window(p_mlx.mlx, W_WIDTH, W_HEIGHT, "second window");


	p_mlx.img.mlx_img = mlx_new_image(p_mlx.mlx, W_WIDTH, W_HEIGHT); //crio a imagem
	//pego todas as informações da imagem,, bpp, size line e o endian
	p_mlx.img.addr = mlx_get_data_addr(p_mlx.img.mlx_img, &p_mlx.img.bpp, &p_mlx.img.line_len, &p_mlx.img.endian);
	//retorna endereço do array de pixel da imagem, navego por cada byte por vez "sizeof(char)"
	//cada pixel tem tamanho de bpp
	
	mlx_loop_hook(p_mlx.mlx, &print_img, &p_mlx);
	
	mlx_loop(p_mlx.mlx);

	mlx_destroy_image(p_mlx.win, p_mlx.img.mlx_img);
	mlx_destroy_display(p_mlx.win);
	free(p_mlx.mlx);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int print_img(t_data *data)
{
	int i = 0;

	if (data->win == NULL)
		return (1);
	
	//apenas testes, aqui entro com as funções para desenhar meus fractais
	while(i <200)
	{
		// if(pow(i, 2) >= W_WIDTH || pow(i, 2) >= W_HEIGHT)
		// 	break;
		img_pix_put(&data->img, i, (W_HEIGHT)-i-1, 0xFF00);
		// img_pix_put(&data->img, i+(pow(i, 2)), (W_HEIGHT)-pow(i,2)-1, 0xFF00);
		i++;
	}
	while(i <300)
	{
		if(i >= W_WIDTH || i >= W_HEIGHT)
			break;
		img_pix_put(&data->img, i, i-(W_HEIGHT-120), 0xFF00);
		// img_pix_put(&data->img, i+(pow(i, 2)), (W_HEIGHT)-pow(i,2)-1, 0xFF00);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}