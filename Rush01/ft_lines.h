/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmikhail <dmikhail@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:39:23 by dmikhail          #+#    #+#             */
/*   Updated: 2026/02/07 18:52:41 by dmikhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINES_H
# define FT_LINES_H

struct s_lines
{
	const char		**data;
	unsigned int	size;
};

struct	s_lines	get_line(int i);

#endif
