/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:54:36 by clorin            #+#    #+#             */
/*   Updated: 2020/10/21 09:55:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int			nl_line(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
**	revoie une chaine malloc de la premiere ligne de str ou str si aucun'\n'
*/

static char			*recup_line(char *str)
{
	int				i;
	char			*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
**	Enlève la premiere ligne rencontrée et renvoi un malloc du reste
**	de la chaine
*/

static char			*save_static(char *str)
{
	int				i;
	int				j;
	char			*dest;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!dest)
		return (NULL);
	i += 1;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

/*
**	1# On verifie fd, line et buffer_size :  => -1 si problemes.
**	2# On alloue un buffer de la taille de buffer_size.
**	3# Tanque str_static ne contient pas un '\n' et que la lecture
**	n'a pas renvoyé 0 (result)
**		- on lit un paquet de BUFFER_SIZE oct.
**		- on rajoute ce paquet à la variable static.
**	4# on recupere la line a renvoyer.
**	5# on tronc la variable static de la ligne renvoyée.
**	6# Si la lecture a renvoyer 0 on renvoie 0
**	   Sinon 1 car il y a quelque chose encore à lire.
*/

int					get_next_line(const int fd, char **line)
{
	static char		*str_static;
	char			*buffer;
	int				result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	result = 1;
	while (!nl_line(str_static) && result != 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[result] = '\0';
		str_static = ft_strjoin(str_static, buffer);
	}
	free(buffer);
	*line = recup_line(str_static);
	str_static = save_static(str_static);
	if (result == 0)
		return (0);
	return (1);
}
