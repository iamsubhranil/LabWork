#include <stdio.h>
#include <stdlib.h>

int main(){
	int *array = NULL, count = 0, temp = 0;
	printf("\nEnter the number of elements : ");
	scanf("%d", &count);
	if(count <= 0){
		printf("\nNumber of elements should be positive!");
		return 1;
	}
	array = (int *)malloc(sizeof(int) * count);
	while(temp < count){
		printf("\nEnter element %d : ", (temp + 1));
		scanf("%d", &array[temp]);
		temp++;
	}
	temp = 0;
	while(temp < count){
		if(temp % 2 == 1){
			int tmp2 = array[temp - 1];
			array[temp - 1] = array[temp];
			array[temp] = tmp2;
		}
		temp++;
	}
	temp = 0;
	printf("\nElements after swap : ");
	while(temp < count){
		printf(" %d", array[temp]);
		temp++;
	}
	printf("\n");
	free(array);
	return 0;
}
