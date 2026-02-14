/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:07:56 by artur             #+#    #+#             */
/*   Updated: 2026/02/14 13:14:47 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

int	main(int ac, char **av)
{	
	int z;

	z = 1;
	if (ac > 1)
	{
		while (av[z] && z < ac)
		{
			ft_putstr(av[z]);
			write(1, "\n", 1);
			z++;
		}
	}
	return (0);

}
