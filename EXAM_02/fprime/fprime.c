/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:25:47 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/05 00:39:15 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

void	fprime(int n)
{
	int	i = 2;

	if (n == 1)
	{
		printf("1");
		return ;
	}
	while(n >= i)
	{
		while(n % i == 0)
		{
			n = n / i;
			printf("%i", i);
			if (n != 1)
				printf("*");
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
}