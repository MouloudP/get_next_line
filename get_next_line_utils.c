/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdoun <ahamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:34:21 by ahamdoun          #+#    #+#             */
/*   Updated: 2021/09/13 11:06:49 by ahamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char		*ft_strdup(const char *s1)
{
	char		*copy;
	int			i;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int			count;
	int			n;
	char		*str;

	count = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(str = (char *)malloc(sizeof(char) * count)))
		return (NULL);
	count = 0;
	n = 0;
	while (s1 && s1[n])
		str[count++] = s1[n++];
	n = 0;
	while (s2 && s2[n])
		str[count++] = s2[n++];
	str[count] = '\0';
	return (str);
}

char		*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;
	
	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strchr(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (c))
		return ((char *)s + i);
	return (NULL);
}
