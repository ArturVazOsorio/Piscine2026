/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmikhail <dmikhail@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:07:22 by dmikhail          #+#    #+#             */
/*   Updated: 2026/02/07 19:07:28 by dmikhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lines.h"

struct s_lines	get_line(int i)
{
	static const char			*l1[] = {"4123", "4132", "4231",
		"4213", "4312", "4321"};
	static const char			*l2[] = {"1423", "1432", "2431",
		"2413",	"2143", "3412",	"3421", "3142", "3241", "3124", "3214"};
	static const char			*l3[] = {"1243", "2143", "2314",
		"2341", "1342", "1324"};
	static const char			*l4[] = {"1234"};
	static const struct s_lines	lns[] = {{l1, 6}, {l2, 11}, {l3, 6}, {l4, 1}};

	return (lns[i - 1]);
}
/*
#include <stdio.h>

int	main(void)
{
	int				i;
	struct s_lines	s_line;

	i = 0;
	s_line = get_line(4);
	while (i < s_line.size)
	{
		printf("%s\n", s_line.data[i]);
		i++;
	}
	return (0);
}
*/
