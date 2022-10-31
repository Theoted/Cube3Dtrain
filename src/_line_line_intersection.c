/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _line_line_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:54:25 by theodeville       #+#    #+#             */
/*   Updated: 2022/10/25 11:50:40 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int _line_line_intersection(t_mlx_data *data,
    double x1, double y1, double x2, double y2,
    double x4, double y4)
{
    double x3, y3, den;
    double px1, py1;
    double c_x; // collision points
    double c_y; // collision points
    double t, u;
    double radiant = data->char_pos.pa * (PI / 180);

    x3 = data->char_pos.px + 22;
    y3 = data->char_pos.py + 22;
    px1 = data->char_pos.px + 22;
    py1 = data->char_pos.py + 552;
    if (y4 < 0)
        y4 = 0;
    den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (den == 0)
        return 0;
    t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
    u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / den;
    if (t > 0 && t < 1  && u > 0)
    {
        data->sensor.c_x = x1 + t * (x2 - x1);
        data->sensor.c_y = y1 + t * (y2 - y1);
        return (1);
    }
    else
        return (0);
}