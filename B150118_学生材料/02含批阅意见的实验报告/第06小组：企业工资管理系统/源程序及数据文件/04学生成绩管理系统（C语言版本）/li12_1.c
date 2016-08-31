/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"employee.h"

void printHead( )      /*打印员工信息的表头*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","工号","姓名","性别","基本工资","税率","奖金","总工资","名次");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 员工绩效管理 ********\n");
		printf("******** 4. 工资统计分析 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入员工记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除员工记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改员工记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、员工工资管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算员工工资 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据工资排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、工资统计分析菜单函数*/
{
		printf("&&&&&&&& 1. 求总工资税费 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求总基本工资 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求总奖金金额 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按工号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		printf("######## 3. 按名次查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Employee emp[],int n)    	     /*该函数完成基本信息管理*/
/*按工号进行插入删除修改，工号不能重复*/
{  
		int choice,t,find[NUM];
     Employee s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readEmp(&s,1);       /*读入一条待插入的员工记录*/
					 n=insertEmp(emp,n,s);   /*调用函数插入员工记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的员工工号*/
					 n=deleteStu(emp,n,s);   /*调用函数删除指定工号的员工记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的员工工号*/
				      t=searchEmp(emp,n,s,1,find) ; /*调用函数查找指定工号的员工记录*/
				      if (t)                 /*如果该工号的记录存在*/
					 {
						  readEmp(&s,1);   /*读入一条完整的员工记录信息*/
					      emp[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该工号的记录不存在*/ 
 printf("this employee is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(Employee emp[],int n)          /*该函数完成员工工资管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(emp,n);         /*求所有员工的工资*/
					  break;
			case 2:   calcuRank(emp,n);         /*根据所有员工的工资排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应总工资税费、总基本工资、总奖金金额*/
int i;
    printf(s);                                  /*这里的s传入的是输出工资的提示信息*/
    for (i=0;i<3;i++)                           /*i控制哪一门课*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Employee emp[],int n)               /*该函数完成工资统计分析功能*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,emp,n);                 /*调用此函数求总工资税费、总基本工资、总奖金金额*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("员工总工资税费是:\n",mark,0);  /*输出总税费*/
				      break;
				case 2:   printMarkCourse("员工总基本工资是:\n",mark,1);  /*输出总基本工资*/
				      break;
				case 3:   printMarkCourse("员工总奖金金额是:\n",mark,2);  /*输出总奖金*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Employee emp[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Employee s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a employee\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询员工的工号*/
					  break;
				case 2:   printf("Input a employee\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询员工的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*输入待查询员工的名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchEmp(emp,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printEmp(&emp[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Employee emp[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortEmp(emp,n,1);         /*按工号由小到大的顺序排序记录*/ 
          	 printStu(emp,n);          /*按工号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(emp,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(emp,n);     /* 3. 员工工资管理*/
					break;
			case 4: countManage(emp,n);     /* 4. 工资统计分析*/
					break;
			case 5: searchManage(emp,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Employee emp[NUM];                /*定义实参一维数组存储员工记录*/
      int choice,n;
	 n=readFile(emp);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(emp);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(emp,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortEmp(emp,n,1);                   /*存入文件前按工号由小到大排序*/ 
	     saveFile(emp,n);                   /*将结果存入文件*/
      return 0;
}
/*②student.c文件的完整内容*/
#include "employee.h"
#include <stdio.h>

int readEmp(Emlpoyee  *emp, int n)          /*读入学生记录值，学号为0或读满规定条数记录时停止*/
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
    	     emp[i].total=0;                /*总分需要计算求得，初值置为0*/
		printf("Input three courses of the employee:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&emp[i].score[j]);	
		}
		emp[i].rank=0;                 /*名次需要根据总分来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printEmp ( Employee  *emp , int n)       /*输出所有学生记录的值*/
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

int equal(Employee s1,Employee s2,int condition)  /*如何判断两个Student记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较总分*/
		return s1.total==s2.total;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Employee s1,Employee s2,int condition)  /*根据condition条件比较两个Student记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return s1.num>s2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总分*/
		return s1.total>s2.total;	
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

void calcuTotal(Employee emp[],int n)         /*计算所有学生的总分*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有学生记录*/
	{
		emp[i].total =0;
		for (j=0;j<3;j++)               /*内层循环控制三门功课*/
			emp[i].total +=emp[i].score[j];
	}	
}

void calcuRank(Employee emp[],int n)          /*根据总分计算所有学生的排名，成绩相同者名次相同*/
{
	int i ;                       
	sortEmp(emp,n,2);                     /*先调用sortStu算法，按总分由小到大排序*/
	reverse(emp,n);                      /*再逆置，则按总分由大到小排序了*/
	emp[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(emp[i],emp[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/
			emp[i].rank=emp[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			emp[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m[3][3],Employee emp[],int n) /*求三门课的最高、最低、平均分*/
/*其中形式参数二维数组m的第一维代表三门课，第二维代表最高、最低、平均分*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*求三门课的最高分*/		
	{ 
		m[i][0]=emp[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<emp[j].score[i])
				m[i][0]=emp[j].score[i];
	}
	for (i=0;i<3;i++)                  /*求三门课的最低分*/
	{ 
		m[i][1]=emp[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>emp[j].score[i])
				m[i][1]=emp[j].score[i];
	}
	for (i=0;i<3;i++)                 /*求三门课的平均分*/
	{ 
		m[i][2]=emp[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=emp[j].score[i];
		m[i][2]/=n;
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

int searchEmp(Employee emp[],int n,Employee s,int condition,int f[ ])  /*在stu数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(emp[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertEmp(Employee emp[],int n,Employee s)              /*向stu数组中依学号递增插入一个元素s*/
{
	int i;
	sortEmp(emp,n,1);                              /*先按学号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(emp[i],s,1))                      /*学号相同不允许插入，保证学号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按学号从小到大有序*/
	{
		if (!larger(emp[i],s,1))                    /*如果s大于当前元素stu[i]，则退出循环*/
		break;
		emp[i+1]=emp[i];                         /*否则元素stu[i]后移一个位置*/
	}
	emp[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteEmp(Employee emp[],int n,Employee s)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(emp[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/ 
		emp[j]=emp[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
