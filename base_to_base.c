#include <stdio.h>
#include <string.h>
#include <math.h>

long int convert10(long int, long int);
void base16(long int a[20], long int);
long int convert16to10(char hex[20], long int);

int main(){
	
	char hex[20], ch;
	do{
		long int n, a[20], ib, ob, i = 1, p,c;
		printf("\nEnter the input base : ");
		scanf("%ld", &ib);
		if(ib != 16){
			printf("\nEnter the no to convert : ");
			scanf("%ld", &n);
		}
		else{
			printf("\nEnter the number to convert : ");
			scanf("%s", hex);
		}
		printf("\nEnter the output base : ");
		scanf("%ld", &ob);
		if(ib != 10){
			if(ib != 16)
				c = convert10(n, ib); // function to convert from all base to decimal
			else
				c = convert16to10(hex, ib); // function to convert from hexadecimal to decimal
		}
		else
			c = n;
		if(ob == 10){
			printf("\nThe output is : %ld", c);
		}
		while(c > 1){ // Finding the output
			a[i] = c % ob;
			c = c / ob;
			p = i;
			i++;
		}
		if(ob != 10){
			printf("\nThe output is : ");
			for(i = p;i >= 1; i--){
			//	printf("%x", a[i]);
				if(a[i] >= 10)
					base16(a, i);
				else
					printf("%ld", a[i]);
			}
		}
		printf("\nDo you want to continue (y/n) ?");
		scanf(" %c", &ch);
		//if(ch != 'Y' || ch != 'y')
		//	break;

	} while(ch == 'Y' || ch == 'y');
	
	printf("\n");
	return 0;
}

long int convert10(long int n, long int ib){
	long int b[20], i = 0, s = 0, p;
	while(n >= 1){
		b[i] = n % 10;
		n = n / 10;
		p = i;
		i++;
	}
	for(i = 0;i <= p;i++)
		s = s + (b[i] * pow(ib, i));
	return s;
}

long int convert16to10(char hex[20], long int ib){
	long int len, val, dec = 0, i = 0;
	len = strlen(hex);
	len--;
	for(i = 0;hex[i]!='\0';i++){
		switch(hex[i]){
			case '0':
				val = 0;
				break;
			case '1':
				val = 1;
				break;
			case '2':
				val = 2;
				break;
			case '3':
				val = 3;
				break;
			case '4':
				val = 4;
				break;
			case '5':
				val = 5;
				break;
			case '6':
				val = 6;
				break;
			case '7':
				val = 7;
				break;
			case '8':
				val = 8;
				break;
			case '9':
				val = 9;
				break;
			case 'a':
			case 'A':
				val = 10;
				break;
			case 'b':
			case 'B':
				val = 11;
				break;
			case 'c':
			case 'C':
				val = 12;
				break;
			case 'd':
			case 'D':
				val = 13;
				break;
			case 'e':
			case 'E':
				val = 14;
				break;
			case 'f':
			case 'F':
				val = 15;
				break;
			default:
				printf("\nBad character : %c", hex[i]);
				val = 0;
				break;
		} // end of switch block
		dec = dec + val*pow(ib, len);
		len--;
	}
	return dec;
}

void base16(long int a[20], long int i){ // function to convert a number into hexadecimal number
	char c;
	c = a[i] + 55;
	printf("%c", c);
}
