/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:50:05 by artur             #+#    #+#             */
/*   Updated: 2026/02/11 00:52:21 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//basic putstr.
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
//prinf grid if sucess.
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
			c = grid[i][j] + '0'; //convert int to ascii and print (putchar).
			write(1, &c, 1);
			if (j < 3) //print space after each number less in end.
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1); //new line
		i++;
	}
}
//check visibility of numbers
int	check_vis(int *line, int clue, int reverse)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	if (reverse) //if reverse is 0 look front to back if is 1 look back to front.
		i = 3;
	while (i >= 0 && i < 4) 
	{
		if (line[i] > max)  //look if see numbers
		{
			max = line[i];
			count++; //mark how many numbers have see
		}
		if (reverse)
			i--;
		else
			i++;
	}
	return (count == clue);//return 1 if numbers see match the number required in clue our 
						   //return 0 if no match 
}
//verify if all clue is satisfied
int	check_board(int **grid, int *clues)
{
	int	i;
	int	j;
	int	col[4];

	i = 0;
	while (i < 4) //check one row and coll at time
	{
		if (!check_vis(grid[i], clues[8 + i], 0) //check current row and check if clues of left and right
			|| !check_vis(grid[i], clues[12 + i], 1)) //calling check vis in reverse 1 if check fails.
			return (0);								//return invalid board Error \n	.
		j = 0;
		while (j < 4)
		{
			col[j] = grid[j][i]; //create a temp for store coll from grid.
			j++;
		}
		if (!check_vis(col, clues[i], 0) || !check_vis(col, clues[4 + i], 1)) 
			return (0); //check if clues of top and botton is true calling check vis in reverse 1
		i++;
	}
	return (1);//if all check have be passed found a solution.
}
