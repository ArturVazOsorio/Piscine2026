/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:48:35 by artur             #+#    #+#             */
/*   Updated: 2026/02/10 23:32:19 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str); // call function 
void	print_grid(int **grid); 
int		solve(int **grid, int *clues, int pos);
// free all memory allocate (grid(grid[]),clues)
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
//inicialize grid creation.
int	**create_grid(void)
{
	int	**grid;
	int	i;
	int	j;
	// try allocate memory in heap using int value  for a matriz 4x4 grid.
	grid = (int **)malloc(sizeof(int *) * 4);
	if (!grid) //if no memory avaliable || malloc failed return null.
		return (NULL);
	i = 0;
	while (i < 4)
	{	//try allocate memory in heap using int value for each line  4 and fill all using 0.
		grid[i] = (int *)malloc(sizeof(int) * 4);
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
	//return grind  && memomy allocate have sucess.
	return (grid);
}
//receive fist parameter sending in terminal.
int	*parse_clues(char *str) 
{
	int	*clues;
	int	i;
	int	j;
	//try allocate memory in heap using int value int * 16 = 4 * 16 bytes.
	clues = (int *)malloc(sizeof(int) * 16);
	if (!clues) //is no memory avaliable our malloc failed return null
		return (NULL);
	i = 0;
	j = 0;
	// if string not null and j less of 16.
	while (str[i] && j < 16)
	{	//if character in pos[i] is in interval of 1 and 4 add to clues converting to int.
		if (str[i] >= '1' && str[i] <= '4')
			clues[j++] = str[i] - '0'; //clues walk [j] for each int received.
		i++;//next pos of string. 
	}
	//if clues not full clean clues and return null
	if (j != 16)
	{
		free(clues);
		return (NULL);
	}
	//return clues && memory allocate have sucess.
	return (clues);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	*clues;
	//test if argc is 2,if not print Error and new line
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	//clues receive parce_clues of fist parameter, argv[0] = name of program.
	clues = parse_clues(argv[1]);
	// grid receive create_grid.
	grid = create_grid();
	// se clues or grid or solve(grid and clues and pos 0 dont respond true) programa failed return Erro and newline.
	if (!clues || !grid || !solve(grid, clues, 0))
		ft_putstr("Error\n");
	else // if all check work and resolve the problem print.
		print_grid(grid);
	//release all memory allocated.
	free_all(grid, clues);
	//finish program.
	return (0);
}
