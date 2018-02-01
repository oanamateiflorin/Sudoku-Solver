/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstefan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:44:09 by dstefan           #+#    #+#             */
/*   Updated: 2017/08/20 16:18:04 by dstefan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

# define N	9
# include <stdlib.h>
# include <unistd.h>

int			ft_check_part3(int argc);
int			ft_check_part2(char **argv);
int			ft_check(char **argv, int argc);
void		ft_print(int **tab);
int			ft_back(int **tab);
int			**ft_convert(char **argv, int **tab);
int			ft_next(int **tab, int *linie, int *coloana);
int			ft_valid_part2(int **tab, int linie, int coloana, int k);
int			ft_valid(int **tab, int linie, int coloana, int k);
int			ft_check2(int **tab);
int			ft_check2_linie(int **tab);
int			ft_check2_coloana(int **tab);
int			*ft_init(int *va);
int			ft_va(int *va);
int			ft_check2_patrat(int **tab);
int			ft_patrat(int **tab, int linie, int coloana);
#endif
