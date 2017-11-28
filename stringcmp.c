#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
		char *p1, *p2;

		if (! str || ! *str)
				return str;
		for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
		{
				*p1 ^= *p2;
				*p2 ^= *p1;
				*p1 ^= *p2;
		}
		return str;
}

int main(){
		char a[20], b[20], c[20];
		int i, c1 = 0, c2 = 0, c3 = 0, k = 0, j = 0, m;
		printf("\nEnter the string : ");
		gets(a);
		for(i = 0;a[i] != '\0';i++){
				switch(a[i]){
						case '[' :
								c1++;
								break;
						case ']' :
								c1--;
								break;
						case '{' :
								c2++;
								break;
						case '}' :
								c2--;
								break;
						case '(' :
								c3++;
								break;
						case ')' :
								c3--;
								break;
				}
		}
		for(i = 0;a[i] != '\0';i++){
				switch(a[i]){
						case '[':
						case '{':
						case '(':
								b[j++] = a[i];
								break;
						case ']':
								c[k++] = '[';
								break;
						case '}':
								c[k++] = '{';
								break;
						case ')':
								c[k++] = '(';
								break;
				}
		}
		c[k] = '\0';
		b[j] = '\0';
		m = strcmp(b, strrev(c));

		if(c1 == 0 && c2 == 0 && c3 == 0 && m == 0){
				printf("\n\nString is valid in algebraic sense!\n");
		}
		else
				printf("\n\nString is not balanced in algebraic sense!\n");

		return 0;

}
