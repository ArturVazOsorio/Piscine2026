/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <arturvitorantelavazosorio@gmail.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:58:26 by artur             #+#    #+#             */
/*   Updated: 2026/01/28 10:14:31 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*int	main(void)
{
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	ft_putchar('\n');
}*/
