/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:29:52 by maxenceli         #+#    #+#             */
/*   Updated: 2021/10/18 19:29:02 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	ft_find_squarex(int x)
{
	if (x / 3 == 0)
		return (0);
	if (x / 3 == 1)
		return (3);
	if (x / 3 == 2)
		return (6);
	return (-1);
}

int	ft_find_squarey(int y)
{
	if (y / 3 == 0)
		return (0);
	if (y / 3 == 1)
		return (3);
	if (y / 3 == 2)
		return (6);
	return (-1);
}

int	ft_check_square(int **tab, int x, int y, int value)
{
	int		xstart;
	int		ystart;
	int		i;
	int		w;

	ystart = ft_find_squarey(y);
	i = 0;
	while (i < 3)
	{
		xstart = ft_find_squarex(x);
		w = 0;
		while (w < 3)
		{
			if (tab[ystart][xstart] == value && (xstart != x || ystart != y))
				return (1);
			xstart++;
			w++;
		}
		ystart++;
		i++;
	}
	return (0);
}

int	ft_check_li_cl(int **tab, int x, int y, int value)
{
	int		temp;

	temp = 0;
	while (temp < 9)
	{
		if (tab[y][temp] == value && x != temp)
			return (1);
		temp++;
	}
	temp = 0;
	while (temp < 9)
	{
		if (tab[temp][x] == value && y != temp)
			return (1);
		temp++;
	}
	return (0);
}

int	ft_first_checks(int **tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (tab[y][x] != 0 && (ft_check_li_cl(tab, x, y, tab[y][x]) == 1
				|| ft_check_square(tab, x, y, tab[y][x]) == 1))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
