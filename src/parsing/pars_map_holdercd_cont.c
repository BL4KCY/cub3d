/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_holdercd_cont.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:46:45 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/16 19:04:26 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_double_list(t_list **nodes)
{
	t_list	*temp;

	temp = *nodes;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

char	**ft_buffer_to_two_d_array(t_list *node, int length, int flag)
{
	int		i;
	char	**sub_str;
	t_list	*temp;
	char *new_substr;

	sub_str = (char **)ft_malloc(sizeof(char *) * (length + 1));
	if (!sub_str)
		return (NULL);
	temp = node;
	i = 0;
	while (temp)
	{
		if (flag == 0)
		{
			sub_str[i] = ft_strdup(temp->content);
		}
		else
		{
			new_substr = ft_strtrim(temp->content , " ");
			new_substr = new_substr + find_specific_char(new_substr, ' ');
			sub_str[i] = ft_strdup(ft_strtrim(new_substr, " "));
		}
		if (!sub_str[i])
			return (NULL);
		i++;
		temp = temp->next;
	}
	sub_str[i] = NULL;
	return (sub_str);
}

int	find_specific_char(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_substr(char **substr)
{
	int	i;

	if (!substr)
		return ;
	i = 0;
	while (substr[i])
	{
		printf("[%s]\n", substr[i]);
		i++;
	}
}

int	ft_count_substr(char **substr)
{
	int	i;

	i = 0;
	while (substr[i])
		i++;
	return (i);
}
