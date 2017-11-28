// To reverse a string in place

#include <stdio.h>
#include <string.h>

int main(){
	char a[20];
	int i = 0, j = 0, n, index = 0;
	printf("\nEnter the string : ");
	gets(a);
	strcat(a, " "); // adding an extra blank space after the text
	printf("\nOriginal text : %s", a);
	printf("\nIn-place reversed text : ");
	for(i = 0;a[i] != 0;i++){
		if(a[i] == ' '){ // Word separated
			for(j = i - 1;j >= index;j--) // Printing word in reverse order
				printf("%c", a[j]);
			index = i+1;
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
