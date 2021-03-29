/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elm_threatment_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 09:32:50 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 10:17:55 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

int	ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
		|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

void	ft_clean_map(t_game_draw *mygame)
{
	int	act_pos;

	act_pos = mygame->map_dim.h - 1;
	if (mygame->worldmap != NULL)
	{
		while (act_pos >= 0)
		{
			ft_clean_arr(mygame->worldmap[act_pos]);
			free(mygame->worldmap[act_pos]);
			mygame->worldmap[act_pos] = NULL;
			act_pos--;
		}
	}
	free(mygame->worldmap);
	mygame->worldmap = NULL;
}
