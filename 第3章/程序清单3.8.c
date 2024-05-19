#include<stdio.h>
int main(void)
	{
	printf("Type long int has a size of types %u bytes.\n",sizeof(long int));
	printf("Type long has a size of types %u bytes.\n",sizeof(long));


	//printf("Type long long has a size of types %u bytes.\n",sizeof(long long));
	
	//该编译器不支持long long类型

	
	printf("Type int has a size of types %u bytes.\n",sizeof(int));
	printf("Type char has a size of types %u bytes.\n",sizeof(char));
	printf("Type float has a size of types %u bytes.\n",sizeof(float));
	printf("Type double has a size of types %u bytes.\n",sizeof(double));
	printf("Type long double has a size of types %u bytes.\n",sizeof(long double));
	getchar();
	return 0;
	}