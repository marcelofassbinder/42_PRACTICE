/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:19:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/01 20:38:59 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;
	int i;

	i = 0;
	n = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n);
}

void	putnbr(int n)
{
	char str;

	if(n >= 10)
		putnbr(n / 10);
	str = n % 10 + '0';
	write(1, &str, 1);
}
int main(int argc, char **argv)
{
	int i = 0;
	int result;

	if (argc == 2)
	{
		while (i++ < 9)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(ft_atoi(argv[1]));
			write (1, " = ", 3);
			result = i * ft_atoi(argv[1]);
			putnbr(result);
			write (1, "\n", 1);
		}
	}
	else
		write (1, "\n", 1);
}

