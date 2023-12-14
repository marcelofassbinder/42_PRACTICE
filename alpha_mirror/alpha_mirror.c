/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:30:47 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/01 20:16:50 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	alpha_mirror(char *str)
{
	int	i;
	int a;
	int z;

	i = 0;
	while(str[i])
	{	
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			a = 97 - str[i];
			z = 122 - str[i];
			str[i] = str[i] + (a + z);
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			a = 65 - str[i];
			z = 90 - str[i];
			str[i] = str[i] + (a + z);
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n,", 1);
}