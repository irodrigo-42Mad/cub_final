/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fnc_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:43:03 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/29 12:28:17 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_var(int *line, int *pos, int *dim)
{
	*line = 0;
	*dim = 0;
	*pos = 0;
}

void	ft_free_textures(t_game_draw *mygame)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		free(mygame->tx.wlone[i]);
		mygame->tx.wlone[i] = NULL;
		free(mygame->tx.wdata[i]);
		mygame->tx.wdata[i] = NULL;
	}
	mygame->allspr_dist = NULL;
	mygame->allspr_pos = NULL;
	mygame->sprite = NULL;
}
