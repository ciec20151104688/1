#include<stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	int NodeNumber = 0;
	char date[11];
	char time[9];
	char lat[10];
	char lon[11];
	FILE *fp = fopen("export.gpx", "r");
	FILE *fp1= fopen("1.csv","w");
	if (fp == NULL|| fp1 == NULL)
	{
		printf("open file failed");
		exit(0);
	}
	else
	{
		char c;
		printf("纬度\t经度\t日期\t时间\n");
		while ((c = fgetc(fp)) != EOF)
		{
			if (c == 't')
			{
				c = fgetc(fp);
				if (c == 'r')
				{
					c = fgetc(fp);
					if (c == 'k')
					{
						c = fgetc(fp);
						if (c == 'p')
						{
							c = fgetc(fp);
							if (c == 't')
							{
								for (int i = 0; i < 6; i++)
									c = fgetc(fp);
								fgets(lat, 10, fp);
								for (int i = 0; i < 7; i++)
									c = getc(fp);
								fgets(lon, 11, fp);
								for (int i = 0; i < 12; i++)
									c = getc(fp);
								fgets(date, 11, fp);
								c = getc(fp);
								fgets(time, 9, fp);
								for (int i = 0; i < 18; i++)
									c = getc(fp);
								NodeNumber++;
								printf("%s\t%s\t%s\t%s\n", lat, lon, date, time);
								fprintf(fp1,"%s\t   %s\t   %s\t   %s\n", lat, lon, date, time);
							}
						}
					}
				}
			}
		}
	}
	printf("共有%d个坐标\n", NodeNumber);
}
