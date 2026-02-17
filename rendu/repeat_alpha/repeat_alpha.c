/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:41:29 by artur             #+#    #+#             */
/*   Updated: 2026/02/17 01:43:09 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_repeatchar(char *str)
{
	int c;
	int x;

	c = 0;
	x = 0;
	while (str[c] != '\0')
	{	
		x = 0;
		if (str[c] >= 'a' && str[c] <= 'z')
		{
			x = str[c] - 96;
			while (x > 0)
			{
				ft_putchar(str[c]);
				x--;
			}
		}
		else if (str[c] >= 'A' && str[c] <= 'Z')
		{
			x = str[c] - 64;
			while (x > 0)
			{
				ft_putchar(str[c]);
				x--;
			}
		}
		else
		{
			ft_putchar(str[c]);
		}
		c++;
	}
}
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_repeatchar(argv[1]);
		ft_putchar('\n');
		return (0);
	}
	ft_putchar('\n');
	return (0);
}
