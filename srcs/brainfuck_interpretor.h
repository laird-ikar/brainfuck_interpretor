/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_interpretor.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:08 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/08 16:44:27 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_INTERPRETOR_H
# define BRAINFUCK_INTERPRETOR_H

# include <stdlib.h>
# include "libft.h"

# define NB_CASE 30000

# ifndef T_LOOP
#  define T_LOOP

typedef struct s_loop
{
	int	level;
	int	index[NB_CASE];
}	t_loop;

# endif

void	interpret(char *brainfuck, char *ptr);
void	init_tab(char *tab, int size);
void	check_loop(t_loop *loop, int *i, char *brainfuck, char *ptr);

#endif
