/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:44:20 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/29 13:58:55 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	ft_pre_var(t_game_draw *mygame)
{
	ft_bzero(mygame, sizeof(t_game_draw));
	mygame->win.w = 0;
	mygame->win.h = 0;
	mygame->screenshot = 0;
	mygame->rc.dirx = 0;
	mygame->rc.diry = 0;
	mygame->rc.planex = 0;
	mygame->rc.planey = 0;
	mygame->stat_txt.ceil = RGB_NONE;
	mygame->stat_txt.floor = RGB_NONE;
	mygame->dirok = 0;
}

void	ft_init_rc(t_game_draw *mygame)
{
	mygame->canvas = NULL;
	mygame->canvas_ptr = NULL;
	mygame->tx.id = 0;
	mygame->rc.movespeed = 0.10;
	mygame->rc.rotspeed = 0.09;
	if (mygame->screenshot == 0)
	{
		mlx_get_screen_size(mygame->mlx_ptr, &mygame->resx, &mygame->resy);
		if (mygame->win.h > mygame->resy)
			mygame->win.h = mygame->resy;
		if (mygame->win.w > mygame->resx)
			mygame->win.w = mygame->resx;
	}
}

int	read_map(t_game_draw *mygame)
{
	mygame->map_dim.h = get_height(mygame->mapchar);
	mygame->map_dim.w = get_width(mygame->mapchar);
	if (mygame->map_dim.h < 3 || mygame->map_dim.w < 3)
		exit(ft_put_error(TIT_003, MSG1_023, -1));
	ft_changetab(mygame);
	ft_create_matrix(mygame);
	ft_clean_mapchar(mygame);
	return (0);
}

int	read_file(int argc, char *pathname, t_game_draw *mygame)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	fd = ft_chk_read(pathname);
	if (fd < 0)
		return (ft_file_error(fd));
	mygame->mapchar = ft_strdup("");
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		mygame->pos = 0;
		mygame->n_err = -1;
		ft_skip_spaces(line, &mygame->pos);
		if (get_info(mygame, line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (line != NULL)
		line = NULL;
	if (argc == 3 && ret != -1)
		mygame->screenshot = 1;
	return (ret);
}

/*
** function that inits game behaviour
*/

void	ft_init_game(t_game_draw *mygame)
{
	mygame->mlx_ptr = mlx_init();
	if (mygame->mlx_ptr == NULL)
	{
		ft_write_error(TIT_010, MSG1_025);
		return ;
	}
	ft_init_rc(mygame);
	if (ft_load_txt(mygame) == 0)
	{
		if(mygame->screenshot != 1)
		{
			mygame->mlx_win = mlx_new_window(mygame->mlx_ptr, mygame->win.w,
					mygame->win.h, "cub3D");
			mlx_hook(mygame->mlx_win, 2, 1L << 0, pulsed, mygame);
			mlx_hook(mygame->mlx_win, 3, 1L << 1, nopulsed, mygame);
			mlx_hook(mygame->mlx_win, 17, 1L << 17, ft_close, mygame);
			mlx_loop_hook(mygame->mlx_ptr, deal_key, mygame);
			mlx_loop(mygame->mlx_ptr);
		}
		else
			deal_key(mygame);
	}
	else
	{
		ft_write_error("Error al cargar texturas", "compruebe la memoria");
		return ;
	}
}
