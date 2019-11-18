/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:24:36 by nsance            #+#    #+#             */
/*   Updated: 2019/08/11 23:02:45 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_print_sudoku(int **grid)
{
	int		i;
	int		j;
	char	out;

	j = 0;
	i = 0;
	while (i <= 8)
	{
		j = 0;
		while (j <= 8)
		{
			out = grid[i][j] + '0';
			write(1, &out, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_wrong_grid_check(char **grid)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < 10)
	{
		while (grid[i][k] != '\0')
		{
			if ((grid[i][k] < '1' || grid[i][k] > '9') && grid[i][k] != EMPTY)
				return (1);
			k++;
		}
		if (k != 9)
			return (1);
		i++;
		k = 0;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int **grid;

	if (argc < 10 || argc > 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_wrong_grid_check(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = ft_transform_grid(argv);
	if (!ft_check_extra_solutions(grid))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_solve(grid) == 1)
	{
		ft_print_sudoku(grid);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
