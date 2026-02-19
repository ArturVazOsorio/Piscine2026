/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:53:55 by artur             #+#    #+#             */
/*   Updated: 2026/02/19 13:02:20 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int size;

	i = 0;
	size = max - min;
	array = malloc(size * (sizeof(int)));
	if ((!array) || (min >= max))
	{
		return (NULL);
	}
	while (i < size)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

int	main(void)
{
	int i = 0;
	int min = 5;
	int max = 20;
	int size = max - min;
	int	*box = ft_range(min, max);

	while (i < size)
	{
		printf("%d\n",box[i]);
		i++;
	}
	free(box);
	box = NULL;
	return (0);
}
