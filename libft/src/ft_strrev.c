/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:26:40 by cgiron            #+#    #+#             */
/*   Updated: 2018/11/13 15:35:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	stock;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	j--	;
	while (i < j)
	{
		stock = str[i];
		str[i] = str[j];
		str[j] = stock;
		j--;
		i++;
	}
	return (str);
}
