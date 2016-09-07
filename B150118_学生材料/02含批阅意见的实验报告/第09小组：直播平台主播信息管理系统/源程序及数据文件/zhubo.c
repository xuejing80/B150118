#include "zhubo.h"
#include <stdio.h>

int readzhu(zhubo  *zhu , int n)          /*读入主播记录值，读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one zhubo\'s information\n");
		printf("name: ");
		scanf("%s",zhu[i].name);
		printf("sex:  ");
		scanf("%s",zhu[i].sex);
		printf("num:  ");
        scanf("%ld", zhu[i].num);
		printf("game: ");
		scanf("%s",zhu[i].game);
		printf("Input time of the zhubo:\n");
		for (j=0;j<7;j++)
	    {
		    scanf("%d",&zhu[i].time[j]);
		}

	}
	return i;                         /*返回实际读入的记录条数*/
}

void printzhu ( zhubo  *zhu , int n)       /*输出所有主播记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8s", zhu[i].name);
		printf("%8s", zhu[i].sex);
		printf("%8ld", zhu[i].num);
		printf("%8s", zhu[i].game);
		printf("%8d\n", zhu[i].total);
	}
	    printf("%5d\n",zhu[i].rank);
}

int equal(zhubo z1,zhubo z2,int condition)  /*如何判断两个主播记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较房间号*/
		return z1.num==z2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(z1.name,z2.name)==0) 	return 1;
		else return 0;
     }

	else return 1;                       /*其余情况返回1*/
}

int larger(zhubo z1,zhubo  z2,int condition)  /*根据condition条件比较两个主播记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较房间号*/
		return z1.num>z2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总时间*/
		return z1.total>z2.total;
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

void calcuTotal(zhubo zhu[],int n)         /*计算所有学生的总时间*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有主播记录*/
	{
		zhu[i].total =0;
		for (j=0;j<7;j++)               /*内层循环控制七天的时间*/
			zhu[i].total +=zhu[i].time[j];
	}
}

void calcuRank(zhubo zhu[],int n)          /*根据总时间计算所有主播的排名，时间相同者名次相同*/
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

void calcuMark(double m[7][3],zhubo zhu[],int n) /*求七天的最长、最短、平均*/

{
	int i,j;
	for (i=0;i<20;i++)
	{
		m[i][0]=zhu[0].time[i];
		for (j=1;j<n;j++)
			if (m[i][0]<zhu[j].time[i])
				m[i][0]=zhu[j].time[i];
	}
	for (i=0;i<20;i++)
	{
		m[i][1]=zhu[0].time[i];
		for (j=1;j<n;j++)
			if (m[i][1]>zhu[j].time[i])
				m[i][1]=zhu[j].time[i];
	}
	for (i=0;i<20;i++)
		m[i][2]=zhu[0].time[i];
		for (j=1;j<n;j++)
			m[i][2]+=zhu[j].time[i];
		m[i][2]/=n;
}



void sortzhu(zhubo zhu[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	zhubo t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(zhu[minpos],zhu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=zhu[i];
			zhu[i]=zhu[minpos];
			zhu[minpos]=t;
		}
	}
}

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[ ])  /*在stu数组中依condition条件查找*/
/*与z相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(zhu[i],z,condition))
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/
		}
	 return find;                                /*返回find，其值为0则表示没找到*/
}

int insertzhu(zhubo zhu[],int n,zhubo z)              /*向zhu数组中依学号递增插入一个元素s*/
{
	int i;
	sortzhu(zhu,n,1);                              /*先按房间号号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(zhu[i],z,1))                      /*房间号相同不允许插入，保证房间号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按房间号从小到大有序*/
	{
		if (!larger(zhu[i],z,1))                    /*如果z大于当前元素zhu[i]，则退出循环*/
		break;
		zhu[i+1]=zhu[i];                         /*否则元素zhu[i]后移一个位置*/
	}
	zhu[i+1]=z;                                /*在下标i+1处插入元素s*/
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deletezhu(zhubo zhu[],int n,zhubo z)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(zhu[i],z,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(zhu[i],s,1)成立*/
		zhu[j]=zhu[j+1];                       /*通过移动覆盖删除下标为i的元素*/

	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}

