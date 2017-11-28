#include<stdio.h>
#include<math.h>

int main(){
	int l, u, i;
	char choice;
	do{
	printf("\nEnter the upper and lower limit : ");
	scanf("%d%d", &l, &u);
	if(l > u){
		int bak = l;
		l = u;
		u = bak;
	}
	printf("\nThe prime numbers in the range %d - %d are : ", l, u);
	for(i = l; i< u; i++){
		int flag = 0, j = 0;
		for(j = 2; j < sqrt(i); j++){
			if(i % j==0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf(" %d", i);
		}
	}
	printf("\nDo you want to continue ? (y/n):");
	scanf(" %c", &choice);
	}
	while(choice == 'Y' || choice == 'y');
	return 0;
}
