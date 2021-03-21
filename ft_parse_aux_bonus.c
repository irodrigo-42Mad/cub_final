/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:26:56 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/19 00:12:42 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parsename(const char *text, const char *compare)
{
	int len1;
	int len2;
	int cont;
	int act;

	len1 = ft_strlen(text) - 1;
	len2 = ft_strlen(compare);
	act = len2 - 1;
	cont = 0;
	while (cont < len2)
	{
		if (text[len1] != compare[act])
			return (-1);
		cont++;
		act--;
		len1--;
	}
	return (1);
}

int			ft_check_gamer(t_game_draw *mygame)
{
	if (mygame->gamer.count == 0)
		return (ft_put_error(TIT_003, MSG1_015, -1));
	if (mygame->gamer.count > 1)
		return (ft_put_error(TIT_003, MSG1_016, -1));
	return (1);
}
