/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:44:33 by mfassbin          #+#    #+#             */
/*   Updated: 2023/11/27 20:06:48 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	repeat_alpha(char *str)
{
	int i;
	int n;

	i = 0;
	while (str[i])
	{	
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			n = 0;
			while (n++ < str[i] - 96)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			n = 0;
			while (n++ < str[i] - 64)
				write(1, &str[i], 1);
		}
		else 
			write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{	
	if (argc == 2)
		repeat_alpha(argv[1]);
	write (1, "\n", 1);
}