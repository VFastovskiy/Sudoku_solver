/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:21:06 by nsance            #+#    #+#             */
/*   Updated: 2019/08/11 18:23:59 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_find_unassigned(int **grid, int *row, int *col)
{
	if (!grid)
		return (-1);
	while (*row < 9)
	{
		while (*col < 9)
		{
			if (grid[*row][*col] == 0)
			{
				return (1);
			}
			*col = *col + 1;
		}
		*row = *row + 1;
		*col = 0;
	}
	return (0);
}

int	ft_solve(int **grid)
{
	int row;
	int col;
	int num;
	int *p_row;
	int *p_col;

	p_row = &row;
	p_col = &col;
	row = 0;
	col = 0;
	num = 1;
	if (!ft_find_unassigned(grid, p_row, p_col))
		return (1);
	while (num <= 9)
	{
		if (ft_check_for_valid(grid, row, col, num) == 1)
		{
			grid[row][col] = num;
			if (ft_solve(grid))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	**ft_transform_grid(char **grid)
{
	int **i_grid;
	int i;
	int k;

	i = 0;
	k = 0;
	i_grid = (int **)malloc(sizeof(int*) * 9);
	while (i < 9)
	{
		i_grid[i] = (int*)malloc(sizeof(int) * 9);
		while (k < 9)
		{
			if (grid[i + 1][k] == EMPTY)
				i_grid[i][k] = 0;
			else
			{
				i_grid[i][k] = (grid[i + 1][k] - '0');
			}
			k++;
		}
		k = 0;
		i++;
	}
	return (i_grid);
}

int	ft_check_extra_solutions(int **grid)
{
	int i;
	int k;
	int cnt;

	i = 0;
	k = 0;
	cnt = 0;
	while (i < 9)
	{
		while (k < 9)
		{
			if (grid[i][k] > 0 && grid[i][k] < 10)
				cnt++;
			k++;
		}
		i++;
		k = 0;
	}
	if (cnt < 17)
		return (0);
	return (1);
}
