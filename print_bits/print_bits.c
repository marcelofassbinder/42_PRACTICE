/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:10:52 by mfassbin          #+#    #+#             */
/*   Updated: 2023/11/27 21:04:26 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i;
	unsigned char bit;

	i = 0;
	while (i < 8)
	{
		bit = (octet << i) & 0b10000000;
		if (bit == 0)
			write (1, "0", 1);
		if(bit == 128)
			write(1, "1", 1);
		i++;
	}
}
/* 
int main()
{
	print_bits(7);
} */