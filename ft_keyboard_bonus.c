/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 02:44:05 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/29 12:48:40 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

void	w_and_s(t_game_draw *mygame)
{
	if (mygame->key.w_status == 1)
	{
		if (mygame->worldmap[(int)(mygame->rc.posx + mygame->rc.dirx
					* mygame->rc.movespeed)][(int)mygame->rc.posy] == 48)
			mygame->rc.posx += mygame->rc.dirx * mygame->rc.movespeed;
		if (mygame->worldmap[(int)mygame->rc.posx][(int)(mygame->rc.posy
						+ mygame->rc.diry * mygame->rc.movespeed)] == 48)
			mygame->rc.posy += mygame->rc.diry * mygame->rc.movespeed;
	}
	if (mygame->key.s_status == 1)
	{
		if (mygame->worldmap[(int)(mygame->rc.posx - mygame->rc.dirx
					* mygame->rc.movespeed)][(int)mygame->rc.posy] == 48)
			mygame->rc.posx -= mygame->rc.dirx * mygame->rc.movespeed;
		if (mygame->worldmap[(int)mygame->rc.posx][(int)(mygame->rc.posy
						- mygame->rc.diry * mygame->rc.movespeed)] == 48)
			mygame->rc.posy -= mygame->rc.diry * mygame->rc.movespeed;
	}
}

void	a_and_d(t_game_draw *mygame)
{
	if (mygame->key.d_status == 1)
	{
		if (mygame->worldmap[(int)(mygame->rc.posx + mygame->rc.planex
					* mygame->rc.movespeed)][(int)mygame->rc.posy] == '0')
			mygame->rc.posx += mygame->rc.planex * mygame->rc.movespeed;
		if (mygame->worldmap[(int)mygame->rc.posx]
			[(int)(mygame->rc.posy + mygame->rc.planey
						* mygame->rc.movespeed)] == '0')
			mygame->rc.posy += mygame->rc.planey * mygame->rc.movespeed;
	}
	if (mygame->key.a_status == 1)
	{
		if (mygame->worldmap[(int)(mygame->rc.posx - mygame->rc.planex
					* mygame->rc.movespeed)][(int)mygame->rc.posy] == '0')
			mygame->rc.posx -= mygame->rc.planex * mygame->rc.movespeed;
		if (mygame->worldmap[(int)mygame->rc.posx][(int)(mygame->rc.posy
						- mygame->rc.planey * mygame->rc.movespeed)] == '0')
			mygame->rc.posy -= mygame->rc.planey * mygame->rc.movespeed;
	}
}

void	l_and_r(t_game_draw *kbd)
{
	if (kbd->key.rg_status == 1)
	{
		kbd_right(kbd);
	}
	if (kbd->key.lf_status == 1)
	{
		kbd->rc.olddirx = kbd->rc.dirx;
		kbd->rc.dirx = kbd->rc.dirx * cos(kbd->rc.rotspeed)
			- kbd->rc.diry * sin(kbd->rc.rotspeed);
		kbd->rc.diry = kbd->rc.olddirx * sin(kbd->rc.rotspeed)
			+ kbd->rc.diry * cos(kbd->rc.rotspeed);
		kbd->rc.oldplanex = kbd->rc.planex;
		kbd->rc.planex = kbd->rc.planex * cos(kbd->rc.rotspeed)
			- kbd->rc.planey * sin(kbd->rc.rotspeed);
		kbd->rc.planey = kbd->rc.oldplanex * sin(kbd->rc.rotspeed)
			+ kbd->rc.planey * cos(kbd->rc.rotspeed);
	}
}

int	ft_close(t_game_draw *mygame, int win)
{
	if (win == 1)
	{
		mlx_destroy_image(mygame->mlx_ptr, mygame->canvas);
		mlx_clear_window(mygame->mlx_ptr, mygame->mlx_win);
		mlx_destroy_window(mygame->mlx_ptr, mygame->mlx_win);
	}
	ft_freemap(mygame);
	free(mygame);
	mygame = NULL;
	system("leaks cub3D");
	exit(0);
}

int	deal_key(t_game_draw *mygame)
{
	w_and_s(mygame);
	a_and_d(mygame);
	l_and_r(mygame);
	if (mygame->key.esc_status == 1)
		ft_close(mygame, 0);
	if (!(mygame->key.a_status == 1) && !(mygame->key.d_status == 1)
		&& !(mygame->key.s_status == 1) && !(mygame->key.w_status == 1)
		&& !(mygame->key.dw_status == 1) && !(mygame->key.up_status == 1)
		&& !(mygame->key.lf_status == 1) && !(mygame->key.rg_status == 1)
		&& mygame->fr == 1)
		return (0);
	raycasting(mygame);
	return (1);
}
