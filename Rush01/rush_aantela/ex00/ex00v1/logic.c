/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:26:53 by artur             #+#    #+#             */
/*   Updated: 2026/02/08 05:26:58 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_visibility(int *line, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count == clue);
}

int	check_visibility_rev(int *line, int clue)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 3;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count == clue);
}

int	check_board(int **grid, int *clues)
{
	int	i;
	int	col[4];
	int	j;

	i = 0;
	while (i < 4)
	{
		if (!check_visibility(grid[i], clues[8 + i])
			|| !check_visibility_rev(grid[i], clues[12 + i]))
			return (0);
		j = 0;
		while (j < 4)
		{
			col[j] = grid[j][i];
			j++;
		}
		if (!check_visibility(col, clues[i])
			|| !check_visibility_rev(col, clues[4 + i]))
			return (0);
		i++;
	}
	return (1);
}
