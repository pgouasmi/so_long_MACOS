/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:11:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/05/22 14:29:13 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_whitespace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

static int	ft_str_has_wrong_char(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_is_whitespace(str[i]))
			return (1);
		while (set[j])
		{
			if (str[i] == set[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_parse_arg(const char *str)
{
	size_t	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4))
		return (1);
	if (ft_str_has_wrong_char(str, "#<>$+%%!*|{}?\\\"/:@&"))
		return (1);
	return (0);
}

int	ft_str_same_char_str(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
