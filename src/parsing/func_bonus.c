#include "cub3d.h"

bool	ft_to_do_map_bonus(t_list *node, t_condition *game_condition)
{
	(void)node;
	int		n_direction;
	char **new_map;
	if (!game_condition->map)
		return (false);
	new_map = fill_modified_map(game_condition->map);
	if (ft_check_up(game_condition->map[0]) == false
		|| ft_check_up(game_condition->map[ft_n_columns_2d(game_condition->map)
				- 1]) == false)
		return (false);
	if (!(ft_check_start_end(game_condition->map, &n_direction, 1) == 0
			&& n_direction == 1))
		return (false);
	if (breadth_first_search(new_map, game_condition) && check_for_dead_ends(new_map))
		return (true);
	return (false);
}

bool	move_on_if_map_valid_bonus(t_condition *condition)
{
	if (condition->substr == NULL)
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	if (ft_grep_to_pars_if('.', condition, ft_to_do_textures)
		&& ft_grep_to_pars_if(',', condition, ft_to_do_c_floor)
		&& ft_grep_to_pars_if('1', condition, ft_to_do_map_bonus))
	{
		printf(GRN_W "[Valid]\n" RESET);
	}
	else
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	return (true);
}

