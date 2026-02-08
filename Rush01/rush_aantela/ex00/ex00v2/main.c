/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:48:35 by artur             #+#    #+#             */
/*   Updated: 2026/02/08 05:48:45 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);
void	print_grid(int **grid);
int		solve(int **grid, int *clues, int pos);

void	free_all(int **grid, int *clues)
{
	int	i;

	if (clues)
		free(clues);
	if (grid)
	{
		i = 0;
		while (i < 4)
			free(grid[i++]);
		free(grid);
	}
}

int	**create_grid(void)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **)malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * 4);
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}

int	*parse_clues(char *str)
{
	int	*clues;
	int	i;
	int	j;

	clues = (int *)malloc(sizeof(int) * 16);
	if (!clues)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
			clues[j++] = str[i] - '0';
		i++;
	}
	if (j != 16)
	{
		free(clues);
		return (NULL);
	}
	return (clues);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	*clues;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	clues = parse_clues(argv[1]);
	grid = create_grid();
	if (!clues || !grid || !solve(grid, clues, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	free_all(grid, clues);
	return (0);
}
