/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayar <ayar@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:03:33 by zkasmi            #+#    #+#             */
/*   Updated: 2022/07/28 15:52:31 by ayar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcheck(char const *s, char c)
{
	int		check;
	size_t	i;

	i = 0;
	check = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			check++;
			while (s[i] == c && s[i])
			{
				i++;
			}
		}
		i++;
	}
	if (s[0] == c)
		check--;
	if (s[ft_strlen(s) - 1] != c)
	{
		check++;
	}
	return (check);
}

static char	**strfreeup(char **tab, int l)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (i < l)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

static char	*wordprint(const char *str, int switcher, int i)
{
	char	*ptr;
	int		l;

	l = 0;
	ptr = malloc((i - switcher + 1) * sizeof(char));
	while (switcher < i)
	{
		ptr[l] = str[switcher];
		l++;
		switcher++;
	}
	ptr[l] = '\0';
	return (ptr);
}

char	**ft_split1(char const *s, char c, size_t j, char **tab)
{
	int		switcher;
	size_t	i;

	i = 0;
	switcher = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && switcher == -1)
			switcher = i;
		else if ((s[i] == c || i == ft_strlen(s)) && switcher >= 0)
		{
			tab[j] = wordprint(s, switcher, i);
			if (tab[j] == NULL)
				return (strfreeup(tab, j));
			switcher = -1;
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t		j;
	char		**tab;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (wordcheck(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	return (ft_split1(s, c, j, tab));
}
