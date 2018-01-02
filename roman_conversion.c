#include <stdio.h>

#define CHECK_FOR(BASE, SPECIAL, BASES, SPECIALS) else if(n >= BASE){ \
			if(n >= SPECIAL){ \
				printf(SPECIALS); \
				n -= SPECIAL; \
			} \
			else{ \
				printf(BASES); \
				n -= BASE; \
			} \
		}

int main(){
	int n, t;
	printf("\nEnter the number : ");
	scanf("%d", &n);
	t = n;
	printf("\nRoman number of %d : ", n);
	while(n > 0){
		if(n >= 1000){
			printf("M");
			n -= 1000;
		}
		CHECK_FOR(500, 900, "D", "CM")
		CHECK_FOR(100, 400, "C", "CD")
		CHECK_FOR(50, 90, "L", "XC")
		CHECK_FOR(10, 40, "X", "XL")
		CHECK_FOR(5, 9, "V", "IX")	
		CHECK_FOR(1, 4, "I", "IV")	
	}
	printf("\n");
}
