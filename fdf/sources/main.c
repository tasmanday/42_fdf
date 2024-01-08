/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:47:12 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:50:34 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	init_data(data);
	read_map(argv[1], data);
	set_z_min_max(data);
	if (init_img(data) == -1)
		return (-1);
	mlx_hook(data->win, ON_KEYDOWN, 0, key_down_hook, data);
	mlx_key_hook(data->win, key_up_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0, close_button_hook, data);
	mlx_loop_hook(data->mlx, loop_function, data);
	mlx_loop(data->mlx);
}
