/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:30:07 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:35:29 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_digit(unsigned int n, int fd)
{
	if (n > 0)
	{
		print_digit(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	_n;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		_n = n * -1;
	}
	else
		_n = n;
	print_digit(_n, fd);
}
