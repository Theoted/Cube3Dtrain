/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:47:57 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/06 15:08:26 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int move_up(t_mlx_data *data)
{
    data->char_pos.py -= 10;
    mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->char_pos.px, data->char_pos.py, 0xFFFFFF);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    return 0;
}

int deal_key(int key, t_mlx_data *data)
{
    if (key == 13)
        move_up(data);
    // if (key == 2)
    //     move_right(data);
    // if (key == 1)
    //     move_left(data);
    // if (key == 0)
    //     move_back(data);
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    t_mlx_data  data;
    int         i;

    i = 0;
    data.matrix = NULL;
    data.matrix = init_matrix_test(data.matrix);
    init_mlx(&data);
    draw_map(&data);
    mlx_key_hook(data.mlx_win, deal_key, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}