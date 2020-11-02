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

size_t				ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int			nl_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*nl_stack;
	int				i;

	i = 0;
	nl_stack = *stack;
	while (nl_stack[i] != '\n')
	{
		if (nl_stack[i] == '\0')
			return (0);
		i++;
	}
	tmp_stack = &nl_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	if (*line == NULL)
		*line = "";
	return (1);
}

static	int			read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (nl_line(stack, line))
			break ;
	}
	if (ret > 0)
		return (1);
	else
		return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stack;
	char			*heap;
	int				i;
	int				ret;

	//printf("stack en entrée : %s\n", stack);
	if (!line || fd < 0 || (read(fd, stack, 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (stack)
		if (nl_line(&stack, line))
		{
			free (heap);
			return (1);
		}
	i = 0;
	while (i < BUFFER_SIZE)
		heap[i++] = '\0';
	ret = read_file(fd, heap, &stack, line);
	free(heap);
	//printf("ret= %d, stack = <%s>, line = <%s>\n", ret, stack, *line);
	if (ret != 0 || stack == NULL || stack[0] == '\0')
	{
		if (!ret) //&& *line
			*line = ""; //NULL
		return (ret);
	}
	*line = stack;
	stack = NULL;
	//printf("stack en sortie : %s\n", stack);
	return (ret);
}
