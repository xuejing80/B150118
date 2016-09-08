/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>



int readBoo(Book *boo,int n)          /*读入图书记录，编号为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	     scanf("%ld", &boo[i].num);
		if (boo[i].num==0) break;
		printf("name: ");
		scanf("%s",boo[i].name);	
		printf("writer:  ");
		scanf("%s",boo[i].writer);
        printf("category:  ");
		scanf("%s",boo[i].category);
		printf("location:  ");
		scanf("%d",boo[i].location);
		printf("information:  ");
		scanf("%s",boo[i].location);
		printf("botime:  ");
		scanf("%d",boo[i].botime);
		printf("retime:  ");
		scanf("%d",boo[i].retime);
	}
        
	return i;                         /*返回实际读入的记录条数*/
}

void printBoo ( Book  *boo , int n)       /*输出所有图书记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", boo[i].num);
		printf("%8s", boo[i].name);
		printf("%8s", boo[i].writer);
        printf("%8s", boo[i].category);
        printf("%8ld", boo[i].location);
		printf("%8s", boo[i].information);
	    printf("%8d", boo[i].botime);
		printf("%8d", boo[i].retime);

	}
}

int equal(Book s1,Book s2,int condition)  /*如何判断两个Student记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较作者*/
	     return s1.writer==s2.writer;
 else if (condition==4)                /*如果参数condition的值为4，则比较类别*/
		return s1.category==s2.category;
	else return 1;                       /*其余情况返回1*/
} 



void reverse(Book boo[],int n)             /*数组元素逆置*/
{
	int i;
	Book temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=boo[i];
		boo[i]=boo[n-1-i];
		boo[n-1-i]=temp;
	}
}


void sortBoo(Book boo[],int n)  /*冒泡排序*/
{
	int i,j,temp;
		for (i=1;i<n-1;i++)                  /*共进行n-1趟排序*/
		  for (j=n-1;j>i;j--)             /*递减循环，从后往前比较，趟号增加相邻元素对减少*/
			if (boo[j].num<boo[j-1].num)         /*两两比较，若后一个元素小，则交换该组相邻元素*/
			{
				temp=boo[j-1].num;
				boo[j-1].num=boo[j].num;
				boo[j].num=temp;
			}
	

}


int searchBoo(Book boo[],int n,Book s,int condition,int f[ ])  /*在boo数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(boo[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}




void  insertBoo(Book boo[],int n,int x)
{
int i,j;
for (i=0;i<n&&boo[i].num<x;i++)         /*查找待插入的位置*/
for (j=n-1;j>=i;j--)            /*用递减循环移位*/
    boo[j+1].num=boo[j].num;
    boo[i].num=x;                       /*数组的下标元素值赋值为插入的x*/

}


int deleteBoo(Book boo[],int n,int s)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	int flag=1;                                  /*是否找到待删元素的标志位，1找到，0未找到*/
	for (i=0;i<n && boo[i].num!=s;i++)                 /*寻找待删除的元素是否存在*/	          
	if (i==n)                                    /*循环停止时如果i==n,则说明元素不存在*/
		flag=0;
	else
	{
	for(j=i;j<n-1;j++)
	
		boo[j].num=boo[j+1].num;
	}
	 return flag;                      
}




int main()
  {
	  int x=5,y=5,z=5,n=5,i=0;
	  int SIZE=6;
	  Book boo[200];
	  printBoo(boo,SIZE);                  /*输出删除前的数组*/
	  printf("Please input x be deleted:\n");

    scanf("%8ld,&x");                /*读入待删除的元素*/
 if(deleteBoo(boo,SIZE,x))
     printBoo(boo,SIZE-1);             /*如果成功则输出删除后的数组元素*/
else
     printf("can not delete!\n");    /*否则给出未删除的提示信息*/

printBoo(boo,SIZE-1);
 printf("Please input y be inserted:\n");
scanf("%8ld,&y");                  /*读入待插入的值y*/
insertBoo(boo,SIZE-1,y);
printBoo(boo,SIZE);



return 0;  
  }


