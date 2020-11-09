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

static char			*recup_line(char *str)
/* revoie une chaine malloc de la premiere ligne de str ou str si aucun'\n'*/
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

static char			*save_static(char *str)
/* tronc str de la premiere ligne rencontrée et renvoi un malloc*/
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

int					get_next_line(const int fd, char **line)
{
	static char		*str_static;
	char			*buffer;
	int				result;

	/* 
	On verifie fd, line et buffer_size :  => -1 si problemes
	*/
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	/*
	on alloue un buffer de la taille de buffer_size
	*/
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	/* tanque str_static ne contient pas un '\n' et que la lecture n'a pas renvoyé 0 (result)
	*/
	result = 1;
	while (!nl_line(str_static) && result != 0)
	{
		/* on lit un paquet de BUFFER_SIZE oct*/
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[result] = '\0';
		/* on rajoute ce paquet à la variable static*/
		str_static = ft_strjoin(str_static, buffer);
	}
	free(buffer);
	/* on recupere la line a renvoyer */
	*line = recup_line(str_static);
	/* on tronc la variable static de la ligne renvoyé */
	str_static = save_static(str_static);
	/* si la lecture a renvoyer 0 on renvoie 0 */
	if (result == 0)
		return (0);
	/* sinon c'est qu'il y a encore quelque chose à renvoyer*/
	return (1);
}
