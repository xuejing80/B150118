/*②book.c文件的完整内容*/
#include "book.h"
#include <stdio.h>

void readOneBook(Book *boo)          /*传入一本书的地址，录入信息*/
{
		printf("Input one book\'s information\n");
		printf("num:  ");
	    scanf("%ld",&boo->num);
		printf("name:  ");
		scanf("%s",boo->name);	
		printf("writer:  ");
		scanf("%s",boo->writer);
        printf("category:  ");
		scanf("%s",boo->category);
		printf("location:  ");
		scanf("%ld",&boo->location);
		printf("information:  ");
		scanf("%s",boo->information);
		printf("botime:  ");
		scanf("%s",&boo->botime);
		printf("retime:  ");
		scanf("%s",&boo->retime);                        
}


int readBoo(Book *boo,int n)          /*读入图书记录，编号为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one book\'s information\n");
		printf("num:  ");
	     scanf("%ld", &boo[i].num);
		if (boo[i].num==0) 
	    break;
		printf("name:  ");
		scanf("%s",boo[i].name);	
		printf("writer:  ");
		scanf("%s",boo[i].writer);
        printf("category:  ");
		scanf("%s",boo[i].category);
		printf("location:  ");
		scanf("%ld",&boo[i].location);
		printf("information:  ");
		scanf("%s",boo[i].information);
		printf("botime:  ");
		scanf("%s",&boo[i].botime);
		printf("retime:  ");
		scanf("%s",&boo[i].retime);
	}
        
	return i;                         /*返回实际读入的记录条数*/
}

void printBoo ( Book  *boo , int n)       /*输出所有图书记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%ld\t",boo[i].num);
		printf("%s\t", boo[i].name);
		printf("%s\t", boo[i].writer);
        printf("%s\t", boo[i].category);
        printf("%ld\t",boo[i].location);
		printf("%s\t",boo[i].information);
	    printf("%s\t",boo[i].botime);
		printf("%s\n",boo[i].retime);

	}
}

int equal(Book s1,Book s2,int condition)  /*如何判断两个Book记录相等*/
{
if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
	return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/
     {
	    if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
else if (condition==3)                /*如果参数condition的值为3，则比较作者*/
{
	    if (strcmp(s1.writer,s2.writer)==0) 	return 1;
		else return 0;
     }
else if (condition==4)                /*如果参数condition的值为4，则比较类别*/
{
	    if (strcmp(s1.category,s2.category)==0) 	return 1;
		else return 0;
     }
	else return 1;                       /*其余情况返回1*/
} 

int larger(Book s1,Book s2,int condition)  /*根据condition条件比较两个Book记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return s1.num>s2.num;
	else return 1; /*其余情况返回1*/
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



int insertBoo(Book boo[],int n,Book s)              /*向boo数组中依编号递增插入一个元素s*/
{
	int i;
	sortBoo(boo,n);                              /*先按编号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(boo[i],s,1))                      /*编号相同不允许插入，保证编号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编号从小到大排序*/
	{
		if (!larger(boo[i],s,1))                    /*如果s大于当前元素boo[i]，则退出循环*/
		break;
		boo[i+1]=boo[i];                         /*否则元素boo[i]后移一个位置*/
	}
	boo[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteBoo(Book boo[],int n,Book s)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(boo[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(boo[i],s,1)成立*/ 
		boo[j]=boo[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}




