/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:29:03 by tchaves           #+#    #+#             */
/*   Updated: 2024/03/08 09:29:05 by tchaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->x_angle);
	*y = (*x + *y) * sin(data->y_angle) - z;
}

void	change_color(t_fdf *data)
{
	if (data->color == RED)
		data->color = BLUE;
	else if (data->color == BLUE)
		data->color = GREEN;
	else if (data->color == GREEN)
		data->color = YELLOW;
	else if (data->color == YELLOW)
		data->color = CYAN;
	else if (data->color == CYAN)
		data->color = PURPLE;
	else if (data->color == PURPLE)
		data->color = RED;
}

void	put_pixel(int x, int y, t_fdf *data)
{
	if (data->z1 > 0 || data->z2 > 0)
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, data->color);
	else if (data->z1 < 0 || data->z2 < 0)
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, WHITE);
	else
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, WHITE);
}

void	put_instructions(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 20, 0xFFFFFF, "Zoom out/zoom in: '+' - '-'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 40, 0xFFFFFF, "Movement: arrows");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 60, 0xFFFFFF, "Rotate left/right: 'z' - 'x'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 80, 0xFFFFFF, "Translation x_angle/y_angle: 'w' - 's'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 100, 0xFFFFFF, "Translation both x_angle/y_angle: 'q' - 'e'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 120, 0xFFFFFF, "Change view: 'i' - 'p'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 140, 0xFFFFFF, "Change color: 'c'");
	mlx_string_put(data->mlx_ptr, data->img_ptr, \
	10, 160, 0xFFFFFF, "Quit Program: 'ESC'");
}

void	display_map(t_fdf *data)
{
	t_pos	p;

	put_instructions(data);
	p.y = 0;
	while (p.y < data->height)
	{
		p.x = 0;
		while (p.x < data->width)
		{
			if (!(p.x == data->width - 1))
				bresenham(p, p.x + 1, p.y, data);
			if (!(p.y == data->height - 1))
				bresenham(p, p.x, p.y + 1, data);
			p.x++;
		}
		p.y++;
	}
}
