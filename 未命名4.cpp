#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *a;
	int len;
	fp=fopen("d:\\20151104688\\export.gpx","r+");
	if((fp=fopen("d:\\20151104688\\export.gpx","r+"))==0)
	{
		printf("wrong");
		return(-1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	a=(char*)malloc(len);
	fseek(fp,0,0);
	fread(a,1,len,fp);
	printf("%s\n",a);
	free(a);
	return 0;
}
