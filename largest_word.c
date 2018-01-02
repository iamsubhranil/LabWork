#include <stdio.h>

int main(){
	char str[100], maxlen = 0, maxstart = 0, curstart = 0, curlen = 0, i = 0;
	printf("\nEnter the string : ");
	gets(str);
	while(str[i] != 0){
		if(str[i] == ' '){
			if(curlen > maxlen){
				maxlen = curlen;
				maxstart = curstart;
			}
			curlen = 0;
			curstart = i+1;
		}
		else
			curlen++;
		i++;
	}
	printf("\nLength of the largest word : %d", maxlen);
	printf("\nLargest word : ");
	i = maxstart;
	while(str[i] != 0 && str[i] != ' ')
		printf("%c", str[i++]);
	printf("\n");
	return 0;
}
