/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:12:45 by artur             #+#    #+#             */
/*   Updated: 2026/02/17 00:16:42 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		ft_putchar(str[c]);
		c++;
	}
}
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(argv[argc - 1]);
		ft_putchar('\n');
		return(0);
	}
	ft_putchar('\n');
	return (0);
}
