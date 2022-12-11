#include"stdio.h"
#include"windows.h"


unsigned char ch[]={11, 80, 88, 15, 90, 14, 94, 87, 86, 1, 87, 91, 92, 0, 85, 86, 76, 25, 66, 72, 27, 76, 75, 28, 71, 65, 71, 69, 16, 65, 79, 68, 113, 112, 122, 41, 121, 116, 126, 123, 119, 112, 122, 117, 124, 124, 37, 116, 104, 107, 106, 63, 109, 109, 57, 106, 104, 99, 100, 52, 55, 55, 49, 50};
unsigned char input[68];
unsigned char payload[]={0, 193, 128, 0, 203, 184, 33, 139};

typedef unsigned char (__cdecl *MYPROC)(int);

int pr(int x)
{
	x=x+x;
	x=x-x;
	x=x*x;
	x=x/x;
	return x;
}

int main()
{
	//open pr
	DWORD ProcessID;
	HANDLE hProcess;
	DWORD PrevFlag;
	ProcessID=GetCurrentProcessId();
	hProcess=OpenProcess(PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,0,ProcessID);
	if(hProcess==0){printf("OpenProcess failed\n");return GetLastError();}
	bool result=VirtualProtect((PVOID)&pr,8,PAGE_EXECUTE_READWRITE,&PrevFlag);
	if(result==0){printf("VirtualProtect failed at one\n");return GetLastError();}
	//WriteProcessMemory
	for(int i=0;i<8;i++)
	{
		payload[i]=payload[i]^0x48;
	}
	WriteProcessMemory(hProcess,(LPVOID)pr,&payload,8,0);
	result=VirtualProtect((PVOID)&pr,20,PrevFlag,&PrevFlag);
	if(result==0){printf("VirtualProtect failed at two\n");return GetLastError();}
	//Input
	printf("Okay so, enter your SHA256 code:\n");
	scanf("%s",&input);
	for(int i=0;i<64;i++)
	{
		char x=input[i];
		unsigned char ans=pr(x);
		if((ans^i)!=ch[i])
		{
			printf("Nope :(\n");
			exit(-1);
		}
	}
	printf("YES\n");
}