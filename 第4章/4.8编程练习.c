/******************************µÚ5Ìâ************************************/
#include<stdio.h>
#include<string.h>
int main(void)
	{
	char a[10],b[10];
	printf("Please enter your name:\n");
	scanf("%s",&a);
	printf("\nPlease enter your surname:\n");
	scanf("%s",&b);
	printf("\n%s %s\n %*d %*d\n",a,b,strlen(a)-1,strlen(a),strlen(b),strlen(b));
	getchar();
	return 0;
	}
