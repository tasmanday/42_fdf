/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:45 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:51:32 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	loop_function(t_data *data)
{
	loop_movement(data);
	update_frame(data);
	return (0);
}

int	update_frame(t_data *data)
{
	t_img	*img;

	img = &(data->img[data->current_img]);
	fill_background(data, 1920, 1080, data->background_colour);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	data->current_img = (data->current_img + 1) % 2;
	return (0);
}

void	fill_background(t_data *data, int width, int height, int colour)
{
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mxl_pixel_put(data, x, y, colour);
			x++;
		}
		y++;
	}
}

void	my_mxl_pixel_put(t_data *data, float fx, float fy, int colour)
{
	int		x;
	int		y;
	char	*pixel;
	t_img	*img;

	x = round(fx);
	y = round(fy);
	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	img = &data->img[data->current_img];
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = colour;
}
