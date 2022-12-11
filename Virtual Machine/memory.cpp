#include"stdio.h"
#include"stdlib.h"


unsigned int MEMORY[2048];

void addIns(int aa,int a, int b, int c)
{
	MEMORY[aa]=a^0x042^aa;
	MEMORY[aa+1]=b^0x042^(aa+1);
	MEMORY[aa+2]=c^0x069^(aa+2);
}

void addMem(int aa, int a)
{
	MEMORY[aa]=a^0x042^(aa);
}

void spurt()
{
//	printf("int MEMORY[2048] = {");
	for(int i=0;i<2048;i++) printf("%d ",MEMORY[i]);
//	printf("\b\b};\n");
}

int main()
{
	for(int i=0;i<2048;i++)
	{
		MEMORY[i]=rand();
	}
	char message[]="42f8a30917ebdef9b62bf447d79e074ba12f7144e179ef49cf25a04fb55957ab";
	
	char num[]=	   "KanonClannadCharotteAngelBeatsPlasticMemoriesPlanetarianAllKey<3";
	//Cipher at 0
	for(int i=0;i<64;i++)addMem(i,message[i]*(num[i]+1));
	//Key at 420
	for(int i=0;i<64;i++)addMem(i+420,num[i]);
	//Input will be at 256
	for(int i=0;i<64;i++)addMem(i+256,message[i]);
	//
	addMem(2047, 0);
	addMem(2046, 1);
	addMem(254, -420);
	addMem(255, 0);
	addMem(499,0);
	printf("Secret number: %d\n",420^0x42^255);
	//Multiplication block at 500
	int m=500, in=256, key=420;
	for(int i=0;i<64;i++)
	{
		addIns(m, 499,in, m+3);
		addIns(m+3, in, 499, m+6);
		addIns(m+6, key, 2046, m+12);
		addIns(m+9, 2047, 2047, m+3);
		addIns(m+12, 499, 499, m+15);
		m=m+15;
		in=in+1;
		key=key+1;
	}
	printf("%d\n",m);
	
	//Checker block where m ends
	in=256;
	for(int i=0;i<64;i++)
	{
		addIns(m, i, in, m+6);
		addIns(m+3, 2047, 2047, 2047);
		m=m+6;
		in++;
	}
	addIns(m, 2047, 2047, 65);
	//Ending Line at 65
	addIns(65, 255, 254, 68);
	addIns(68, 2047, 2047, 2047);
	//
	
	spurt();
	return 0;
}