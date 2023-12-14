/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:00 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/01 16:58:37 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	size_array(int start, int end)
{
	int	size;

	if(start >= 0 && end >= 0)
		size = end - start + 1;
	else if (start <= 0 && end >= 0)
		size = end - start + 1;
	else if (start <= 0 && end <= 0)
		size = (-1) * (start - end - 1);
	return(size);
}

void	ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	*ft_range(int start, int end)
{
	int	*array;
	int size;
	int	i;

	if(start > end)
	{
		ft_swap(&start, &end);
		size = size_array(start, end);
		array = (int *)malloc(sizeof(int) * size);
		i = 0;
		while (i < size)
		{
			array[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		size = size_array(start, end);
		array = (int *)malloc(sizeof(int) * size);
		i = 0;
		while (i < size)
		{
			array[i] = start;
			i++;
			start++;
		}
	}
	return(array);
}
/* #include <stdio.h>

int main()
{
	int *ptr;
	int i = 0;

	ptr = ft_range(0, -3);
	while (i < 4)
	{
		printf("%i ", ptr[i]);
		i++;
	}
} */