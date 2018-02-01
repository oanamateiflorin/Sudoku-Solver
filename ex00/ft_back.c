/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:18:55 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/19 14:34:23 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		ft_next(int **tab, int *linie, int *coloana)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (tab[i][j] == 0)
			{
				*linie = i;
				*coloana = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_valid_part2(int **tab, int linie, int coloana, int k)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[linie - (linie % 3) + i][coloana - (coloana % 3) + j] == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_valid(int **tab, int linie, int coloana, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < N)
	{
		if (tab[linie][i] == k)
			return (0);
		i++;
	}
	while (j < N)
	{
		if (tab[j][coloana] == k)
			return (0);
		j++;
	}
	if (ft_valid_part2(tab, linie, coloana, k) == 0)
		return (0);
	return (1);
}

int		ft_back(int **tab)
{
	int linie;
	int coloana;
	int i;

	if (ft_next(tab, &linie, &coloana) == 1)
		return (1);
	i = 1;
	while (i <= N)
	{
		if (ft_valid(tab, linie, coloana, i) == 1)
		{
			tab[linie][coloana] = i;
			if (ft_back(tab) == 1)
				return (1);
			tab[linie][coloana] = 0;
		}
		i++;
	}
	return (0);
}
