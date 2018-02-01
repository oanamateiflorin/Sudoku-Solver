/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:45:27 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 16:18:57 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		ft_patrat(int **tab, int linie, int coloana)
{
	int i;
	int j;
	int *va;

	va = (int *)malloc(sizeof(int) * 10);
	i = 0;
	va = ft_init(va);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[linie + i][coloana + j] > 0)
				va[tab[linie + i][coloana + j]]++;
			j++;
		}
		i++;
		if (ft_va(va) == 0)
			return (0);
	}
	return (1);
}

int		ft_check2_patrat(int **tab)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (k < 3)
	{
		if (ft_patrat(tab, i, 0) == 0)
			return (0);
		if (ft_patrat(tab, i, 3) == 0)
			return (0);
		if (ft_patrat(tab, i, 6) == 0)
			return (0);
		i += 3;
		k++;
	}
	return (1);
}
