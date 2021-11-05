/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:29:24 by maxenceli         #+#    #+#             */
/*   Updated: 2021/10/18 19:18:14 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>

int		ft_check_square(int **tab, int x, int y, int value);
int		ft_check_li_cl(int **tab, int x, int y, int value);
void	ft_print_tab(int **tab);
void	ft_init_tab(int **tab, char *arg);
int		ft_first_checks(int **tab);
void	ft_free(int **tab);
int		**ft_maloc81_int(void);

#endif
