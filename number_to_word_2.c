//WAP in C to convert a decimal number into word.
#include <math.h>
#include <stdio.h>

#define ELEVEN(val, str) if(a == val){ \
							printf(str); \
						}

int main(){
	char *f[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *c[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *e[] = {"eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen",
				"eighteen", "nineteen"};
	char *d[] = {"hundred", "thousand", "lakh", "crore"};
	int b1, d1, e1, f1, c1 = 0;
	long int a, t, t1;
	
	printf("\nEnter the number : ");
	scanf("%ld", &a);
	t = a;
	int pos = 0;
	while(t > 0){
		b1 = t % 100;
		if(b1 > 10 && b1 < 20){
			b1 -= 11;
			printf("%s ", e[b1]);
		}
		else{
			d1 = b1 / 10;
			printf("%s ", c[d1 - 1]);
			d1 = b1 % 10;
			if(d1 > 0){
				printf("%s ", f[d1]);
			}
		}

		if(pos > 0){
			printf("%s", d[(pos / 2) - 1]);
		}
		pos += 2;
		t = t/100;
	}
	/*if(c1 == 1){
		printf("%s", f[a]);
	}
	else if(c1 == 2){
		ELEVEN(11, "eleven")
		else ELEVEN(12, "twelve")
		else ELEVEN(13, "thirteen")
		else ELEVEN(14, "forteen")
		else ELEVEN(15, "fifteen")
		else ELEVEN(16, "sixteen")
		else ELEVEN(17, "seventeen")
		else ELEVEN(18, "eighteen")
		else ELEVEN(19, "nineteen")
		else{
			t = a;
			b1 = t % 10;
			t = t / 10;
			if(b1 != 0){
				printf("%s %s", c[t - 1], f[b1]);
			}
			else
				printf("%s", c[t - 1]);
		}
	}
	else if(c1 == 3){
		t = a;
		t = t / 100;
		printf("%s ", d[t - 1]);
		a = a % 100;
		ELEVEN(11, "eleven")
		else ELEVEN(12, "twelve")
		else ELEVEN(13, "thirteen")
		else ELEVEN(14, "forteen")
		else ELEVEN(15, "fifteen")
		else ELEVEN(16, "sixteen")
		else ELEVEN(17, "seventeen")
		else ELEVEN(18, "eighteen")
		else ELEVEN(19, "nineteen")
		else{
			t = a;
			b1 = t % 10;
			t = t / 10;
			if(b1 != 0){
				printf("%s %s", c[t - 1], f[b1]);
			}
			else
				printf("%s", c[t - 1]);
		}
	}*/
	printf("\n");
	return 0;
}
