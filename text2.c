#include<stdio.h>
#include<string.h>
int main()
{
	char a[201], b[201];
	int i,j;
	int len_a, len_b,max;
	scanf("%s", a);
	scanf("%s", b);
	len_a = strlen(a);
	len_b = strlen(b);
	max = (len_a > len_b) ? len_a : len_b;
	a[max + 1] = '\0';
	for (i = 0; i < len_a; i++)
		a[max - i] = a[len_a - i - 1];
	for (i = 0; i < len_b; i++)
		b[max - i] = b[len_b - i - 1];
	for (i = 0; i <= max - len_a; i++)
		a[i] ='0';
	for (i = 0; i <= max - len_b; i++)
		a[i] ='0';

	j = 0;
	for (i = 0; i < max; i++)
	{
		j = (a[max - i] + b[max - i] + j - 96);
		a[max - i] = j % 10 + 48;
		j = j / 10;
	}
	if (j > 0) {
		a[0] = j+48;
		printf("%s", a);
	}
		
	else
		printf("%s", a + 1);

		
}