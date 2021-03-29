/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:36:46 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 12:01:48 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

void	ft_swap_int(int *a, int *b)
{
	int	iaux;

	iaux = *a;
	*a = *b;
	*b = iaux;
}

void	ft_swap_float(double *a, double *b)
{
	double	faux;

	faux = *a;
	*a = *b;
	*b = faux;
}
