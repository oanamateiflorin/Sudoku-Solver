/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:12:07 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 14:02:14 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		**ft_convert(char **argv, int **tab)
{
	int i;
	int j;
	int a;
	int b;

	i = 1;
	a = 0;
	while (i <= N)
	{
		j = 0;
		b = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				tab[a][b] = argv[i][j] - '0';
			else
				tab[a][b] = 0;
			b++;
			j++;
		}
		i++;
		a++;
	}
	return (tab);
}
