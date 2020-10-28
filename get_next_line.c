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
#include "libft/libft.h"
#include <stdio.h>

// static				int ft_valid_fd(const int fd)
// {
// 	if (fd == -1)
// 		return (-1);
// 	else
// 		return (0);
// }
int		essais2(char *str)
{
/*recherche '\n' en partant du debut et renvoie la chaine sans '\n' */
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	essais3(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[i] != '\n')
			ft_putchar(str[i]);
		else
			ft_putstr("\\n");
		i++;
	}
}

int				trait_tmp(char **tmp, char **str)
{
	int i = 0;
	int	j = 0;

	ft_putstr("-----------------------\n");
	ft_putstr("Traitement de tmp -> str: \n\ttmp = '");
	essais3(*tmp);
	ft_putstr("'");
	if (ft_strlen(*tmp) > 0)
	{
		while ((*tmp)[i])
		{
			if ((*tmp)[i] != '\n')
			{
				(*str)[j] = (*tmp)[i];
				j++;
			}
			else if (i > 0)
			{
				ft_putstr("\t --> Nouvelle ligne --> '");
				(*str)[j] = '\0';
				ft_putstr(*str);
				ft_putstr("'\n\t tmp = '");
				(*tmp) = ft_strdup(&(*tmp)[i + 1]);
				essais3(*tmp);
				ft_putstr("'\n");
				return (1);
			}
			i++;
		}
	}
	(*str)[j] = '\0';
	ft_putstr("\nTraitement terminé ...\n");
	ft_putstr("'\n\t tmp = '");
	essais3(*tmp);
	ft_putstr("'\tet str = '");
	essais3(*str);
	ft_putstr("'\n-------------------\n");
	return (0);
}

int					read_file(const int fd, char **tmp, char **str)
{
	int				result;
	char			buffer[BUFF_SIZE + 1];
	int				eof;

	printf("lecture fichier...");
	while ((result = read(fd, buffer, BUFF_SIZE)) > 0 && !ft_strchr(buffer,'\n'))
	{
		buffer[result] = '\0';
		(*str) = ft_strjoin(*str, buffer);
	}
	if (result < BUFF_SIZE)
	{
		buffer[result] = '\0';
		eof = TRUE;
	}
	else
		eof = FALSE;
	(*tmp) = ft_strdup(buffer);
	return (eof);
}

int					get_next_line(const int fd, char **line)
{
	//int				result;
	char			*str;
	static char		*tmp = "";
	int 	pos_nl;
	int		eof;

	if (fd == -1 || line == NULL)
		return (-1);
	str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!str)
		return (-1);

	if (trait_tmp(&tmp, &str))
	{
		(*line) = str;
		return (1);
	}
	eof = read_file(fd, &tmp, &str);
	//tmp = ft_strdup(buffer);
	pos_nl = essais2(tmp);
	ft_putstr("\n\t tmp = '");
	essais3(tmp);
	ft_putstr("'\tet str = '");
	essais3(str);
	// ft_putstr("'\tet buffer = '");
	// essais3(buffer);
	// ft_putstr("'\n");
	
	
	
	printf("\npos_nl = %d\n", pos_nl);	
	printf(">EOF = %d\n", eof);
	// printf("\t'\\n' en position %d dans tmp",pos_nl);

	if (pos_nl >= 0)
	{
		str = ft_strncat(str, tmp, pos_nl);
		tmp = ft_strdup(&tmp[pos_nl + 1]);
		(*line) = str;
	}
/*
	if (pos_nl == 0)
	{
		// le premier carractère prochain du buffer est sau de ligne
		donc on peut sortir on a une ligne
		(*line) = str;
		if (ft_strlen(tmp) > 1)
		{
			//il reste des choses dans le buffer 
			tmp = ft_strdup(&tmp[1]);
			sortie = 1;
		}
		else if (eof)
			sortie = 0;
		else
			sortie = 1;
	}
	else if (pos_nl > 0)
	{
		str = ft_strncat(str, tmp, pos_nl);
		tmp = ft_strdup(&tmp[pos_nl + 1]);
		(*line) = str;
		
		if (ft_strlen(&tmp[pos_nl + 1]) > 0)
			sortie = 1;
		else if (eof)
			sortie = 0;
		else
			sortie = 1;
	}
*/
	else //(pos_nl == -1)
	{
		if (ft_strlen(str) > 0)
			(*line) = str;
	}

	ft_putstr("\n## Avant sortie ##:\n\t tmp = '");
	essais3(tmp);
	ft_putstr("'\tet str = '");
	essais3(str);
	// ft_putstr("'\tet buffer = '");
	// essais3(buffer);
	// ft_putstr("'\n");
	free(str);
	if (eof && ft_strlen(tmp) == 0)
		return (0);
	else 
		return (1);
}
