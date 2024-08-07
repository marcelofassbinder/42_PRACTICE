/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:27:51 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/06 15:11:50 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>


int ft_len(int n)
{
	int len = 1;

	if(n < 0)
	{
		len ++;
		n = n * (-1);
	}
	if (n >= 0)
	{
		while(n >= 10)
		{
			n = n /10;
			len ++;
		}
	}
	return(len);
}

char *ft_itoa(int nbr)
{
	char	*s;
	int len;

	len = ft_len(nbr);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return(NULL);
	if (nbr < 0)
	{
		s[len] = '\0';
		s[0] = '-';
		nbr = nbr * (-1);
		while(len - 1 > 0)
		{
			s[len - 1] = nbr % 10 + 48;
			nbr = nbr / 10;
			len --;
		}
	}
	else
	{
		s[len] = '\0';
		while(len--)
		{
			s[len] = nbr % 10 + 48;
			nbr = nbr / 10;
		}
	}
	return(s);
}
/* 
#include<stdio.h>

int main()
{
	printf("%s", ft_itoa(-10));
} */