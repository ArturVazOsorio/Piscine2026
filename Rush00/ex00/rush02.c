/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantela- <aantela-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:52:39 by aantela-          #+#    #+#             */
/*   Updated: 2026/01/31 17:40:18 by aantela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0 || x >= 2147483647 || y >= 2147483647)
		return ;
	i = -1;
	while (++i <= y)
	{
		j = -1;
		while (++j <= x)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == x))
				ft_putchar('A');
			else if ((i == y && j == 0) || (i == y && j == x))
				ft_putchar('C');
			else if ((i == 0 || i == y) && (j > 0 && j < x))
				ft_putchar('B');
			else if ((j == 0 || j == x) && (i > 0 && i < y))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
