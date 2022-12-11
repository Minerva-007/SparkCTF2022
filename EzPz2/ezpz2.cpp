#include"stdio.h"


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

int arr[]={98, 66, 118, 31, 98, 98, 21, -96, 79, 51, 50, 70, 119, 75, 54, 100, 23, 118, 29, 56, 54, 70, 112, 77, 48, 103, 65, 107, 72, 100, 57, 69, 112, 29, 56, 100, 23, 118, 30, 97, 102, 75, -104, 67, 56, 103, 23, 112, 74, 100, 52, 68, -104, 72, 56, 99, 23, 112, 31, 54, 101, 64, 107};

int main()
{
	char input[68];
	printf("Howdy, enter ye key: ");
	scanf("%s",&input);
	for(int i=0;i<63;i++)
	{
		char x=selector(i,input[i]);
		if(x!=arr[i]){
			printf("RIP\n");
			return -1;
		}
	}
	printf("Yippy!\n");
	return 0;
}