/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 01:09:05 by artur             #+#    #+#             */
/*   Updated: 2026/01/30 01:42:35 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*FUNCAO PARA IMPRESSAO DE CARACTERES*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*FUNCAO PARA MOSTRAR NO TERMINAL O ALPHABETO MINUSCULO
 sendo letter variavel que testa se o valor =ou menor que 'z'
 apos isto faz um incremento.*/
void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_putchar(letter);
		letter++;
	}
}

/*int	main(void)
{
	ft_print_alphabet();
	return(0);
}*/
