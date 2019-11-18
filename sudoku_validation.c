/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:21:24 by nsance            #+#    #+#             */
/*   Updated: 2019/08/11 14:55:07 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_row(int **grid, int row, int number)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[row][i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_col(int **grid, int col, int number)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col] == number)
			return (0);
		i++;
	}
	return (1);
}

int	check_box(int **grid, int row, int col, int number)
{
	int i;
	int k;
	int box_row;
	int box_col;

	i = 0;
	k = 0;
	box_col = col - (col % 3);
	box_row = row - (row % 3);
	while (i <= 2)
	{
		while (k <= 2)
		{
			if (grid[box_row + i][box_col + k] == number)
			{
				return (0);
			}
			k++;
		}
		i++;
		k = 0;
	}
	return (1);
}

int	ft_check_for_valid(int **grid, int row, int col, int number)
{
	if (check_row(grid, row, number) && check_col(grid, col, number))
	{
		if (check_box(grid, row, col, number))
			return (1);
		return (0);
	}
	else
		return (0);
}
