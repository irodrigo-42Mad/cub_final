/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:35:13 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/29 12:23:33 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static int	ft_resolution(t_game_draw *mygame, char *line, int *pos)
{
	if (mygame->map_read == 1)
		exit(ft_put_error(TIT_009, MSG1_019, -9));
	if (mygame->win.w != 0 || mygame->win.h != 0)
		exit(ft_put_error(TIT_005, MSG1_006, -3));
	(*pos)++;
	mygame->win.w = ft_atoi_cub(line, pos);
	mygame->win.h = ft_atoi_cub(line, pos);
	ft_skip_spaces(line, pos);
	if (mygame->win.w <= 0 || mygame->win.h <= 0 || line[*pos] != '\0')
		exit(ft_put_error(TIT_005, MSG1_007, -4));
	return (0);
}

void	ft_if_comma(char *line, int *pos)
{
	if (line[*pos] != ',')
		exit(ft_put_error("Falta la comma\n", "cadena no valida\n", -1));
	(*pos)++;
	ft_skip_spaces(line, pos);
}

static int	getcolor(unsigned int *color, char *line,
						int *pos, t_game_draw *game)
{
	game->r = -1;
	game->g = -1;
	game->b = -1;
	if (game->map_read == 1)
		exit(ft_put_error(TIT_009, MSG1_022, -1));
	if (*color != RGB_NONE)
		exit(ft_put_error(TIT_007, MSG1_012, -1));
	(*pos)++;
	ft_skip_spaces(line, pos);
	if (line[*pos] != '\0')
		game->r = ft_atoi_cub(line, pos);
	ft_if_comma(line, pos);
	if (line[*pos] != '\0')
		game->g = ft_atoi_cub(line, pos);
	ft_if_comma(line, pos);
	if (line[*pos] != '\0')
		game->b = ft_atoi_cub(line, pos);
	ft_skip_spaces(line, pos);
	if (line[*pos] != '\0' || game->r > 255 || game->g > 255
		|| game->b > 255 || game->r < 0 || game->g < 0 || game->b < 0)
		exit(ft_put_error(TIT_007, MSG1_013, -1));
	*color = game->r * 256 * 256 + game->g * 256 + game->b;
	return (0);
}

static int	takeline(t_game_draw *mygame, char *line)
{
	char	*temp2;
	char	*temp;

	if (mygame->map_read != 1)
	{
		mygame->map_read = 1;
		if (ft_prerequisites(mygame) == -1)
			exit(ft_put_error(TIT_008, MSG1_014, -1));
	}
	temp = ft_strjoin(line, "\n");
	temp2 = mygame->mapchar;
	mygame->mapchar = ft_strjoin(mygame->mapchar, temp);
	free(temp);
	temp = NULL;
	free(temp2);
	temp2 = NULL;
	return (0);
}

int	get_info(t_game_draw *g, char *l)
{
	if (l[g->pos] == 'R' && sp(l[g->pos + 1]) == 1)
		g->n_err = ft_resolution(g, l, &g->pos);
	else if (l[g->pos] == 'N' && l[g->pos + 1] == 'O' && sp(l[g->pos + 2]) == 1)
		g->n_err = ft_chk_texture(g, l, "NO", g->pos);
	else if (l[g->pos] == 'S' && l[g->pos + 1] == 'O' && sp(l[g->pos + 2]) == 1)
		g->n_err = ft_chk_texture(g, l, "SO", g->pos);
	else if (l[g->pos] == 'W' && l[g->pos + 1] == 'E' && sp(l[g->pos + 2]) == 1)
		g->n_err = ft_chk_texture(g, l, "WE", g->pos);
	else if (l[g->pos] == 'E' && l[g->pos + 1] == 'A' && sp(l[g->pos + 2]) == 1)
		g->n_err = ft_chk_texture(g, l, "EA", g->pos);
	else if (l[g->pos] == 'S' && sp(l[g->pos + 1]) == 1)
		g->n_err = ft_chk_texture(g, l, "SP", g->pos);
	else if (l[g->pos] == 'F' && sp(l[g->pos + 1]) == 1)
		g->n_err = getcolor(&g->stat_txt.floor, l, &g->pos, g);
	else if (l[g->pos] == 'C' && sp(l[g->pos + 1]) == 1)
		g->n_err = getcolor(&g->stat_txt.ceil, l, &g->pos, g);
	else if ((l[g->pos] == '1' || l[g->pos] == '0' || g->n_err == 1))
		g->n_err = takeline(g, l);
	else if (l[g->pos] == '\0' && g->map_read == 1)
		g->n_err = takeline(g, " ");
	else if (l[g->pos] == '\0' && g->map_read == 0)
		g->n_err = 0;
	return (ft_n_err(g->n_err));
}
