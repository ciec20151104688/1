#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *a;
	int flen;
	printf("a len=%d",sizeof(a));
	fp=fopen("d:\\20151104688\\export.gpx","r+");
	if((fp=fopen("d:\\20151104688\\export.gpx","r+"))==0)
	{
		printf("wrong");
		return(-1);
	}
	fseek(fp,0,SEEK_END);
	flen=ftell(fp); 
	fseek(fp,0,SEEK_SET);
	a=(char *)malloc(1*flen);
	fread(a,1,flen,fp);
	printf("len=%d   %c\n",flen,a[0]);
	fclose(fp);
	return 0;
}
