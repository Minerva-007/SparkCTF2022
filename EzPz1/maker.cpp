#include"stdio.h"
#include"string.h"

int main()
{
	char arr[]="b83e7b197a499d205a92f04b6147e582881c4815609798b2131e01f4937fbcfd";
	printf("unsigned char ch[]={");
	for(unsigned int i=0;i<strlen(arr);i++)
	{
		printf("%d, ",arr[i]^0x069^i);
	}
	printf("\b\b}\n");
	unsigned char payload[]={ 0x48, 0x89, 0xC8, 0x48, 0x83, 0xF0, 0x69, 0xC3 };
	printf("unsigned char payload[]={");
	for(int i=0;i<8;i++)
	{
		printf("%d, ",payload[i]^0x48);
	}
	printf("\b\b};\n");
}