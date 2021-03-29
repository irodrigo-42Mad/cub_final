/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:14:45 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 12:01:37 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

int	parsename(const char *text, const char *compare)
{
	int	len1;
	int	len2;
	int	cont;
	int	act;

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

int	ft_check_gamer(t_game_draw *mygame)
{
	if (mygame->gamer.count == 0)
		exit(ft_put_error(TIT_003, MSG1_015, -1));
	if (mygame->gamer.count > 1)
		exit(ft_put_error(TIT_003, MSG1_016, -1));
	return (1);
}

/*
** in this function creates a dummy map that check if prime map is closed
*/

int	ft_check_close(t_game_draw *mygame)
{
	char	**tmp;
	int		line;

	line = 0;
	tmp = NULL;
	if (!tmp)
	{
		tmp = ft_calloc(mygame->map_dim.h, sizeof(char *));
		if (!tmp)
			exit(ft_put_error(TIT_004, MSG1_017, -1));
	}
	while (line < mygame->map_dim.h)
	{
		tmp[line] = ft_strdup(mygame->worldmap[line]);
		line++;
	}
	tmp[mygame->gamer.pos.y][mygame->gamer.pos.x] = '0';
	ft_checkborder(mygame->gamer.pos.y, mygame->gamer.pos.x, tmp, mygame);
	ft_fretable(tmp, mygame);
	if (mygame->map_err == -1)
		ft_put_error(TIT_003, MSG1_018, -1);
	return (0);
}

void	ft_checkborder(int x, int y, char **str, t_game_draw *err)
{
	if (err->map_err != -1)
	{
		if (x == 0 || y == 0 || y == (int)ft_strlen(str[x]) - 1
			|| x == err->map_dim.h - 1 || y >= (int)ft_strlen(str[x + 1])
			|| y >= (int)ft_strlen(str[x - 1]))
		{
			err->map_err = -1;
			ft_write_error("Map error\n", "Open map structure\n");
			exit(-1);
		}
		str[x][y] = '3';
		if (str[x][y + 1] == '0' || str[x][y + 1] == '2'
			|| str[x][y + 1] == '9')
			ft_checkborder(x, y + 1, str, err);
		if (str[x][y - 1] == '0' || str[x][y - 1] == '2'
			|| str[x][y - 1] == '9')
			ft_checkborder(x, y - 1, str, err);
		if (str[x + 1][y] == '0' || str[x + 1][y] == '2'
			|| str[x + 1][y] == '9')
			ft_checkborder(x + 1, y, str, err);
		if (str[x - 1][y] == '0' || str[x - 1][y] == '2'
			|| str[x - 1][y] == '9')
			ft_checkborder(x - 1, y, str, err);
	}
}
