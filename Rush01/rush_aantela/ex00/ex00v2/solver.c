/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 05:49:28 by artur             #+#    #+#             */
/*   Updated: 2026/02/10 23:52:46 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_board(int **grid, int *clues);//call function.


int	is_safe(int **grid, int pos, int num)
{
	int	row;
	int	col;
	int	i;

	row = pos / 4;//set line
	col = pos % 4;//set coll
	i = 0;
	while (i < 4) //verify if have a number in row and coll.
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);//return failed.
		i++;
	}
	return (1); //return sucess.
}
//recive grid clues and pos || backtracking sistem
int	solve(int **grid, int *clues, int pos)
{
	int	num;
	int	row;
	int	col;
	//if pos == 16 return to check board to validate if respect all clues.
	if (pos == 16)
		return (check_board(grid, clues));
	row = pos / 4;//set line
	col = pos % 4;//set coll
	num = 1;
	while (num <= 4) //try put a number in pos current.
	{
		if (is_safe(grid, pos, num)) // verify if number exist in line our coll. 
		{
			grid[row][col] = num; //receive number in curruent line and coll
			if (solve(grid, clues, pos + 1)) //recursive call for next pos.
				return (1); //signalize sucess
			grid[row][col] = 0; //if number dont solve clean and try next numb.
		}
		num++;
	}
	return (0);//signalize failed.
}
