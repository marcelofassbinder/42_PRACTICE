/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:23:31 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/14 20:36:58 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

void	expand_str(char *str)
{
	int i = 0;
	int len = ft_strlen(str);

	while(str[i] == ' ' || str[i] == '	')
		i++;
	while(str[len - 1] == ' ' || str[len - 1] == '	')
		len--;
	while(i < len)
	{
		while(str[i] == ' ' || str[i] == '	')
		{ 
			if ((str[i] == ' ' || str[i] == '	') && (str[i + 1] != ' ' && str[i + 1] != '	'))	
				write(1, "   ", 3);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
}