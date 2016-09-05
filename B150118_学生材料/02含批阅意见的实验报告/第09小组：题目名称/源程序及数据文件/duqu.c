#include <stdio.h>
#include <stdlib.h>
#include "zhibo.h"
FILE *fp;
int  createFile(zhubo  zhu[ ])
{
	int n;
   	if((fp=fopen("zhubo.dat", "w")) == NULL)
	{
	    printf("can not open file !\n");
	    exit(0);
    	}
	printf("input zhubo's information:\n");
	n=readzhu(zhu,NUM);
fwrite(zhu,sizezhu,n,fp);
 	fclose(fp);
	 return n;
}

int readFile(zhubo zhu[ ] )
{
	int i=0;
	if((fp=fopen("zhubo.dat", "r")) == NULL)
	{
	    printf("file does not exist,create it first:\n");
	    return 0;

    	fread(&zhu[i],sizezhu,1,fp);
   	while(!feof(fp))
	{
		i++;
	    	fread(&zhu[i],sizezhu,1,fp);
     }
	fclose(fp);
	return i;
}

void saveFile(zhubo zhu[],int n)
{
   	if((fp=fopen("zhubo.dat", "w")) == NULL)
	{
		printf("can not open file !\n");
		exit(0);
	}
	fwrite(zhu,sizezhu,n,fp);
	fclose(fp);
}
}


