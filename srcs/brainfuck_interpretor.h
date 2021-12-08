/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_interpretor.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:08 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/08 15:55:07 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_INTERPRETOR_H
# define BRAINFUCK_INTERPRETOR_H

# include <stdlib.h>
# include "libft.h"

# define NB_CASE 30000

void	interpret(char *brainfuck, char *ptr);
void	init_tab(char *tab, int size);

#endif
