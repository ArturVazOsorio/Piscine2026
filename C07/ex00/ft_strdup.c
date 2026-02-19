/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:36:40 by artur             #+#    #+#             */
/*   Updated: 2026/02/19 12:52:12 by artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dupli;
	int		len;

	len = ft_strlen(str) + 1;
	dupli = malloc(len * sizeof(char));
	if (!dupli)
	{
		return (NULL);
	}
	return (ft_strcpy(dupli, str));
}

int	main(void)
{
	char src[] = "Hello World.";
	char *dupli = ft_strdup(src);
	printf("%s\n",dupli);
	free(dupli);
	return (0);
}
