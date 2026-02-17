/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:48:55 by artur             #+#    #+#             */
/*   Updated: 2026/02/17 00:05:38 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_occ_a(char *str)
{
	int	x;
	int a;

	x = 0;
	a = 0;
	while (str[x] != '\0')
	{	
		if (str[x] == 'a')
		{
			a = 1;
		}
		x++;
	}
	return (a);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_occ_a(argv[1]) == 0)
		{
			ft_putchar('\n');
			return (0);
		}
	}
	ft_putchar('a');
	ft_putchar('\n');
	return (0);
}
