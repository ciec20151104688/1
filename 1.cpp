#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *a;
	fp=fopen("d:\\20151104688\\export.gpx","r+");
	if((fp=fopen("d:\\20151104688\\export.gpx","r+"))==0)
	{
		printf("wrong");
		return(-1);
	}
