/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:21:47 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:45:58 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

typedef unsigned char			t_uchar;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_img;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		colour;
}			t_point;

typedef struct s_delta
{
	int		dx;
	int		dy;
	int		steps;
	float	x_incr;
	float	y_incr;
	float	slope;
	float	frac_x;
	float	frac_y;
}			t_delta;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img[2];
	int		current_img;
	int		background_colour;
	int		height;
	int		width;
	int		**z_matrix;
	int		z_min;
	int		z_max;
	int		colour;
	int		shift_x;
	int		shift_y;
	float	zoom;
	float	altitude;
	int		is_iso;
	int		is_wu;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	float	center_x;
	float	center_y;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_p;
	int		key_l;
	int		key_u;
	int		key_i;
	int		key_h;
	int		key_j;
	int		key_b;
	int		key_n;
	int		key_less;
	int		key_more;
}				t_data;

typedef struct s_value
{
	t_uchar	t;
	t_uchar	r;
	t_uchar	g;
	t_uchar	b;
}				t_value;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum e_colour_channel
{
	T = 3,
	R = 2,
	G = 1,
	B = 0
};

typedef enum e_colour_channel	t_colour_channel;

/* initialisation */
void	init_data(t_data *data);
void	init_keys(t_data *data);
void	set_z_min_max(t_data *data);
int		init_img(t_data *data);

/* read map */
void	read_map(char *file_name, t_data *data);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	fill_matrix(int	*zline, char *line);

/* key down controls */
int		key_down_hook(int keycode, t_data *data);
int		k_d_move_zoom(int keycode, t_data *data);
int		k_d_angles_altitude(int keycode, t_data *data);

/* key up controls */
int		key_up_hook(int keycode, t_data *data);
int		k_u_move_zoom(int keycode, t_data *data);
int		k_u_angles_altitude(int keycode, t_data *data);
int		toggle_lines(int keycode, t_data *data);
int		toggle_rotation(int keycode, t_data *data);

/* events */
int		loop_movement(t_data *data);
void	loop_move_zoom(t_data *data);
void	loop_angles_altitude(t_data *data);
int		close_window(t_data *data);
int		close_button_hook(t_data *data);

/* frame/image management */
int		loop_function(t_data *data);
int		update_frame(t_data *data);
void	fill_background(t_data *data, int width, int height, int colour);
void	my_mxl_pixel_put(t_data *data, float x, float y, int colour);

/* colours */
t_value	get_all_values(int trgb);
t_uchar	get_channel(int trgb, t_colour_channel channel);
int		create_trgb(t_uchar t, t_uchar r, t_uchar g, t_uchar b);

/* gradients */
int		set_point_colour(int x, int y, t_data *data);
int		interpolate_colour(int start_colour, int end_colour, float f);
void	blend_colours(t_value start, t_value end, float f, int *result);

/* bresenham */
void	bresenham(t_point start, t_point end, t_data *data);
void	zoom_and_rotate(t_point *pt, t_data *data);
t_delta	calc_t_delta(t_point start, t_point end);

/* wu */
void	wu(t_point start, t_point end, t_data *data);
void	update_points(t_point *start, t_point *end, t_data *data);
void	swap_points(t_point *start, t_point *end);
t_point	fill_plot_point(float x, float y, int colour);
void	plot(t_point pt, float f, t_data *data);

/* wu lines*/
void	wu_line_hori(t_point start, t_point end, t_delta delta, t_data *data);
void	wu_line_vert(t_point start, t_point end, t_delta delta, t_data *data);
void	wu_line_vpos(t_point start, t_point end, t_delta delta, t_data *data);
void	wu_line_vneg(t_point start, t_point end, t_delta delta, t_data *data);

/* grid */
void	draw_grid(t_data *data);
void	grid_br(int x, int y, t_data *data);
void	grid_wu(int x, int y, t_data *data);
t_point	calc_t_point(int x, int y, t_data *data);

/* isometric/rotate */
void	to_iso(t_point *pt);
void	rotate_axis(t_point *pt, t_data *data);
void	rotate_x(t_point *pt, t_data *data);
void	rotate_y(t_point *pt, t_data *data);
void	rotate_z(t_point *pt, t_data *data);

/* unused */
/* int	set_channel(int trgb, t_colour_channel channel, t_uchar n);
int		mouse_move_hook(int x, int y, t_data *data); */

#endif