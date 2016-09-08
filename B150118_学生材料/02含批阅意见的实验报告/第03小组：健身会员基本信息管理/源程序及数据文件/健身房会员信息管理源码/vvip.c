/*②vvip.c文件的完整内容*/
#include "vvip.h"
#include <stdio.h>

int readVip(Vvip  *vip , int n)          /*读入会员记录值，会员号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one vvip\'s information\n");
		printf("num:  ");
	        scanf("%ld", &vip[i].num);
		if (vip[i].num==0) break;
		printf("name: ");
		scanf("%s",vip[i].name);	
		printf("sex:  ");
		scanf("%s",vip[i].sex);
		printf("date: ");
		scanf("%s",vip[i].date);
    	     vip[i].total=0;                /*总次数需要计算求得，初值置为0*/
		printf("Input four quarters of the vvip:\n");
		for (j=0;j<4;j++)
	    {
		    scanf("%d",&vip[i].time[j]);	
		}
		vip[i].rank=0;                 /*名次需要根据总次数来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printVip ( Vvip  *vip , int n)       /*输出所有会员记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", vip[i].num);
		printf("%8s", vip[i].name);
		printf("%8s", vip[i].sex);
		printf("%10s", vip[i].date);
		for (j=0;j<4;j++)
		   printf("%10d",vip[i].time[j]);
	    printf("%10d",vip[i].total);
	    printf("%10d\n",vip[i].rank);
	}
}

int equal(Vvip v1,Vvip v2,int condition)  /*如何判断两个Vvip记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较会员号*/
		return v1.num==v2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(v1.name,v2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return v1.rank==v2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较总次数*/
		return v1.total==v2.total;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Vvip v1,Vvip v2,int condition)  /*根据condition条件比较两个Vvip记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较会员号*/
		return v1.num>v2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总次数*/
		return v1.total>v2.total;	
	else return 1; /*其余情况返回1*/
}

void reverse(Vvip vip[],int n)             /*数组元素逆置*/
{
	int i;
	Vvip temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=vip[i];
		vip[i]=vip[n-1-i];
		vip[n-1-i]=temp;
	}
}

void calcuTotal(Vvip vip[],int n)         /*计算所有会员健身的总次数*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有会员记录*/
	{
		vip[i].total =0;
		for (j=0;j<4;j++)               /*内层循环控制四个季度*/
			vip[i].total +=vip[i].time[j];
	}	
}

void calcuRank(Vvip vip[],int n)          /*根据总分计算所有会员的排名，健身次数相同者名次相同*/
{
	int i ;                       
	sortVip(vip,n,2);                     /*先调用sortVip算法，按总次数由小到大排序*/
	reverse(vip,n);                      /*再逆置，则按总次数由大到小排序了*/
	vip[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(vip[i],vip[i-1],4))         /*当前记录与其相邻的前一条记录如果总次数相等*/
			vip[i].rank=vip[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			vip[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m[4][4],Vvip vip[],int n) /*求四个季度的最高、最低、平均次数*/
/*其中形式参数二维数组m的第一维代表四个季度，第二维代表最高、最低、平均次数*/
{
	int i,j;
	for (i=0;i<4;i++)                 /*求四个季度的最高次数*/		
	{ 
		m[i][0]=vip[0].time[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<vip[j].time[i])
				m[i][0]=vip[j].time[i];
	}
	for (i=0;i<4;i++)                  /*求四个季度的最低次数*/
	{ 
		m[i][1]=vip[0].time[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>vip[j].time[i])
				m[i][1]=vip[j].time[i];
	}
	for (i=0;i<4;i++)                 /*求四个季度的平均次数*/
	{ 
		m[i][2]=vip[0].time[i];     
		for (j=1;j<n;j++)
			m[i][2]+=vip[j].time[i];
		m[i][2]/=n;
	}
}

void sortVip(Vvip vip[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Vvip t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(vip[minpos],vip[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=vip[i];
			vip[i]=vip[minpos];
			vip[minpos]=t;
		}
	}
}

int searchVip(Vvip vip[],int n,Vvip s,int condition,int f[ ])  /*在vip数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(vip[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertVip(Vvip vip[],int n,Vvip v)              /*向vip数组中依学号递增插入一个元素s*/
{
	int i;
	sortVip(vip,n,1);                              /*先按会员号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(vip[i],v,1))                      /*会员号相同不允许插入，保证会员号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按会员号从小到大有序*/
	{
		if (!larger(vip[i],v,1))                    /*如果s大于当前元素vip[i]，则退出循环*/
		break;
		vip[i+1]=vip[i];                         /*否则元素vip[i]后移一个位置*/
	}
	vip[i+1]=v;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteVip(Vvip vip[],int n,Vvip v)            /*从数组中删除指定会员号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(vip[i],v,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(vip[i],s,1)成立*/ 
		vip[j]=vip[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}