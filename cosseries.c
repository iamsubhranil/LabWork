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
		int i, j, denom, index, sign;
		float term, sum, x, cosine, numer, error, c, t, pre;
		
		printf("\nEnter the value of x : ");
		scanf("%f", &x);
		pre = getPrecision();
		t = (3.141593 * x)/180;
		cosine = 1;
		sign = -1;
		index = 2;
		while(1){
			numer = pow(t, index);
			denom = 1;
			for(j = 1;j<=index;j++)
				denom = denom*j;
			term = (numer/denom)*sign;
			if(numer/denom < pre)
				break;
			cosine += term;
			index += 2;
			sign *= -1;
		}
		c = cos(t);
		error = fabs(cosine - c);
		printf("\nValue of cosine is %.10f", x);
		printf("\nAs per series = %.10f", cosine);
		printf("\nAs per library function = %.10f", c);
		printf("\nError = %.10f", error);

		printf("\nDo you want to continue (y/n) ? ");
		scanf(" %c", &ch);
	} while(ch == 'y' || ch == 'Y');
	

	return 0;
}
