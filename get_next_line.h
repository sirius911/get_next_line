/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:32:17 by clorin            #+#    #+#             */
/*   Updated: 2020/10/21 09:36:16 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

#define BUFF_SIZE 32
#define FALSE 0
#define TRUE 1
#define DEBUG FALSE

int	get_next_line(const int fd, char **line);

#endif
