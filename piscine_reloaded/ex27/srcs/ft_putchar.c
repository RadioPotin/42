/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:56:24 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 14:29:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_display.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}