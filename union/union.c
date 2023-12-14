#include <unistd.h>


int check_repeat(char *str, char c, int index)
{
	int i = 0;

	while(i < index)
	{
		if(str[i] == c)
			return(0);
		i++;
	}
	return(1);

}
void ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while(s1[i])
		i++;
	while(s2[j])
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = 0;
	i = 0;
	while(s1[i])
	{
		if (check_repeat(s1, s1[i], i) == 1)
			write(1, &s1[i], 1);
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
}