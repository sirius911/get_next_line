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

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(const int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
