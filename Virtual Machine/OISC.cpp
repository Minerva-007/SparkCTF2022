#include"stdio.h"
#include"stdlib.h"


// Flag SparkCTF{42f8a30917ebdef9b62bf447d79e074ba12f7144e179ef49cf25a04fb55957ab}

int MEMORY[2048] = {0};


void runner()
{
	int index=500;
	while(index!=2047)
	{
		//Read 3 values
		long int mem1=MEMORY[index]^0x042^index;
		long int mem2=MEMORY[index+1]^0x042^(index+1);
		long int mem3=MEMORY[index+2]^0x069^(index+2);
		MEMORY[mem1] = ((MEMORY[mem1]^0x042^mem1)-(MEMORY[mem2]^0x042^mem2))^0x042^mem1;
		if((MEMORY[mem1]^0x042^mem1)==0){
			index = mem3;
		}
		else{
			index = index +3;
		}
		
	}
}

// A memory profile will be available, but encrypted.
// Instruction format: SUBLEQ mem1 mem2 loc1
// mem1 = mem1 - mem2, jump to loc1 if mem1<=0.
// Ez.


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
	
	if(MEMORY[255]==281)
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Nopity Nope.\n");
	}
	return 0;
}