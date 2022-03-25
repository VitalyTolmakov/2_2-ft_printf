/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:44:09 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/18 13:49:50 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, size_t *len)

{
	write(1, &c, 1);
	*len = *len + 1;
}

int	ft_putstr(char *s, size_t *len)
{
	if (!s)
		return (0);
	while (*s)
	{
		write(1, s, 1);
		*len = *len + 1;
		s++;
	}
	return (1);
}

void	ft_putnbr_base(long int nbr, int base, char *charset, size_t *len)
{
	if (nbr >= base)
		ft_putnbr_base(nbr / base, base, charset, len);
	write(1, &charset[nbr % base], 1);
	*len = *len + 1;
}

void	if_minus_decimal(int nbr, int base, char *charset, size_t *len)
{
	if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr_base((long int)nbr * (-1), base, charset, len);
	}
	else
		ft_putnbr_base((long int)nbr, base, charset, len);
}

void	ft_putnbr_base_u(unsigned long int nbr, unsigned int base,
			char *charset, size_t *len)
{
	if (nbr >= base)
		ft_putnbr_base(nbr / base, base, charset, len);
	write(1, &charset[nbr % base], 1);
	*len = *len + 1;
}
