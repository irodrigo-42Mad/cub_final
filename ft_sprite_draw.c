/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 04:29:02 by jdiaz-co          #+#    #+#             */
/*   Updated: 2021/03/29 12:18:41 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	spritepos(t_game_draw *mygame, int x, int y)
{
	if (mygame->spr_totalb < mygame->spr_total)
	{
		mygame->sprite[mygame->spr_totalb].spr_pos.x = x;
		mygame->sprite[mygame->spr_totalb].spr_pos.y = y;
		mygame->spr_totalb++;
	}
}

static void	sortsprite(t_game_draw *mygame)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	j = 0;
	while (i < mygame->spr_total)
	{
		j = i + 1;
		while (j <= mygame->spr_total - 1)
		{
			if (mygame->sprite[i].spr_dist < mygame->sprite[j].spr_dist)
			{
				temp = mygame->sprite[i];
				mygame->sprite[i] = mygame->sprite[j];
				mygame->sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_order(t_game_draw *mygame)
{
	int		i;

	i = 0;
	while (i < mygame->spr_total)
	{
		mygame->sprite[i].spr_dist
			= ((mygame->rc.posx - mygame->sprite[i].spr_pos.x)
				* (mygame->rc.posx - mygame->sprite[i].spr_pos.x)
				+ (mygame->rc.posy - mygame->sprite[i].spr_pos.y)
				* (mygame->rc.posy - mygame->sprite[i].spr_pos.y));
		i++;
	}
	sortsprite(mygame);
}

void	draw_sprite(t_game_draw *mygame)
{
	sprite_order(mygame);
	raysprite(mygame);
}
