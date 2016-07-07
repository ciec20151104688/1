#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mian()
{
	FILE *fp;
	char *text;
	int len;
	fp=fopen("d:\\20151104688\\export.gpx","r+");
	if((fp=fopen("d:\\20151104688\\export.gpx","r+"))==0)
	{
		printf("wrong");
		return(-1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp); 
	text=(char*)malloc(len);
	printf("length=%d\n",len);
	fseek(fp,0,0);
	strcpy("lat",&ch[i+4]);
	while(fgets(text,1024,fp)!=NULL)
	{
	   puts(text);
	   fputs(text,fp); 
    }
	fread(text,1,len,fp);
	printf("%s\n",text);
	free(text);
	return 0;
}

