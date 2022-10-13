/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:47:57 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/07 12:53:35 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double radiant;

int move_up(t_mlx_data *data)
{
    int x1;
    int y1;

    x1 = 0;
    y1 = 0;
    data->char_pos.py -= 10 - data->char_pos.pa;
    x1 = data->char_pos.px + 22 + data->char_pos.pa;
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    _bresenham(data, data->char_pos.px + 22, data->char_pos.py + 22,
        x1, data->char_pos.py - 150);
    return 0;
}

int move_back(t_mlx_data *data)
{
    int x1;
    int y1;

    x1 = 0;
    y1 = 0;
    data->char_pos.py += 10 + data->char_pos.pa;
    x1 = data->char_pos.px + 22 + data->char_pos.pa;
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    _bresenham(data, data->char_pos.px + 22, data->char_pos.py + 22,
        x1, data->char_pos.py - 150);
    return 0;
}

int move_right(t_mlx_data *data)
{
    int x1;
    int y1;

    x1 = 0;
    y1 = 0;
    data->char_pos.pa += PI/2;
    x1 = data->char_pos.px + 22 + data->char_pos.pa;
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    _bresenham(data, data->char_pos.px + 22, data->char_pos.py + 22,
        x1, data->char_pos.py - 150);
    return 0;
}

// int move_left(t_mlx_data *data)
// {
//     int x1;
//     int y1;

//     x1 = 0;
//     y1 = 0;
//     data->char_pos.pa -= 1;
//     if (data->char_pos.pa < 0)
//         data->char_pos.pa += 2*PI;
//     data->char_pos.pdx=cos(data->char_pos.pa) * 5;
//     data->char_pos.pdy=sin(data->char_pos.pa) * 5;
    
//     printf("pa = %d\n", data->char_pos.pa);
//     x1 = data->char_pos.px + 22 - data->char_pos.pa;
//     draw_player1(data, data->char_pos.px, data->char_pos.py);
//     mlx_clear_window(data->mlx_ptr, data->mlx_win);
//     draw_map(data);
//     _bresenham(data, data->char_pos.px + 22, data->char_pos.py + 22,
//         x1, data->char_pos.py - 150);
//     return 0;
// }

int move_left(t_mlx_data *data)
{
    int px;
    int py;
    int px1;
    int py1;
    int dx;
    int dy;

    data->char_pos.pa -= 1;
    px = data->char_pos.px + 22;
    py = data->char_pos.py + 22;
    px1 = data->char_pos.px + 22 + data->char_pos.pa;
    py1 = data->char_pos.px + 22;
    radiant = 20 * (PI/180);

    dx = ((cos(radiant) *  (px - px1)) - (sin(radiant) * (py - py1)) + px1);
    dy = ((sin(radiant) *  (px - px1)) - (cos(radiant) * (py - py1)) + py1);

    printf("radiant = %f\n", radiant);
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    _bresenham(data, px, py,
        dx, dy);
    return 0;
}

int deal_key(int key, t_mlx_data *data)
{
    if (key == 13)
        move_up(data);
    if (key == 2)
        move_right(data);
    if (key == 1)
        move_back(data);
    if (key == 0)
        move_left(data);
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
    // mlx_key_hook(data.mlx_win, deal_key, &data);
    mlx_hook(data.mlx_win, 2, 1L << 0, deal_key, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}