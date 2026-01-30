/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:59:33 by artur             #+#    #+#             */
/*   Updated: 2026/01/30 02:06:19 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int	n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

/*int	main(void)
{
	ft_is_negative(6);
	ft_is_negative(9);
	ft_is_negative(-6);
	ft_is_negative(0);
	ft_is_negative(26);
	ft_is_negative(-26);
}*/
