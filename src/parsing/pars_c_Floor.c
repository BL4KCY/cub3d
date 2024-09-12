/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c_Floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:34:10 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/12 15:23:55 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_contain_only_digit(char *str)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			error = -1;
		i++;
	}
	if (error == -1)
		return (-1);
	if (ft_atoi_if(str) == false || ft_atoi(str) > 255)
		return (-1);
	return (0);
}

bool	ft_track_comma(char *str)
{
	int		i;
	int		flag;
	char	**substr;

	flag = 0;
	i = 0;
	if (ft_count_specific_char(str, ',') == 2)
	{
		substr = ft_split(ft_substr(ft_strtrim(str, " "),
					find_specific_char(str, ' ') + 1, ft_strlen(str)), ',');
		while (substr[i])
		{
			if (ft_contain_only_digit(ft_strtrim(substr[i], " ")) == -1)
				flag = -1;
			i++;
		}
	}
	else
		return (false);
	if (flag == -1 && ft_count_substr(substr) != 2)
		return (false);
	return (true);
}

bool	ft_pars_colors(t_list *node)
{
	t_list	*temp;

	if (!node)
		return (false);
	temp = node;
	while (temp)
	{
		if (ft_track_comma(temp->content) == true)
			temp = temp->next;
		else
			return (false);
	}
	return (true);
}

bool	ft_spin(const char *str)
{
	size_t	str_len;
	char	**substr;

	if (!str)
		return (false);
	substr = ft_split(ft_strtrim(str, " "), ' ');
	if (!substr)
		return (false);
	str_len = ft_strlen(str);
	return (ft_strncmp(substr[0], "C", str_len) == 0
		|| ft_strncmp(substr[0], "F", str_len) == 0);
}

bool ft_find_color(char *str, char c)
{
	if (!str)
		return (false);
	if (ft_strrchr(str, c))
		return (true);
	return (false);
}

void ft_import_colors(t_list *floor, t_list *ceiling, t_condition *condition)
{
	char **floor_substr;
	char **ceiling_substr;
	floor_substr = ft_buffer_to_two_d_array(floor, ft_lstsize(floor), 0);
	ceiling_substr = ft_buffer_to_two_d_array(ceiling, ft_lstsize(ceiling), 0);

	condition->floor_color = rgb_int(ft_atoi(floor_substr[0]),
				ft_atoi(floor_substr[1]), ft_atoi(floor_substr[2]));

	condition->ceiling_color = rgb_int(ft_atoi(ceiling_substr[0]),
				ft_atoi(ceiling_substr[1]), ft_atoi(ceiling_substr[2]));
}
void ft_node_colors(t_list *node, t_condition *condition)
{
	t_list *current;
	t_list *floor;
	t_list *ceiling;
	char **f;
	char **c;
	(void)condition;
	floor = NULL;
	ceiling = NULL;
	current = node;
	f = NULL;
	c = NULL;
	while (current)
	{
		if (ft_find_color(current->content, 'F') == true)
			f = ft_split(current->content + 3, ',');
		else if (ft_find_color(current->content, 'C') == true)
			c = ft_split(current->content + 3, ',');
		current = current->next;
	}
	floor = ft_add_substrings_to_linked_list(floor, f, 1);
	ceiling = ft_add_substrings_to_linked_list(ceiling, c, 1);
	ft_import_colors(floor, ceiling, condition);
}
bool	ft_to_do_c_floor(t_list *node, t_condition *condition)
{
	t_list	*temp;

	(void)condition;
	temp = node;
	while (temp)
	{
		if (ft_spin((char *)temp->content) == true)
			temp = temp->next;
		else
			return (false);
	}
	if (ft_lstsize(node) != 2)
		return (false);
	if (ft_duplicates(node) == false)
		return (false);
	if (ft_pars_colors(node) == false)
	{
		return (false);
	}
	ft_node_colors(node, condition);
	ft_putnbr_fd(condition->floor_color, 1);
	printf("\n");
	ft_putnbr_fd(condition->ceiling_color, 1);
	printf("\n");
	return (true);
}

