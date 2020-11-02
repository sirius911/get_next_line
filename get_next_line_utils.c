/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:18:56 by clorin            #+#    #+#             */
/*   Updated: 2020/10/29 17:18:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strcat(char *dest, const char *src)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (size <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

char		*ft_strdup(const char *str)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(str));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, str));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}