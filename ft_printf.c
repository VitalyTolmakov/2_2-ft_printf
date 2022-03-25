/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:12:54 by fheidi            #+#    #+#             */
/*   Updated: 2021/12/18 14:07:05 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	print_argum(void *argum, char perc_argum, size_t *len)
{
	if (!argum && (perc_argum == 's'))
		ft_putstr("(null)", len);
	else if (perc_argum == 'c')
		ft_putchar((char)argum, len);
	else if (perc_argum == 's')
		ft_putstr((char *)argum, len);
	else if (perc_argum == 'd' || perc_argum == 'i')
		if_minus_decimal((int)argum, 10, "0123456789", len);
	else if (perc_argum == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr_base_u((unsigned long int)argum, 16, "0123456789abcdef", len);
	}
	else if (perc_argum == 'x')
		ft_putnbr_base_u((unsigned int)argum, 16, "0123456789abcdef", len);
	else if (perc_argum == 'X')
		ft_putnbr_base_u((unsigned int)argum, 16, "0123456789ABCDEF", len);
	else if (perc_argum == 'u')
		ft_putnbr_base_u((unsigned int)argum, 10, "0123456789", len);
}

int	ft_printf(const char *str, ...)
{
	va_list	argum;
	size_t	len;

	len = 0;
	va_start(argum, str);
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &len);
		else if (*str == '%' && *(str + 1) && *(str + 1) == '%')
		{
			ft_putchar('%', &len);
			str++;
		}
		else if (*str == '%' && *(str + 1) && *(str + 1) != '%')
			print_argum(va_arg(argum, void *), *(++str), &len);
		str++;
	}
	va_end(argum);
	return (len);
}
