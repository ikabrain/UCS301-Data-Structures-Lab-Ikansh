#include <stdio.h>

#define MAX 100

void concat(char s1[], char s2[])
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
}

int main(void)
{
	char s1[MAX], s2[MAX];
	printf("Enter string 1: ");
	scanf("%s", &s1);
	printf("Enter string 2: ");
	scanf("%s", &s2);
	
	concat(s1, s2);
	
	printf("\nConcatenated string = %s\n", s1);
	return 0;
}
