/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:25:25 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/14 22:22:32 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int index_base(char c, int str_base)
{
	int i = 0;
	char *low = "0123456789abcdef";
	char *up = "0123456789ABCDEF";

	while(i < str_base)
	{
		if (c == low[i] || c == up[i])
			return(i);
		i++;
	}
	return(0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int signal = 1;
	int number = 0;
	
	if (str[0] == '-')
		signal = -1;
	while(str[i] >= '0' && str[i] <= '9' || 
		str[i] >= 'a' && str[i] <= 'f' || 
		str[i] >= 'A' && str[i] <= 'F')
	{
		number = (number * str_base) + index_base(str[i], str_base);
		i++;
	}
	return(number * signal);
}
#include<stdio.h>

int main(void)
{
	printf("%i", ft_atoi_base("100", 2));
}