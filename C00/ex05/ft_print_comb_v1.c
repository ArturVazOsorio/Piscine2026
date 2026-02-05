/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:17:18 by artur             #+#    #+#             */
/*   Updated: 2026/02/05 13:30:47 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_print_comb(void)
{
	int	var1;
	int	var2;
	int	var3;

	var1 = 0;
	while (var1 <= 7)
	{
		var2 = var1 + 1;
		while (var2 <= 8)
		{
			var3 = var2 + 1;
			while (var3 <= 9)
			{
				ft_putchar(var1 + '0');
				ft_putchar(var2 + '0');
				ft_putchar(var3 + '0');
				if (var1 != 7)
				{
					ft_putchar(' ');
					ft_putchar(',');				
				}
				var3++;
			}
			var2++;
		}
		var1++;
	}
}

int main(void)
{
	ft_print_comb();
}
