/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantela- <aantela-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:46:48 by aantela-          #+#    #+#             */
/*   Updated: 2026/02/08 16:47:18 by aantela-         ###   ########.fr       */
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

/* ** Valida o formato estrito: tamanho 31, padrao "N N N..."
*/
int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 != 0 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/* ** Aloca e preenche o array. Agora tem menos de 25 linhas.
*/
int	*parse_clues(char *str)
{
	int	*clues;
	int	i;

	if (!check_input(str))
		return (NULL);
	clues = (int *)malloc(sizeof(int) * 16);
	if (!clues)
		return (NULL);
	i = 0;
	while (i < 16)
	{
		clues[i] = str[i * 2] - '0';
		i++;
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
	if (!clues)
	{
		ft_putstr("Error\n");
		return (0);
	}
	grid = create_grid();
	if (!grid || !solve(grid, clues, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	free_all(grid, clues);
	return (0);
}
