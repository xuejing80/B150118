/*②food.c文件的完整内容*/
#include "food.h"
#include <stdio.h>

int readFoo(Food  *foo , int n)          /*读入菜品记录值，序号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one food\'s information\n");
		printf("num:  ");
	     scanf("%ld", &foo[i].num);
		if (foo[i].num==0) break;
		printf("name: ");
		scanf("%s",foo[i].name);	
		printf("style:  ");
		scanf("%s",foo[i].style);
		printf("taste:  ");
		scanf("%s",foo[i].taste);
    	foo[i].total=0;                /*总分需要计算求得，初值置为0*/
		printf("Input three mark of the food:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%lf",&foo[i].score[j]);	
		}
		foo[i].rank=0;                 /*名次需要根据总分来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printFoo ( Food   *foo , int n)       /*输出所有菜品记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%6ld  ", foo[i].num);
		printf("%8s", foo[i].name);
		printf("%8s", foo[i].style);
		printf("%4s",foo[i].taste);
		for (j=0;j<3;j++)
		   printf("       %3.1f",foo[i].score[j]);
		printf("   ");
	    printf("  %3.1f",foo[i].total);
	    printf("%7d\n",foo[i].rank);
	}
}

int equal(Food s1,Food s2,int condition)  /*如何判断两个菜品记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较序号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较菜名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较总分*/
		return s1.total==s2.total;
 else if(condition==5)                 /*如果参数condition的值为5，则比较口味*/
	    {
	     if (strcmp(s1.taste,s2.taste)==0) 	return 1;
		else return 0;
     }
	else return 1;                       /*其余情况返回1*/
}

int larger(Food s1,Food s2,int condition)  /*根据condition条件比较两个菜品记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较序号*/
		return s1.num>s2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总分*/
		return s1.total>s2.total;	
	else return 1; /*其余情况返回1*/
}

void reverse(Food foo[],int n)             /*数组元素逆置*/
{
	int i;
	Food temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=foo[i];
		foo[i]=foo[n-1-i];
		foo[n-1-i]=temp;
	}
}

void calcuTotal(Food foo[],int n)         /*计算所有菜品的总分*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有菜品记录*/
	{
		foo[i].total =0;
		for (j=0;j<3;j++)               /*内层循环控制三个评分项目*/
			foo[i].total +=foo[i].score[j];
	}	
}

void calcuRank(Food foo[],int n)          /*根据总分计算所有菜品的排名，总分相同者名次相同*/
{
	int i ;                       
	sortFoo(foo,n,2);                     /*先调用sortFoo算法，按总分由小到大排序*/
	reverse(foo,n);                      /*再逆置，则按总分由大到小排序了*/
	foo[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(foo[i],foo[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/
			foo[i].rank=foo[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			foo[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m[3][3],Food foo[],int n) /*求三个评分项目的最高、最低、平均分*/
/*其中形式参数二维数组m的第一维代表三各评分项目，第二维代表最高、最低、平均分*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*求三个评分项目的最高分*/		
	{ 
		m[i][0]=foo[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<foo[j].score[i])
				m[i][0]=foo[j].score[i];
	}
	for (i=0;i<3;i++)                  /*求三个评分项目的最低分*/
	{ 
		m[i][1]=foo[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>foo[j].score[i])
				m[i][1]=foo[j].score[i];
	}
	for (i=0;i<3;i++)                 /*求三个评分项目的平均分*/
	{ 
		m[i][2]=foo[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=foo[j].score[i];
		m[i][2]/=n;
	}
}

void sortFoo(Food foo[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Food t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(foo[minpos],foo[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=foo[i];
			foo[i]=foo[minpos];
			foo[minpos]=t;
		}
	}
}

int searchFoo(Food foo[],int n,Food s,int condition,int f[ ])  /*在foo数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(foo[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}


int insertFoo(Food foo[],int n,Food s)              /*向foo数组中依序号递增插入一个元素s*/
{
	int i;
	sortFoo(foo,n,1);                              /*先按序号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(foo[i],s,1))                      /*序号相同不允许插入，保证序号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按序号从小到大有序*/
	{
		if (!larger(foo[i],s,1))                    /*如果s大于当前元素foo[i]，则退出循环*/
		break;
		foo[i+1]=foo[i];                         /*否则元素foo[i]后移一个位置*/
	}
	foo[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteFoo(Food foo[],int n,Food f)            /*从数组中删除指定序号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(foo[i],f,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(foo[i],s,1)成立*/ 
		foo[j]=foo[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}