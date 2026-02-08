/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantela- <aantela-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 03:17:46 by aantela-          #+#    #+#             */
/*   Updated: 2026/02/08 03:44:43 by aantela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		solve(int grid[4][4], int *clues, int pos);
void	print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	grid[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int	clues[16];
	int	i;
	int	j;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[1][i] != '\0' && j < 16)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
			clues[j++] = argv[1][i] - '0';
		i++;
	}
	if (j != 16 || !solve(grid, clues, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	return (0);
}
