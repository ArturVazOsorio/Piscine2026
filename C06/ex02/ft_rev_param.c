/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:16:56 by artur             #+#    #+#             */
/*   Updated: 2026/02/14 13:32:02 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

int	main(int ac, char **av)
{
	int z;

	z = ac - 1;
	if (ac > 1)
	{
		while (av[z] && z != 0)
		{
			if(z > 0)
			{
				ft_putstr(av[z]);
				write(1, "\n", 1);
				z--;
			}
		}
		return (0);
		
	}
	return (0);
}
