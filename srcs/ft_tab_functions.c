/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:30:24 by maxenceli         #+#    #+#             */
/*   Updated: 2021/10/18 19:17:19 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_print_tab(int **tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			printf("%d", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_init_tab(int **tab, char *arg)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			tab[y][x] = arg[i] - '0';
			x++;
			i++;
		}
		y++;
	}
}

void	ft_free(int **tab)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	**ft_maloc81_int(void)
{
	int	**tab;
	int	i;

	tab = malloc(sizeof(int *) * 9);
	if (!tab)
		return (0);
	i = 0;
	while (i < 9)
	{
		tab[i] = malloc(sizeof(int) * 9);
		if (!tab[i])
			return (0);
		i++;
	}
	return (tab);
}
