/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:36 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/25 16:05:09 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_iswhitespace(int c)
{
	if (c == 32 || (8 < c && c < 14))
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

static int	ft_check_letter(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (-1);
		str++;
	}
	return (0);
}

int	ft_atoiwo(char *str, int *n)
{
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign = -1;
	}
	if (ft_check_letter(str))
		return (-1);
	while (*str > 47 && *str < 58)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (-1);
	}
	*n = nb;
	return (0);
}
/*
return -1 if there is an overflow or charactere error;
*/