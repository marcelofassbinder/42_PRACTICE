/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:59:09 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/06 14:21:35 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int n = 0;
	
	while(str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return(n);
}

void	putnbr(int n)
{
	char a;

	if(n >= 10)
		putnbr(n / 10);
	a = n % 10 + 48;
	write(1, &a, 1);
}

int	isprime(int n)
{
	int i = 2;

	if(n == 1)
		return(0);
	while(i < n)
	{
		if (n % i == 0)
			return(0);
		i++;
	}
	return(1);
}
int	add_prime_sum(int n)
{
	int i = 2;
	int sum = 0;

	while(i <= n)
	{
		if (isprime(i))
			sum = sum + i;
		i++;
	}
	return(sum);
}
#include<stdio.h>

int main(int argc, char **argv)
{
	if(argc == 2)
		putnbr(add_prime_sum(ft_atoi(argv[1])));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}