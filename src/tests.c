/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:23:59 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/24 10:32:45 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    print_matrix(char **matrix)
{
    int i;
    int j;

    i = -1;
    while (matrix[++i])
    {
        j = -1;
        while (matrix[i][++j])
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

char    **init_matrix_test(char **matrix)
{
    int i;

    i = 0;
    matrix = malloc(sizeof(char *) * 11);
    matrix[10] = 0;
    matrix[0] = ft_strdup("111111111111");
    matrix[9] = ft_strdup("111111111111");
    while (++i < 9)
        matrix[i] = ft_strdup("100000000001");
    free(matrix[4]);
    matrix[4] = ft_strdup("10000N000001");
    // print_matrix(matrix);
    return (matrix);
}