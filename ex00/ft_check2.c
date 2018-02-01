/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:17:29 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 16:17:03 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		*ft_init(int *va)
{
	int i;

	i = 0;
	while (i < 10)
	{
		va[i] = 0;
		i++;
	}
	return (va);
}

int		ft_va(int *va)
{
	int i;

	i = 1;
	while (i <= N)
	{
		if (va[i] > 1)
		{
			write(1, "Erreur\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check2_coloana(int **tab)
{
	int i;
	int j;
	int *va;

	va = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < N)
	{
		va = ft_init(va);
		j = 0;
		while (j < N)
		{
			if (tab[j][i] > 0)
				va[tab[j][i]]++;
			j++;
		}
		i++;
		if (ft_va(va) == 0)
			return (0);
	}
	if (ft_check2_patrat(tab) == 0)
		return (0);
	return (1);
}

int		ft_check2_linie(int **tab)
{
	int i;
	int j;
	int *va;

	va = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < N)
	{
		va = ft_init(va);
		j = 0;
		while (j < N)
		{
			if (tab[i][j] > 0)
				va[tab[i][j]]++;
			j++;
		}
		i++;
		if (ft_va(va) == 0)
			return (0);
	}
	if (ft_check2_coloana(tab) == 0)
		return (0);
	return (1);
}

int		ft_check2(int **tab)
{
	int nr;
	int i;
	int j;

	i = 0;
	nr = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (tab[i][j] != 0)
				nr++;
			j++;
		}
		i++;
	}
	if (nr < 17)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	if (ft_check2_linie(tab) == 0)
		return (0);
	return (1);
}
