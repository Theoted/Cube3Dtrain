/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:53:47 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/25 11:07:47 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1200, 800, "cub3D");
	data->img = mlx_new_image(data->mlx_ptr, 1200, 800);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->char_pos.px = -1;
	data->char_pos.py = -1;
	data->char_pos.pa = 0;
	data->init = 0.0;
	data->sensor.c_x = -1;
	data->sensor.c_y = -1;
}
