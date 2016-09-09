#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "conio.h"
#include "windows.h"
#include"en.h"
struct Custome
{
	char idcard[19];
	char password[20];
};
typedef struct Custome Custome;
#define sizeCus sizeof(Custome)
void enroll()//×¢²áº¯Êý
{
	FILE *fp;
	int i,n,l;
	struct Custome c;
	if((fp=fopen("d:\\custome.dat","ab"))==NULL)
	{
		printf("can not open file");
		exit(0);
	}
do
{
		printf("please input you idcard:");
        gets(c.idcard);
        n=strlen(c.idcard);
}while(n<18||n>18);
	//getchar();
	do
	{
       printf("please input the six password you want:");
	   for(i=0;i<6;i++)
	   {
		   c.password[i]=getch();
           printf("%c", c.password[i]); 
	       Sleep(500);
	       printf("\b*");
	   }


        c.password[6]='\0';
		printf("\n");
		l=strlen(c.password);
		
	}while(l>6||l<6);
	printf("%s",c.idcard);
	fwrite(&c,sizeCus,1,fp);
	fclose(fp);
}
int entry()//µÇÂ¼º¯Êý
{
	FILE *fp;
	int i=0,n,j,m=0,a,l,b;
	struct Custome cus[100];
	struct Custome c;
    j=0;
	if((fp=fopen("d:\\custome.dat","rb"))==NULL)
	{
		printf("file does not exit,creat it first:\n");
		exit(0);
	}
	fread(&cus[i],sizeCus,1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&cus[i],sizeCus,1,fp);

	}
	fclose(fp);
	n=i;
	printf("\t\t|------------ÇëµÇÂ¼------------|\n");
	
	do
	{
		printf("idcard: ");
		scanf("%s",c.idcard);
        n=strlen(c.idcard);
	}while(n>18);
    
	do
	{
		b=strcmp(c.idcard,cus[j].idcard);
		if(b==0)
			break;
		j++;
	}while(j<n||j==n);
	switch(b)
	{
	case 0:
	
			for(m=1;m<4;m++)
			{
				do
				{
                   printf("please input the six password :");
				   for(i=0;i<6;i++)
				   {
					   c.password[i]=getch();
                       printf("%c", c.password[i]); 
	                   Sleep(500);
	                   printf("\b*");
				   }

                   c.password[6]='\0';
		           printf("\n");
	           	   l=strlen(c.password);
				}while(l>6);
				a=strcmp(c.password,cus[j].password);
				if(a==0)
				{
					break;
				}
			}
	if(a==0)
	{
	printf("Yes");
	return 1;
	}
	else
	{
	printf("You have input three times wrong password.\n\a\a\a");
    return 0;
	}
	break;
	case -1:
		printf("Do not exit this user,please back and enroll.");
		break;
	case 1:
        printf("Do not exit this user,please back and enroll.");
		return 1;
		break;
	};
}

		



	
	





	


