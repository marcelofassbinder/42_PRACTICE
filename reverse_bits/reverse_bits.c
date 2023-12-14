/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:54:12 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/06 16:08:47 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char aux;
	unsigned char bit = 0;
	int i = 0;

	while(i < 8)
	{
		aux = octet % 2;
		bit = bit << 1;
		bit = bit | aux;
		octet = octet >> 1;
		i++;
	}
	return (bit);
}

#include <stdio.h>

int main()
{
	printf("%i", reverse_bits(8));
}