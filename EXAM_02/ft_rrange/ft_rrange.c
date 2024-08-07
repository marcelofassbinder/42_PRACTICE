/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:14:12 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/02 20:28:16 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *crescente(int start, int end, int size)
{
	int	*crescente;
	int	i;

	crescente = malloc(sizeof(int) * size);
	if (!crescente)
		return(NULL);
	i = 0;
	while(end <= start)
	{
		crescente[i] = end;
		i++;
		end ++;
	}
	return(crescente);
}
int *decrescente(int start, int end, int size)
{
	int	*decrescente;
	int	i;

	decrescente = malloc(sizeof(int) *size);
	if (!decrescente)
		return(NULL);
	i = 0;
	while(end >= start)
	{
		decrescente[i] = end;
		i++;
		end --;
	}
	return(decrescente);
}

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	size;


	if(start < end)
	{
		size = end - start + 1;
		array = decrescente(start, end, size);
	}
	else if (start > end)
	{
		size = (-1) * (end - start + 1);
		array = crescente(start, end, size);
	}
	if(start == end)
	{
		array = malloc(sizeof(int));
		if(!array)
			return(NULL);
		array[0] = 0;
	}
	return(array);
}
/* 

#include<stdio.h>

int main()
{
	int	*a;
	int i = 0;

	a = ft_rrange(-1, 2932);
	while(i < 2934)
	{
		printf("%i ", a[i]);
		i++;
	}
} */