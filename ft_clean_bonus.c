/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:57:05 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 10:07:42 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clean_arr(char *data)
{
	int	i;

	i = (ft_strlen(data) - 1);
	while (i >= 0 && data[i] != '\0')
	{
		data[i] = '\0';
		i--;
	}
}

void	ft_fretable(char **fra, t_game_draw *mygame)
{
	int		pos;

	pos = 0;
	while (pos < mygame->map_dim.h)
	{
		free(fra[pos]);
		fra[pos] = NULL;
		pos++;
	}
	free(fra);
	fra = NULL;
}

void	ft_freemap(t_game_draw *mygame)
{
	int		pos;

	pos = 0;
	if (mygame->sprite != NULL)
	{
		free(mygame->sprite);
		mygame->sprite = NULL;
	}
	while (mygame->worldmap[pos] != NULL && pos < mygame->map_dim.h)
	{
		ft_clean_arr(mygame->worldmap[pos]);
		mygame->worldmap[pos] = NULL;
		pos++;
	}
	free(mygame->worldmap);
	mygame->worldmap = NULL;
}

void	ft_freearray(char **str)
{
	int	elm;

	elm = 0;
	if (str)
	{
		while (str[elm])
		{
			if (str[elm] != NULL)
				free(str[elm]);
			elm++;
		}
		free(str);
	}
}

void	ft_clean_mapchar(t_game_draw *mygame)
{
	if (mygame->mapchar != NULL)
	{
		ft_clean_arr(mygame->mapchar);
		free(mygame->mapchar);
		mygame->mapchar = NULL;
	}
}
