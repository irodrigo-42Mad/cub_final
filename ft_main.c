/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 02:23:23 by irodrigo          #+#    #+#             */
/*   Updated: 2021/03/25 11:15:15 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	pulsed(int key, t_game_draw *mygame)
{
	if (key == KEY_W)
		mygame->key.w_status = 1;
	if (key == KEY_S)
		mygame->key.s_status = 1;
	if (key == KEY_A)
		mygame->key.a_status = 1;
	if (key == KEY_D)
		mygame->key.d_status = 1;
	if (key == KEY_LEFT)
		mygame->key.lf_status = 1;
	if (key == KEY_RIGHT)
		mygame->key.rg_status = 1;
	if (key == KEY_DOWN)
		mygame->key.dw_status = 1;
	if (key == KEY_ESC)
		mygame->key.esc_status = 1;
	if (key == KEY_SHIFT)
		mygame->rc.movespeed = 0.35;
	return (0);
}

int	nopulsed(int key, t_game_draw *mygame)
{
	if (key == KEY_W)
		mygame->key.w_status = 0;
	if (key == KEY_S)
		mygame->key.s_status = 0;
	if (key == KEY_A)
		mygame->key.a_status = 0;
	if (key == KEY_D)
		mygame->key.d_status = 0;
	if (key == KEY_LEFT)
		mygame->key.lf_status = 0;
	if (key == KEY_RIGHT)
		mygame->key.rg_status = 0;
	if (key == KEY_DOWN)
		mygame->key.dw_status = 0;
	if (key == KEY_ESC)
		mygame->key.esc_status = 0;
	if (key == KEY_SHIFT)
		mygame->rc.movespeed = 0.12;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_draw	*mygame;

	if (argc == 2 || argc == 3)
	{
		if (parsename(argv[0], "cub3D") == -1)
			exit(ft_put_error(TIT_001, MSG1_001, 1));
		if (parsename(argv[1], ".cub") == -1)
			exit(ft_put_error(TIT_002, MSG1_002, 3));
		if (argc == 3)
		{
			if (parsename(argv[2], "--save") == -1)
				exit(ft_put_error(TIT_002, MSG1_002, 2));
		}
		mygame = malloc(sizeof(t_game_draw));
		if (!mygame)
			exit(ft_put_error(TIT_004, MSG1_005, 4));
		ft_pre_var(mygame);
		if (read_file(argc, argv[1], mygame) != 0)
			exit(ft_put_error(TIT_011, MSG1_026, -1));
		if (read_map(mygame) != -1)
			if (ft_parse_map(mygame) == 1)
				ft_init_game(mygame);
	}
	else
		exit(ft_put_error(TIT_002, MSG1_002, 2));
}
