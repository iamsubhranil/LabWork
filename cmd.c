// sum to two numbers using command line
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int i, sum = 0;
	if(argc != 3){
		printf("\nWrong arguments!");
		return 1;
	}
	printf("\nSum is : ");
	for(i = 1;i < argc;i++){
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return 0;
}
