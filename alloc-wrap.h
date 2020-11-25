/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc-wrap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:59:58 by clorin            #+#    #+#             */
/*   Updated: 2020/11/24 17:00:05 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_WRAP_H
# define ALLOC_WRAP_H

typedef struct		s_list
{
	void			*addr;
	int				free;
}					t_list;

# define MAX_MALLOC 10000
#endif
