#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp,*fp1;
	int i=0;
	int flen;
	char *ptr;
	char lat[10];
	char lon[11];
	char date[11];
	char time[9];
    fp=fopen("export.gpx","r");
    fp1=fopen("export.csv","w");
    if(fp==NULL)
    {    
        printf("打开文件失败!\n");
        return -1;
	}
	fseek(fp,0,SEEK_END);
	flen=ftell(fp);	
	fseek(fp,0,SEEK_SET);
	ptr=(char *)malloc(1*flen);
	fread(ptr,flen,1,fp);
	ptr[flen]='\0';
	fprintf(fp1,"精度,维度,日期,时间\n");
	while(!(ptr[i]=='<'&&ptr[i+1]=='/'&&ptr[i+2]=='g'&&ptr[i+3]=='p'&&ptr[i+4]=='x'&&ptr[i+5]=='>'))
	{
		if(ptr[i]==' '&&ptr[i+1]=='l'&&ptr[i+2]=='a'&&ptr[i+3]=='t')
	    {
	    	strncpy(lat,&ptr[i+6],9);
	    	lat[9]='\0';
	    	printf("%s",lat);
            strncpy(lon,&ptr[i+22],10);
            lon[10]='\0';
            printf("%s",lon);
            strncpy(date,&ptr[i+44],10);
            date[10]='\0';
            printf("%s",date);
            strncpy(time,&ptr[i+55],8);
            time[8]='\0';
	    	printf("%s\n",time) ;
     		fprintf(fp1,"%s,%s,%s,%s\n",lat,lon,date,time);
       }
       	i++;
    }
	fclose(fp1);
	fclose(fp);
	free(ptr);
    return 0;
}
