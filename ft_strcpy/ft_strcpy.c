/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:21:29 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/01 19:28:39 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
} 
/* #include <stdio.h>

int main()
{
	char s1[50] = "ola";
	char s2[] = "tudo";
	printf("%s", ft_strcpy(s1, s2));
} */