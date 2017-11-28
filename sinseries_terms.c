#include <stdio.h>
#include <math.h>

double getPrecision(){
	int p;
	double d = 0.1;
	printf("\nEnter the precision after decimal point : ");
	scanf("%d", &p);
	while(p > 1){
		d *= 0.1;
		p--;
	}
	return d;
}

int main(){
	char ch;
	do{
		long double i=1, j, denom, index, sign, n = 0;
		float term, sum, x, sine, numer, error, c, t, pre;
		
		printf("\nEnter the value of x : ");
		scanf("%f", &x);
		printf("\nEnter the number of terms : ");
		scanf("%ld", &n);
	//	pre = getPrecision();
		t = (3.141593 * x)/180;
		sine = t;
		sign = -1;
		index = 3;
		i = 1;
		while(i<n){
			numer = pow(t, index);
			denom = 1;
			for(j = 1;j<=index;j++)
				denom = denom*j;
			term = (numer/denom)*sign;
			sine += term;
			index += 2;
			sign *= -1;
			i++;
		}
		c = sin(t);
		error = fabs(sine - c);
		printf("\nValue of sine is %.10f", x);
		printf("\nAs per series = %.10f", sine);
		printf("\nAs per library function = %.10f", c);
		printf("\nError = %.10f", error);

		printf("\nDo you want to continue (y/n) ? ");
		scanf(" %c", &ch);
	} while(ch == 'y' || ch == 'Y');
	

	return 0;
}
