/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:58:07 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/18 13:49:06 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, size_t *len);
int		ft_putstr(char *s, size_t *len);
void	if_minus_decimal(int nbr, int base, char *charset, size_t *len);
void	ft_putnbr_base(long int nbr, int base, char *charset, size_t *len);
void	ft_putnbr_base_u(unsigned long int nbr, unsigned int base,
			char *charset, size_t *len);

#endif
