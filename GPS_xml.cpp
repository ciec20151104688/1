#include<stdio.h>
#include<string.h>
#include<Windows.h>
struct Coordinate
{
	char date[11];
	char time[9];
	char lat[10];
	char lon[11];
};
int main()
{
	int NodeNumber = 0;
	FILE *fp = fopen("export.gpx", "r");
	FILE *fp1= fopen("a.txt","w");
	if (fp == NULL)
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
								Coordinate *current = new Coordinate;
								for (int i = 0; i < 6; i++)
									c = fgetc(fp);
								fgets(current->lat, 10, fp);
								for (int i = 0; i < 7; i++)
									c = getc(fp);
								fgets(current->lon, 11, fp);
								for (int i = 0; i < 12; i++)
									c = getc(fp);
								fgets(current->date, 11, fp);
								c = getc(fp);
								fgets(current->time, 9, fp);
								for (int i = 0; i < 18; i++)
									c = getc(fp);
								NodeNumber++;
								printf("%s\t%s\t%s\t%s\n", current->lat, current->lon, current->date, current->time);
								fprintf(fp1,"%s\t%s\t%s\t%s\n", current->lat, current->lon, current->date, current->time);
							}
						}
					}
				}
			}
		}
	}
	printf("共有%d个坐标\n", NodeNumber);
}
