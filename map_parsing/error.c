/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:25:30 by sayar             #+#    #+#             */
/*   Updated: 2022/10/25 21:22:12 by zkasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error(char *error)
{
	write(2, "Error\n", 6);
	if (error != NULL)
		write(2, error, ft_strlen(error));
	exit (1);
}

int	display(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(1);
}

int	print_error_pos(int row, int column, char c)
{
	write(2, "Error\n", 6);
	printf("row : [%d] colmn : [%d] char : [%c]\n", row, column, c);
	exit (1);
}
