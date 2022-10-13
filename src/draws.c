/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:40:23 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/07 11:06:02 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void    draw_player_vector(t_data data, int x, int y, int xp, int yp)
// {
//     int i;
//     int j;

//     i = -1;
//     while ()
// }

void    draw_player1(t_mlx_data *data, int x, int y)
{
    int i;
    int j;
    int xx;

    i = -1;
    while (++i < 45)
    {
        j = -1;
        xx = x;
        while (++j < 45)
        {
            mlx_pixel_put(data->mlx_ptr, data->mlx_win, xx, y, 0xFF0000);
            xx++;
        }
        y++;
    }
}

void    draw_player(t_mlx_data *data, int x, int y)
{
    int i;
    int j;
    int xx;
    
    i = -1;
    y *= 100;
    y += 45;
    x *= 100;
    data->char_pos.px = x + 45;
    data->char_pos.py = y;
    while (++i < 45)
    {
        xx = x;
        xx += 45;
        j = -1;
        while (++j < 45)
        {
            mlx_pixel_put(data->mlx_ptr, data->mlx_win, xx, y, 0xFF0000);
            xx++;
        }
        y++;
    }
}

void    put_pixel_y(t_mlx_data *data, int x, int y)
{
    int i;
    int j;

    i = -1;
    j = -1;
    x *= 100;
    while (++i < 10000)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0x808080);
        y++;
    }
}

void    put_pixel_x(t_mlx_data *data, int x, int y)
{
    int i;
    int j;

    i = -1;
    j = -1;
    x *= 100;
    y *= 100;
    while (++i < 100)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0x808080);
        x++;
    }
}

void    draw_map(t_mlx_data *data)
{
    int     y;
    int     x;

    y = -1;
    while (data->matrix[++y])
    {
        x = -1;
        while (data->matrix[y][++x])
        {
            if (y == 0)
                put_pixel_y(data, x, y);
            put_pixel_x(data, x, y);
            if (data->matrix[y][x] == 'N' && data->init == 0)
            {
                draw_player(data, x, y);
                data->init = 1;
                data->char_pos.px = ((x * 100) + 45);
                data->char_pos.py = ((y * 100) + 45);
                mlx_pixel_put(data->mlx_ptr, data->mlx_win, ((x * 100) + 45), ((y * 100) + 45), 0xFFFFFF);
            }
        }
    }
}
