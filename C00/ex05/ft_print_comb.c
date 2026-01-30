/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:09:36 by artur             #+#    #+#             */
/*   Updated: 2026/01/30 03:07:17 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	var1;
	char	var2;
	char	var3;

	var1 = '0';
	while (var1 <= '7')
	{
		var2 = var1 + 1;
		while (var2 <= '8')
		{
			var3 = var2 + 1;
			while (var3 <= '9')
			{
				ft_putchar(var1);
				ft_putchar(var2);
				ft_putchar(var3);
				if (!(var1 == '7' && var2 == '8' && var3 == '9'))
					write(1, ", ", 2);
				var3++;
			}
			var2++;
		}
		var1++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return(0);
}*/
