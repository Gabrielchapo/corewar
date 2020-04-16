/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:21:26 by cgiron            #+#    #+#             */
/*   Updated: 2019/09/24 10:22:18 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (256 * 256 * r + 256 * g + b);
}
