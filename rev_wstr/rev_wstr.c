#include <unistd.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int words = 1;
	int i = 0;

	if (str == NULL)
		return(0);
	while (str[i] == ' ' || str[i] == '	')
		i++;
	while(str[i])
	{
		if ((str[i] == ' ' || str[i] == '	') && str[i + 1] != ' ' && str[i + 1] != '	' && str[i + 1] != '\0')
			words++;
		i++;
	}
	return(words);
}
int count_bytes(char *str)
{
	int i = 0;

	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '	' && (str[i + 1] != ' ' && str[i + 1] != '	'))
			return(i);
		i++;
	}
	return(i);

}

char	**rev_wstr(char *str)
{
	char **rev;
	int i;
	int j;
	int count = 0;;

	rev = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!rev)
		free(rev);
	i = 0;
	while(*str)
	{	
		if(*str != ' ' && *str != '	')
		{
			count = count_bytes(str);
			rev[i] = malloc(sizeof(char) * (count + 1));
			if (!rev[i])
				free(rev[i]);
			j = 0;
			while(j < count)
			{
				rev[i][j] = *str;
				str++;
				j++;
			}
			rev[i][j] = '\0';
		}
		i++;
		if(*str == '\0')
			break;
		str++;
	}
	rev[i] = NULL;
	return(rev);
}

void putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

#include<unistd.h>

int main(int argc, char **argv)
{
	char **rev;
	int	words;

	words = count_words(argv[1]);
	if (argc == 2)
	{
		rev = rev_wstr(argv[1]);
		while(words > 0)
		{
			putstr(rev[words - 1]);
			if(words != 1)
				write(1, " ", 1);
			words--;
		}
	}
	write(1, "\n", 1);
}