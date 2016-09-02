#include"zhubo.h"
#include<stdio.h>


int readzhu(zhubo *zhu , int n);
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
       printf("输入观看人数")；
         scanf("%d",&zhu[i].people);
       printf("每周直播总时间")；
         scanf("%d",&zhu[i].Time);
       pirntf("直播游戏名称")；
         scanf("&c",&zhu[i].game);
       zhu[i].rank=0;
   }
   return i;
}

void printzhu( zhubo *zhu , int n);
{tot
    int i;
    for(i=0;i<n,i++)
    {
        printf("%8s",zhu[i].name);
        printf("%8s",zhu[i].sex);
        printf("%8d",zhu[i].num);
        printf("%8d",zhu[i].people);
        printf("%8d",zhu[i].Time);
        printf("%8s",zhu[i].game);
        printf("%7d",zhu[i].total);
        printf("%7d",zhu[i].rank);
    }
}

int  calcuTotal(zhubo zhu[],int n);
{
    int i,sum;
    sum==0;
    for(i=0;i<n;i++)
        {
            sum+=zhu[i].Time;
        }
    return sum;
}

int deletezhu(zhubo zhu[],int n ,zhubo  z);
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
			t=zhu[i];
			zhu[i]=zhu[minpos];
			zhu[minpos]=t;
		}
	}
}












