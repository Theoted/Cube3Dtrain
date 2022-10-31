/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:47:57 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/25 15:42:37 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int draw_sensor(t_mlx_data *data, int nb);

float radiant;

void my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int move_up(t_mlx_data *data)
{
    int x;
    int y;

    x = data->char_pos.px + 22;
    y = data->char_pos.py + 22;
    data->char_pos.py -= 10;
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    draw_sensor(data, 1);
    return 0;
}

int move_back(t_mlx_data *data)
{
    int x;
    int y;

    x = data->char_pos.px + 22;
    y = data->char_pos.py + 22;
    data->char_pos.py += 10;
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    draw_sensor(data, 1);
    return 0;
}

int move_right(t_mlx_data *data)
{
    data->char_pos.pa -= 1.5;
    printf("%f\n", data->char_pos.pa);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_map(data);
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    draw_sensor(data, 10);
    return 0;
}

int draw_sensor(t_mlx_data *data, int nb)
{
    int px;
    int py;
    int px1;
    int py1;
    int dx;
    int dy;
    int i;
    double s_r;

    i = 0;
    px = data->char_pos.px + 10;
    py = data->char_pos.py + 10;
    px1 = data->char_pos.px + 10;
    py1 = data->char_pos.py + 552;
    s_r = data->char_pos.pa;
    while (i < nb)
    {
        radiant = s_r * (PI/180);
        dx = ((cos((double)radiant) *  (px1 - px)) - (sin((double)radiant) * (py1 - py)) + px);
        dy = ((sin((double)radiant) *  (px1 - px)) - (cos((double)radiant) * (py1 - py)) + py);
        if (!_line_line_intersection(data, 200, 200, 550, 550, dx, dy))
            if (!_line_line_intersection(data, 63, 634, 768, 768, dx, dy))  
                if (!_line_line_intersection(data, 983, 183, 709, 409, dx, dy))
                    ;
        if (data->sensor.c_x != -1 && data->sensor.c_y != -1)
        {
            dx = data->sensor.c_x;
            dy = data->sensor.c_y;
        }
        if (dy < 0)
            dy = 0;
        s_r += 2.5;
        _bresenham(data, px, py, dx, dy);
        data->sensor.c_x = -1;
        data->sensor.c_y = -1;
        i++;
    }
    return (0);
}

int move_left(t_mlx_data *data)
{
    data->char_pos.pa += 1.5;
    draw_map(data);
    draw_player1(data, data->char_pos.px, data->char_pos.py);
    // mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_sensor(data, 10);
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
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
    return (0);
}

int draw_walls(t_mlx_data *data)
{
    _bresenham(data, 200, 200, 550, 550);
    _bresenham(data, 63, 634, 768, 768);
    _bresenham(data, 983, 183, 709, 409);
    return 0;
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