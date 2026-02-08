/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantela- <aantela-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:47:31 by aantela-          #+#    #+#             */
/*   Updated: 2026/02/08 16:47:35 by aantela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_board(int **grid, int *clues);

int	is_safe(int **grid, int pos, int num)
{
	int	row;
	int	col;
	int	i;

	row = pos / 4;
	col = pos % 4;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int **grid, int *clues, int pos)
{
	int	num;
	int	row;
	int	col;

	if (pos == 16)
		return (check_board(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, pos, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
