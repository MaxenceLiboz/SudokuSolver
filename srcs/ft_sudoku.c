/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:30:14 by maxenceli         #+#    #+#             */
/*   Updated: 2021/10/18 19:29:32 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_solve(int **tab, int x, int y, int value)
{	
	if (y == 8 && x == 9)
	{
		return (1);
	}
	if (x == 9)
	{
		x = 0;
		y++;
	}
	if (tab[y][x] != 0)
		return (ft_solve(tab, x + 1, y, 1));
	while (value < 10)
	{
		if (ft_check_square(tab, x, y, value) == 0
			&& ft_check_li_cl(tab, x, y, value) == 0)
		{
			tab[y][x] = value;
			if (ft_solve(tab, x + 1, y, 1) == 1)
				return (1);
		}
		value++;
	}
	tab[y][x] = 0;
	return (0);
}

void	ft_sudoku(char *arg)
{
	int	**tab;

	tab = ft_maloc81_int();
	if (!tab)
		return ;
	ft_init_tab(tab, arg);
	if (ft_first_checks(tab) == 1)
	{
		printf("The sudoku entered is invalid");
		return ;
	}
	if (ft_solve(tab, 0, 0, 1) == 1)
		ft_print_tab(tab);
	ft_free(tab);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_sudoku(argv[1]);
	else
		printf("Please enter your Sudoku (Example: ./a.out \"00012321...\"\n");
	return (0);
}
