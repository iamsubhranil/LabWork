#include <stdio.h>
#include <stdlib.h>

int * binary_search(int *array, int key, int low, int high){
	int mid = (low+high)/2;
	int *res = NULL;
	if(array[mid] == key){
		res = (int *)malloc(sizeof(int) * 2);		
		res[0] = 1;
		res[1] = mid;
	}
	else if(low > high){
		res = (int *)malloc(sizeof(int) * 1);
		res[0] = 0;
	}
	else{
		if(array[mid] > key)
			high = mid -1;
		else
			low = mid + 1;
		res = binary_search(array, key, low, high);
	}
	return res;
}

int * bubble_sort(int *a, int count){
	int i = 0;
	for(i = 0; i < count - 1; i++){
		int j = 0;
		for(j = 0; j < (count - i - 1) ; j++){
			if(a[j+1] < a[j]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	return a;
}

int * linear_search(int *array, int size, int key){
	int temp = 0;
	int *res = (int *)malloc(sizeof(int) * 2);
	res[0] = 0;
	while(temp < size && array[temp] <= key){
		if(array[temp] == key){
			res[0] = 1;
			res[1] = temp;
			break;
		}
		temp++;
	}
	return res;
}

void print_res(int *res, int key){
	if(res[0] == 0){
		printf("\n%d is not found in the array!", key);
	}
	else{
		printf("\n%d's first occurrence in the array is at position %d!", key, (res[1] + 1));
	}
}

int main(){
	int *array = NULL, count = 0, temp = 0, key;
	printf("\nEnter the number of elements : ");
	scanf("%d", &count);
	if(count <= 0){
		printf("\nNumber of elements should be positive");
		return 1;
	}
	array = (int *)malloc(sizeof(int) * count);
	while(temp < count){
		printf("\nEnter element %d : ", (temp + 1));
		scanf("%d", &array[temp]);
		temp++;
	}
	array = bubble_sort(array, count);
	temp = 0;
	printf("\nAfter sorting : ");
	while(temp < count){
		printf(" %d", array[temp]);
		temp++;
	}

	printf("\nEnter element to search : ");
	scanf("%d", &key);
	int c = 1;
	while(c){
		char choice;
		printf("\n(B)inary search");
		printf("\n(L)inear search");
		printf("\n[CHOICE] ");
		scanf(" %c", &choice);
		switch(choice){
			case 'L':
			case 'l':
				print_res(linear_search(array, count, key), key);
				break;
			case 'B':
			case 'b':
				print_res(binary_search(array, key, 0, count - 1), key);
				break;
			default: 
				c = 0;
				break;
		}
	}
	printf("\n");
	free(array);
	return 0;
}
