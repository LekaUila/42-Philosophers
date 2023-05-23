/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:13:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/28 12:41:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	if (!size)
		return (malloc(0));
	if (!(nmemb * size / size == nmemb))
		return (NULL);
	i = nmemb * size;
	array = malloc(nmemb * size);
	if (!(array))
		return (array);
	while (i--)
		*(((unsigned char *) array) + i) = 0;
	return (array);
}
