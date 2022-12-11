#include"stdio.h"

// Flag is SparkCTF{a1cdbaf14315b06cdcf855a60f2f3d86af8cdceae8988fda1d37938bdad6d3fa}

char one(char x)
{
	return x+1;
}

char two(char x)
{
	return x^0x73;
}

char four(char x)
{
	return x^123;
}

char three(char x)
{
	x=x-86;
	return four(x);
}

char five(char x)
{
	return x;
}

int selector(int n, char x)
{
	switch(n%5)
	{
		case 0:{
			return one(x);
			break;
		}
		case 1:{
			return two(x);
			break;
		}
		case 2:{
			return three(x);
			break;
		}
		case 3:{
			return four(x);
			break;
		}
		case 4:{
			return five(x);
			break;
		}
	}
	return 69;
}


int main()
{
	char input[]="a1cdbaf14315b06cdcf855a60f2f3d86af8cdceae8988fda1d37938bdad6d3fa";
	printf("int arr[]={");
	for(int i=0;i<63;i++)
	{
		char x=selector(i,input[i]);
		printf("%d, ",x);
	}
	printf("\b\b};\n");
}