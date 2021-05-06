#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	for (int i = 0; i < 2; i++)
	{
		pid_t pid = fork();
		printf("hello, world?");
	}
}