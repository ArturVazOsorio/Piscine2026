/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantela- <aantela-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:47:43 by aantela-          #+#    #+#             */
/*   Updated: 2026/02/08 16:47:46 by aantela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check_vis(int *line, int clue, int reverse)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	if (reverse)
		i = 3;
	while (i >= 0 && i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		if (reverse)
			i--;
		else
			i++;
	}
	return (count == clue);
}

int	check_board(int **grid, int *clues)
{
	int	i;
	int	j;
	int	col[4];

	i = 0;
	while (i < 4)
	{
		if (!check_vis(grid[i], clues[8 + i], 0)
			|| !check_vis(grid[i], clues[12 + i], 1))
			return (0);
		j = 0;
		while (j < 4)
		{
			col[j] = grid[j][i];
			j++;
		}
		if (!check_vis(col, clues[i], 0) || !check_vis(col, clues[4 + i], 1))
			return (0);
		i++;
	}
	return (1);
}
