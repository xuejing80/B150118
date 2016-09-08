/*②employee.c文件的完整内容*/
#include "employee.h"
#include <stdio.h>

int readEmp(Employee  *emp , int n)          /*读入员工记录值，工号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one employee\'s information\n");
		printf("num:  ");
	     scanf("%ld", &emp[i].num);
		if (emp[i].num==0) break;
		printf("name: ");
		scanf("%s",emp[i].name);	
		printf("sex:  ");
		scanf("%s",emp[i].sex);
    	     emp[i].total=0;                /*总工资需要计算求得，初值置为0*/
		printf("Input three pay of the employee:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&emp[i].score[j]);	
		}
		emp[i].rank=0;                 /*名次需要根据总工资来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printEmp ( Employee  *emp , int n)       /*输出所有员工记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", emp[i].num);
		printf("%8s", emp[i].name);
		printf("%8s", emp[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",emp[i].score[j]);
	    printf("%7d",emp[i].total);
	    printf("%5d\n",emp[i].rank);
	}
}

int equal(Employee e1,Employee e2,int condition)  /*如何判断两个Employee记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较工号*/
		return e1.num==e2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(e1.name,e2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return e1.rank==e2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较总工资*/
		return e1.total==e2.total;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Employee e1,Employee e2,int condition)  /*根据condition条件比较两个Employee记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return e1.num>e2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总工资*/
		return e1.total>e2.total;	
	else return 1; /*其余情况返回1*/
}

void reverse(Employee emp[],int n)             /*数组元素逆置*/
{
	int i;
	Employee temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=emp[i];
		emp[i]=emp[n-1-i];
		emp[n-1-i]=temp;
	}
}

void calcuTotal(Employee emp[],int n)         /*计算所有员工的总工资*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有员工记录*/
	{
		emp[i].total =0;
		for (j=0;j<3;j++)               /*内层循环控制三门功课*/
			emp[i].total +=emp[i].score[j];
	}	
}

void calcuRank(Employee emp[],int n)          /*根据总工资计算所有员工的排名，工资相同者名次相同*/
{
	int i ;                       
	sortEmp(emp,n,2);                     /*先调用sortEmp算法，按总工资由小到大排序*/
	reverse(emp,n);                      /*再逆置，则按总工资由大到小排序了*/
	emp[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(emp[i],emp[i-1],4))         /*当前记录与其相邻的前一条记录如果总工资相等*/
			emp[i].rank=emp[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			emp[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m[3][3],Employee emp[],int n) /*求全公司员工的总税费、总基本工资、总奖金*/
/*其中形式参数二维数组m的第一维代表工资哪一项，第二维代表总税费、总基本工资、总工资*/
{
	int i,j;
    for (i=0;i<3;i++)                 /*求全公司的总税费，总基本工资，总奖金*/
	{ 
		m[i][2]=emp[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=emp[j].score[i];
	}
}

void sortEmp(Employee emp[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Employee t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(emp[minpos],emp[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=emp[i];
			emp[i]=emp[minpos];
			emp[minpos]=t;
		}
	}
}

int searchEmp(Employee emp[],int n,Employee e,int condition,int f[ ])  /*在emp数组中依condition条件查找*/
/*与e相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(emp[i],e,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertEmp(Employee emp[],int n,Employee e)              /*向stu数组中依工号递增插入一个元素s*/
{
	int i;
	sortEmp(emp,n,1);                              /*先按工号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(emp[i],e,1))                      /*工号相同不允许插入，保证工号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按工号从小到大有序*/
	{
		if (!larger(emp[i],e,1))                    /*如果e大于当前元素emp[i]，则退出循环*/
		break;
		emp[i+1]=emp[i];                         /*否则元素emp[i]后移一个位置*/
	}
	emp[i+1]=e;                                /*在下标i+1处插入元素e*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteEmp(Employee emp[],int n,Employee e)            /*从数组中删除指定工号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(emp[i],e,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(emp[i],s,1)成立*/ 
		emp[j]=emp[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
