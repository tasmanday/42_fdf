/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:06:53 by tday              #+#    #+#             */
/*   Updated: 2023/10/02 22:52:54 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"
#include "colours.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	read_map(char *file_name, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)ft_calloc(data->height, sizeof(int *));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)ft_calloc(data->width, sizeof(int));
		i++;
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(data->z_matrix[i], line);
		free_null(&line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (fd);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free_null(&line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (fd);
	line = get_next_line(fd);
	width = ft_count_words(line, ' ');
	free_null(&line);
	close(fd);
	return (width);
}

void	fill_matrix(int	*zline, char *line)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	i = 0;
	while (values[i])
	{
		zline[i] = ft_atoi(values[i]);
		free_null(&values[i]);
		i++;
	}
	free_null(values);
}
