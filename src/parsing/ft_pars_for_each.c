/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:57:09 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/11 19:04:46 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	process_c_flor(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " ");
	if ((trimmed_str[0] == 'F' && trimmed_str[1] == ' ')
		|| (trimmed_str[0] == 'C' && trimmed_str[1] == ' '))
	{
		return (true);
	}
	return (false);
}

bool	process_textture(char *str)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, " ");
	if ((trimmed_str[0] == 'N' && trimmed_str[1] == 'O'
			&& trimmed_str[2] == ' ') || (trimmed_str[0] == 'E'
			&& trimmed_str[1] == 'A' && trimmed_str[2] == ' ')
		|| (trimmed_str[0] == 'S' && trimmed_str[1] == 'O'
			&& trimmed_str[2] == ' ') || (trimmed_str[0] == 'W'
			&& trimmed_str[1] == 'E' && trimmed_str[2] == ' '))
	{
		return (true);
	}
	return (false);
}

void	ft_process_game_condition(t_list *textures, t_list *c_flor, t_list *map,
		t_condition *game_condition)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (game_condition->substr[i])
	{
		if (!flag && !ft_strtrim(game_condition->substr[i], " 1")[0])
			flag = 1;
		if (process_c_flor(game_condition->substr[i]) == true && !flag)
			ft_lstadd_back(&c_flor,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		else if (process_textture(game_condition->substr[i]) == true && !flag)
			ft_lstadd_back(&textures,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		else
			ft_lstadd_back(&map,
				ft_lstnew(ft_strdup((char *)game_condition->substr[i])));
		i++;
	}
	game_condition->textures = ft_buffer_to_two_d_array(textures,
			ft_lstsize(textures), 0);
	game_condition->c_flor = ft_buffer_to_two_d_array(c_flor,
			ft_lstsize(c_flor), 0);
	game_condition->map = ft_buffer_to_two_d_array(map, ft_lstsize(map), 0);
}

bool	ft_grep_to_pars_if(char ch, t_condition *game_condition,
		bool (*f)(t_list *, t_condition *condition))
{
	t_list	*textures;
	t_list	*c_flor;
	t_list	*map;

	textures = NULL;
	c_flor = NULL;
	map = NULL;
	ft_process_game_condition(textures, c_flor, map, game_condition);
	game_condition->width_of_map = ft_find_longest_line(game_condition->map, &game_condition->height_of_map);
	textures = ft_add_substrings_to_linked_list(textures,
			game_condition->textures);
	game_condition->pure_texture = ft_buffer_to_two_d_array(textures, ft_lstsize(textures), 1);
	game_condition->pure_map = fill_modified_map(game_condition->map);
	ft_find_direction(game_condition->pure_map, &game_condition->y_player, &game_condition->x_player);
	c_flor = ft_add_substrings_to_linked_list(c_flor, game_condition->c_flor);
	if (ch == '.')
		return (f(textures, game_condition));
	else if (ch == ',')
		return (f(c_flor, game_condition));
	else
	{
		if (f(map, game_condition) != true)
			return (false);
	}
	return (true);
}