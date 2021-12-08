/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_interpretor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:09 by bguyot            #+#    #+#             */
/*   Updated: 2021/12/08 16:44:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck_interpretor.h"

int	main(int ac, char *av[])
{
	int		i;
	char	*ptr;

	ptr = malloc(sizeof(char) * NB_CASE);
	init_tab(ptr, NB_CASE);
	if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			ft_putstr("===> Brainfuck ");
			ft_putnbr(i);
			ft_putstr(" <===");
			interpret(av[i++], ptr);
		}
		return (0);
	}
	else if (ac == 2)
		interpret(av[1], ptr);
	else
	{
		ft_putstr("No Brainfuck to interpret\n");
		return (-42);
	}
}

void	interpret(char *brainfuck, char *ptr)
{
	int		i;
	t_loop	*loop;

	i = 0;
	loop = malloc(sizeof(t_loop));
	loop->level = 0;
	while (brainfuck[i])
	{
		if (brainfuck[i] == '>')
			ptr++;
		else if (brainfuck[i] == '<')
			ptr--;
		else if (brainfuck[i] == '+')
			(*ptr)++;
		else if (brainfuck[i] == '-')
			(*ptr)--;
		else if (brainfuck[i] == '.')
			ft_putchar(*ptr);
		else if (brainfuck[i] == ',')
			*ptr = ft_getchar();
		else
			check_loop(loop, &i, brainfuck, ptr);
		i++;
	}
}

void	init_tab(char *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	tab[i++] = 0;
}

void	check_loop(t_loop *loop, int *i, char *brainfuck, char *ptr)
{
	if (brainfuck[*i] == '[')
	{
		loop->level++;
		loop->index[loop->level] = *i;
	}
	else if (brainfuck[*i] == ']')
	{
		if (*ptr)
			*i = loop->index[loop->level];
		else
			loop->level--;
	}
}
