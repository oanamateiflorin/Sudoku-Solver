/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:01:00 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 16:13:39 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		main(int argc, char **argv)
{
	int **tab;
	int i;

	if (ft_check(argv, argc) == 0)
		return (0);
	tab = (int **)malloc(sizeof(int *) * N);
	i = 0;
	while (i < N)
		tab[i++] = (int *)malloc(sizeof(int) * N);
	tab = ft_convert(argv, tab);
	if (ft_check2(tab) == 0)
		return (0);
	if (ft_back(tab) == 1)
		ft_print(tab);
	else
		write(1, "Erreur\n", 8);
	i = 0;
	while (i < N)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
