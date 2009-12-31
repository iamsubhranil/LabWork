#include <stdio.h>

int main(){
	FILE *f1, *f2, *f3;
	int t, i, n;
	printf("\nHow many numbers you want to store : ");
	scanf("%d", &n);
	printf("\nContent of data file : ");
	f1 = fopen("data.txt", "w");
	for(i = 0;i < n;i++){
		printf("\nEnter number : ");
		scanf("%d", &t);
		if(t == -1){
			break;
		}
		else{
			fprintf(f1, "%d ", t);
		}
	}
	fclose(f1);
	f1 = fopen("data.txt", "rb");
	f2 = fopen("data_even.txt", "w");
	f3 = fopen("data_odd.txt", "w");
	while(fscanf(f1, "%d", &t) != EOF){ // read from data file
		if(t % 2 == 0)
			fprintf(f2, "%d ", t); // write to even file
		else
			fprintf(f3, "%d ", t); // write to odd file
	}
	fcloseall();
	f2 = fopen("data_even.txt", "rb");
	f3 = fopen("data_odd.txt", "rb");
	printf("\nContents of odd file : \n");
	while(fscanf(f3, "%d", &t) != EOF)
		printf("%d ", t);
	printf("\nContents of even file : \n");
	while(fscanf(f2, "%d", &t) != EOF)
		printf("%d ", t);
	printf("\n");
	return 0;
}
