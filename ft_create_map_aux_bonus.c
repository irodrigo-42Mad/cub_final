/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_aux_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:16:30 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 12:56:25 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**Funcion que permite calcular el ancho de la linea actual
*/

int	ft_get_line_width(char *mapchar, int pos)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (mapchar[pos] != '\n')
	{
		if (mapchar[pos] == '8')
			count++;
		len++;
		pos++;
	}
	count = (count * 4);
	return (len + count + 1);
}

int	ft_n_err(int n_err)
{
	if (n_err < 0)
		return (-1);
	else
		return (0);
}
