/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:14:00 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 14:00:00 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_sudoku.h"

int		ft_check_part3(int argc)
{
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	return (1);
}

int		ft_check_part2(char **argv)
{
	int i;
	int c;
	int j;

	i = 1;
	while (i <= N)
	{
		c = 0;
		j = 0;
		while (argv[i][j])
		{
			c++;
			j++;
		}
		if (c != 9)
		{
			write(1, "Erreur\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	if (ft_check_part3(argc) == 0)
		return (0);
	if (ft_check_part2(argv) == 0)
		return (0);
	while (i <= N)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '1' || argv[i][j] > '9') && argv[i][j] != '.')
			{
				write(1, "Erreur\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
