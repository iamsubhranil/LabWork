#include <stdio.h>

int main(){
	int n, line = 0, maxstars = 0, mid, stars = 1;
	printf("\nEnter the number of levels : ");
	scanf("%d", &n);
	maxstars = (2*n) - 1;
	mid = maxstars/2 + 1;
	while(line < n){
		int temp = mid;
		while(temp > 0){
			printf(" ");
			temp--;
		}
		temp = 0;
		while(temp < stars){
			printf("*");
			temp++;
		}
		stars += 2;
		mid -= 1;
		printf("\n");
		line++;
	}
	return 0;
}
