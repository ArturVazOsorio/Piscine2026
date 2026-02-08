/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rows_above.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalamba <dgalamba@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:16:28 by dgalamba          #+#    #+#             */
/*   Updated: 2026/02/08 01:41:46 by dgalamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	while_loops_rec(char ***ato, int level)
{
	int	i;

	if (level == 4)
	{
		if (teste(matrix) == 1)
			return (1);
		return (0);
	}
	i = 0;
	while (ato[level][i] != NULL)
	{
		if (level == 0)
			m1 = ato[0][i];
		else if (level == 1)
			m2 = ato[1][i];
		else if (level == 2)
			m3 = ato[2][i];
		else if (level == 3)
			m4 = ato[3][i];
		if (while_loops_rec(ato, level + 1))
			return (1);
		i++;
	}
	return (0);
}
