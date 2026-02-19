/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:40:29 by artur             #+#    #+#             */
/*   Updated: 2026/02/19 13:54:42 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	size;

	if (min >= max)
	{
		return (NULL);
	}
	size = max - min;
	array = malloc(size *(sizeof(int)));
	if (!array)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if(!*range)
	{
		return (-1);
	}
	return (max -min);
}

int main(void)
{
    int *test= NULL;
    int size;
    int i;
    int min = 10;
    int max = 20;

    size = ft_ultimate_range(&test, min, max);

    if (size == -1)
    {
        printf("Erro de alocação!\n");
        return (1);
    }

    printf("size: %d\n", size);
    printf("Valores: ");
    i = 0;
	while (i < size)
	{
		printf("%d ,",test[i]);
		i++;
	}
    printf("\n");

    free(test);
    return (0);
}

