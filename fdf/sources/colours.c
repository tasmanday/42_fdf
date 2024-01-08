/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:08 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:51:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	create_trgb(t_uchar t, t_uchar r, t_uchar g, \
t_uchar b)
{
	return (*(int *)(t_uchar [4]){b, g, r, t});
}

t_uchar	get_channel(int trgb, t_colour_channel channel)
{
	return (((t_uchar *)&trgb)[channel]);
}

t_value	get_all_values(int trgb)
{
	t_value	channels;

	channels.t = get_channel(trgb, T);
	channels.r = get_channel(trgb, R);
	channels.g = get_channel(trgb, G);
	channels.b = get_channel(trgb, B);
	return (channels);
}

/* int	set_channel(int trgb, t_colour_channel channel, t_uchar n)
{
	((t_uchar *)&trgb)[channel] = n;
	return (trgb);
} */
