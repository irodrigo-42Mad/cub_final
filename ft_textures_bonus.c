/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:52:44 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/19 13:13:05 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	getdirandpos(t_game_draw *mygame, int x, int y)
{
	mygame->rc.posx = x + 0.5;
	mygame->rc.posy = y + 0.5;
	if (mygame->gamer.spr_dir == 'N')
	{
		mygame->rc.dirx = -1;
		mygame->rc.planey = 0.66;
	}
	if (mygame->gamer.spr_dir == 'S')
	{
		mygame->rc.dirx = 1;
		mygame->rc.planey = -0.66;
	}
	if (mygame->gamer.spr_dir == 'W')
	{
		mygame->rc.diry = -1;
		mygame->rc.planex = -0.66;
	}
	if (mygame->gamer.spr_dir == 'E')
	{
		mygame->rc.diry = 1;
		mygame->rc.planex = 0.66;
	}
	mygame->dirok = 1;
}

int			ft_check_content(t_game_draw *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_dim.h)
	{
		j = -1;
		while (++j < game->map_dim.w && !((game->worldmap[i][j]) == '\0'))
		{
			if (game->dirok == 0 && game->worldmap[i][j] == '3')
			{
				getdirandpos(game, i, j);
				game->worldmap[i][j] = '0';
			}
			if (game->worldmap[i][j] == '2')
				spritepos(game, i, j);
		}
	}
	return (1);
}

void		ft_setgamer(t_game_draw *mygame, int mat_pos, int line)
{
	mygame->gamer.pos.x = mat_pos;
	mygame->gamer.pos.y = line;
}

int			ft_reserve_worldmap(t_game_draw *mygame)
{
	if (!mygame->worldmap)
		if (!(mygame->worldmap = (char **)malloc(sizeof(char *)
			* mygame->map_dim.h + 1)))
			return (ft_put_error(TIT_004, MSG1_024, -1));
	return (0);
}

int			sp(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}
