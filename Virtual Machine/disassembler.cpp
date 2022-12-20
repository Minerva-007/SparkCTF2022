#include"stdio.h"

int MEMORY[2048] = {0};

void runner()
{
	int index=500;
	while(index<2047)
	{
		//Read 3 values
		long int mem1=MEMORY[index]^0x042^index;
		long int mem2=MEMORY[index+1]^0x042^(index+1);
		long int mem3=MEMORY[index+2]^0x069^(index+2);
		printf("%d:\t\tSUBEQ %d, %d, %d\n",index,mem1, mem2, mem3);
			index = index +3;
	}
}

int main()
{
	FILE* f=fopen("Memory","r");
	if(f==0)
	{
		printf("Cannot load memory.\n");
		return -1;
	}
	
	for(int i=0;i<2048;i++)
	{
		fscanf(f, "%d",&MEMORY[i]);
	}
	runner();
	printf("%d %d %d %d %d\n",MEMORY[499]^0x042^499, MEMORY[256]^0x042^256, MEMORY[420]^0x042^420, MEMORY[2046]^0x42^2046, MEMORY[2047]^0x042^2047);
	
	printf("SparkCTF{");
	for(int i=0;i<64;i++)
	{
		printf("%c",(MEMORY[i]^0x042^i)/(MEMORY[i+420]^(i+420)^0x042));
	}
	printf("}\n");
}