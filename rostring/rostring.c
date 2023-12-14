/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:35:33 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/02 17:52:55 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_putstr(char *str)
{
	int i;
	int flag;
	
	flag = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	while(str[i])
	{
		while ((str[i] == ' ' || str[i] == '	') && (str[i + 1] == ' ' || str[i + 1] == '	'))
			i++; 
		if (!((str[i] == ' ' || str[i] == '	') && (str[i + 1] == '\0')))
		{
			write(1, &str[i], 1);
			flag = 1;
		}
		i++;
	}
	return(flag);
}


void	rostring(char *str)
{
	int i;
	int j;
	char *first = NULL;
	int flag;

	flag = 0;
	i = 0;
	while(str[i] == ' ' || str[i] == '	')
		i++;
	j = i;
	while(str[j])
	{
		if (str[j + 1] == '\0')
		{
			ft_putstr(&str[i]);
			break;
		}
		else if((str[j] != ' ' && str[j] != '	') && (str[j + 1] == ' ' || str[j + 1] == '	'))
		{
			flag = ft_putstr(&str[j + 1]);
			if (flag == 1)
				write(1, " ", 1);
			first = malloc((char) j);
			if (!first)
				free(first);
			i = -1;
			while(i++ < j)
				first[i] = str[i];
			first[i] = '\0';
			break;
		}
		else 
			j++;
	}
	if (first)
	{
		ft_putstr(first);
		free (first);
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "\n", 1);
	else
		rostring(argv[1]);
}	