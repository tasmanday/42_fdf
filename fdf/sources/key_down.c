/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:26:18 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:52:25 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	key_down_hook(int keycode, t_data *data)
{
	if (k_d_move_zoom(keycode, data))
		return (0);
	else if (k_d_angles_altitude(keycode, data))
		return (0);
	else if (keycode == 53)
		close_window(data);
	else
		return (0);
	return (0);
}

int	k_d_move_zoom(int keycode, t_data *data)
{
	if (keycode == 13)
		data->key_w = 1;
	else if (keycode == 1)
		data->key_s = 1;
	else if (keycode == 0)
		data->key_a = 1;
	else if (keycode == 2)
		data->key_d = 1;
	else if (keycode == 35)
		data->key_p = 1;
	else if (keycode == 37)
		data->key_l = 1;
	else
		return (0);
	return (1);
}

int	k_d_angles_altitude(int keycode, t_data *data)
{
	if (keycode == 32)
		data->key_u = 1;
	else if (keycode == 34)
		data->key_i = 1;
	else if (keycode == 4)
		data->key_h = 1;
	else if (keycode == 38)
		data->key_j = 1;
	else if (keycode == 11)
		data->key_b = 1;
	else if (keycode == 45)
		data->key_n = 1;
	else if (keycode == 43)
		data->key_less = 1;
	else if (keycode == 47)
		data->key_more = 1;
	else
		return (0);
	return (1);
}
