/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:58:47 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/02 19:07:01 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *str)
{
	int i = 0;
	while(str[i] == ' ' || str[i] == '	')
		i++;
	while(str[i])
	{
		if(str[i] != ' ' && str[i] != '	')
		{
			write(1, &str[i], 1);
			i++;
		}
		else break;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write (1, "\n", 1);
}