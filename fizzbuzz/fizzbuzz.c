/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:23:06 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/01 14:37:58 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char	a;

	if(n > 10)
		putnbr(n / 10);
	a = n % 10 + '0';
	write(1, &a, 1);
}

void	fizzbuzz(void)
{
	int i;

	i = 0;
	while (i++ < 100)
	{
		if(i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 != 0 && i % 5 != 0)
			putnbr(i);
		write(1, "\n", 1);
	}
}

int main()
{
	fizzbuzz();
}