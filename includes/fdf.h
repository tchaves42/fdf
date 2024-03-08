/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:30:51 by tchaves           #+#    #+#             */
/*   Updated: 2024/03/08 09:30:54 by tchaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define HEIGHT 1920
# define WIDTH 1080
# define ARROW_LEFT 0xFF51
# define ARROW_RIGHT 0xff53
# define ARROW_DOWN 0xff54
# define ARROW_UP 0xff52
# define KEY_W	0x0077
# define KEY_S	0x0073
# define KEY_Q	0x0071
# define KEY_E	0x0065
# define KEY_I	0x0069
# define KEY_C	0x0063
# define KEY_P	0x0070
# define KEY_F	0x0066
# define KEY_Z	0x007a
# define KEY_X	0x0078

# define WHITE	0xffffff
# define RED	0xff0000
# define BLUE	0x0000FF
# define GREEN	0x00FF00
# define YELLOW	0xFFF700
# define CYAN	0x00FFFB
# define PURPLE	0x6100FF

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;

	int		zoom;
	int		color;
	double	x_angle;
	double	y_angle;
	int		isometric_flag;
	int		rotate_left_flag;
	int		rotate_rigth_flag;
	int		mv_x;
	int		mv_y;

	int		z1;
	int		z2;

	void	*mlx_ptr;
	void	*img_ptr;
	float	y_diff;
	int		max;
}	t_fdf;

void	control_zoom(t_pos *p, float *x2, float *y2, t_fdf *data);
void	control_pos(t_pos *p, float *x2, float *y2, t_fdf *data);
void	controls(t_pos *p, float *x2, float *y2, t_fdf *data);
void	bresenham(t_pos p, float x2, float y2, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	get_map(char *file_name, t_fdf *data);
void	put_pixel(int x, int y, t_fdf *data);
void	display_map(t_fdf *data);
void	ft_free(t_fdf *data);
void	defaults(t_fdf *data);
int		get_infos(char *file_name, t_fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		destroy_fdf(t_fdf *data);
int		get_width(char *line);
char	*count_height(int fd, int *height);

void	rotate_left(float *x, float *y);
void	rotate_right(float *x, float *y);
void	change_r_right(t_fdf *data);
void	change_r_left(t_fdf *data);

void	change_color(t_fdf *data);
int		moves(int key, t_fdf *data);
void	arrows(int key, t_fdf *data);
void	zoom(int key, t_fdf *data);
void	translation(int key, t_fdf *data);
void	rotation(int key, t_fdf *data);
void	views(int key, t_fdf *data);

#endif
