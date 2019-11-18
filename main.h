/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:51:10 by nsance            #+#    #+#             */
/*   Updated: 2019/08/11 18:19:32 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_H
# define __MAIN_H
# include <unistd.h>
# include <stdlib.h>
# define EMPTY '.'

void	ft_print_sudoku(int **grid);
int		check_row(int **grid, int row, int number);
int		check_col(int **grid, int col, int number);
int		check_box(int **grid, int row, int col, int number);
int		ft_find_unassigned(int **grid, int *row, int *col);
int		ft_check_for_valid(int **grid, int row, int col, int number);
int		ft_solve (int **grid);
int		**ft_transform_grid(char **grid);
int		ft_check_extra_solutions(int **grid);

#endif
