#include"zhibo.h"
#include<stdio.h>
#include <stdlib.h>

FILE *fp;
int readzhu(zhubo *zhu , int n)
{
   int i;
   for(i=0;i<n;i++)
   {
       printf("请输入主播信息\n");
       printf("姓名:  ");
         scanf("%s",&zhu[i].name);
       printf("性别:  ");
         scanf("%s",&zhu[i].sex);
       printf("输入房间号");
         scanf("%d",&zhu[i].num);
       printf("输入观看人数");
         scanf("%d",&zhu[i].people);
       printf("每周直播总时间");
         scanf("%d",&zhu[i].Time);
       pirntf("直播游戏名称");
         scanf("&c",&zhu[i].game);
       zhu[i].rank=0;
   }
   return i;
}

void printzhu( zhubo *zhu , int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%8s",zhu[i].name);
        printf("%8s",zhu[i].sex);
        printf("%8d",zhu[i].num);
        printf("%8d",zhu[i].people);
        printf("%8d",zhu[i].Time);
        printf("%8s",zhu[i].game);
        printf("%7d",zhu[i].time);
        printf("%7d",zhu[i].rank);
    }
}

int  calcuTotal(zhubo zhu[],int n)
{
    int i,sum;
    sum==0;
    for(i=0;i<n;i++)
        {
            sum+=zhu[i].Time;
        }
    return sum;
}

int deletezhu(zhubo zhu[],int n ,zhubo  z)
{
	int i,j;
	for (i=0;i<n;i++)
		if (equal(zhu[i],z,1))   break;
	if (i==n)
	{
		printf("This record does not exist!\n");
		return n;
	}
	for (j=i; j<n-1; j++)
		zhu[j]=zhu[j+1];

	n--;
	return n;
}

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[ ])

{
	int i,j=0,find=0;
	for (i=0;i<n;i++)
		if (equal(zhu[i],z,condition))
		{
			f[j++]=i;
			find++;
		}
	 return find;
}

int insertzhu(zhubo zhu[],int n,zhubo z)
{
	int i;
	sortzhu(zhu,n,1);
	for (i=0;i<n;i++)
	{
		if (equal(zhu[i],z,1))
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)
	{
		if (!larger(zhu[i],z,1))
		break;
		zhu[i+1]=zhu[i];
	}
	zhu[i+1]=z;
	n++;
	return n;
}

void sortzhu(zhubo zhu[],int n,int condition)
{
	int i,j,minpos;
	zhubo z;
	for (i=0;i<n-1;i++)
	{
		minpos=i;
		for (j=i+1;j<n;j++)
			if (larger(zhu[minpos],zhu[j],condition))
				minpos=j;
		if (i!=minpos)
		{
			z=zhu[i];
			zhu[i]=zhu[minpos];
			zhu[minpos]=z;
		}
	}
}

int equal(zhubo z1,zhubo z2,int condition)  /*如何判断两个Student记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较房间号*/
		return z1.num==z2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(z1.name,z2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较游戏*/
	     return z1.game==z2.game;

	else return 1;                       /*其余情况返回1*/
}

int larger(zhubo z1,zhubo z2,int condition)  /*根据condition条件比较两个Student记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较房间号*/
		return z1.num>z2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总时间*/
		return z1.Time>z2.Time;
	else return 1; /*其余情况返回1*/
}

void reverse(zhubo zhu[],int n)             /*数组元素逆置*/
{
	int i;
	zhubo temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=zhu[i];
		zhu[i]=zhu[n-1-i];
		zhu[n-1-i]=temp;
	}
}

void calcuRank(zhubo zhu[],int n)          /*根据总时间计算所有学生的排名，时间相同者名次相同*/
{
	int i ;
	sortzhu(zhu,n,2);                     /*先调用sortStu算法，按总分由小到大排序*/
	reverse(zhu,n);                      /*再逆置，则按总分由大到小排序了*/
	zhu[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(zhu[i],zhu[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/
			zhu[i].rank=zhu[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/
	    else
			zhu[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}


int calcumax(int m[NUM], zhubo zhu[] ,int n)  /*求直播时间最长*/
{
   int i,j,max;
   max=zhu[0].Time ;
   for(i=0;i<NUM;i++)
   {
       m[i]=zhu[i].Time;
       if(m[i]<m[i+1])
       {
           max=zhu[i+1].Time;
       }
       else
       {
           max=zhu[i].Time;
       }
   }
   return max;
}


int calcumost(int m[NUM], zhubo zhu[] ,int n)  /*求直播人数最多*/
{
   int i,j,most;
   most=zhu[0].people ;
   for(i=0;i<NUM;i++)
   {
       m[i]=zhu[i].Time;
       if(m[i]<m[i+1])
       {
           most=zhu[i+1].people;
       }
       else
       {
           most=zhu[i].people;
       }
   }
   return most;
}


int calcupj(int m[NUM], zhubo zhu[] ,int n)  /*求直播平均时间*/
{
   int i,j,pj,sum;
   sum=0;
   for(i=0;i<NUM;i++)
   {
      m[i]=zhu[i].Time;
      sum+sum+m[i];
   }
   pj=sum/NUM;
   return pj;
}


