#include <stdio.h>


int main(void)
{
	char str[200], wrd[200], rep[200];
	printf("Enter a sentence: ");
	scanf("%[^\n]s", str);
	printf("Enter target word to replace: ");
	scanf("%s", wrd);
	printf("Enter new word to replace by: ");
	scanf("%s", rep);
	printf("\n");
	
	// Iterate through each char, with word start = 0
	int start = 0, end = 200;
	int i, j, k, is_end = 0;
	for (i = 0; is_end == 0; i++) {
		// If char = ending character, end = i
		if ((str[i] == ' ') || (str[i] == '.') || (str[i] == '\0')) {
			end = i;
			
			// Now, check if each char between 0 and i = each char of wrd.	
			for (j = start; j < end; j++) {
				
			}
			
			if (str[i] == '\0') {
				is_end = 1;
				break;	
			}
			
			start = i+1;
		}
	}
		
	
	return 0;
}
