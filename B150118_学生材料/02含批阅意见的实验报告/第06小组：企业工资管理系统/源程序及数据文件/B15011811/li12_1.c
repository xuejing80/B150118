/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"employee.h"

void printHead( )      /*打印员工信息的表头*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","工号","姓名","性别","税费","基本工资","奖金","总工资","名次");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 员工工资管理 ********\n");
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
		printf("@@@@@@@ 1. 计算员工总工资 @@@@@@@\n");
		printf("@@@@@@@ 2. 根据总工资排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、工资统计菜单函数*/
{
		printf("&&&&&&&& 1. 求总税费、总基本工资、总奖金 &&&&&&&&\n");
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
/*按学号进行插入删除修改，工号不能重复*/
{  
		int choice,t,find[NUM];
     Employee e;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readEmp(&e,1);       /*读入一条待插入的员工记录*/
					 n=insertEmp(emp,n,e);   /*调用函数插入员工记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&e.num);  /*读入一个待删除的员工工号*/
					 n=deleteEmp(emp,n,e);   /*调用函数删除指定工号的员工记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&e.num);  /*读入一个待修改的员工工号*/
				      t=searchEmp(emp,n,e,1,find) ; /*调用函数查找指定工号的员工记录*/
				      if (t)                 /*如果该工号的记录存在*/
					 {
						  readEmp(&e,1);   /*读入一条完整的员工记录信息*/
					      emp[find[0]]=e;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
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
			case 1:   calcuTotal(emp,n);         /*求员工的总工资*/
					  break;
			case 2:   calcuRank(emp,n);         /*根据所有员工的总工资排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *e,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应总税费、总基本工资、总奖金*/
int i;
    printf(e);                                  /*这里的e传入的是输出工资的提示信息*/
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
			calcuMark(mark,emp,n);                 /*调用此函数求三门课的最高、最低、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
			    case 1:   printMarkCourse("所有员工总税费、总基本工资、总奖金是:\n",mark,2);  /*输出总奖金*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Employee emp[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
    Employee e;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a employee\'s num will be searched:\n");
				      scanf("%ld",&e.num);         /*输入待查询员工的学号*/
					  break;
				case 2:   printf("Input a employee\'s name will be searched:\n");
				      scanf("%s",e.name);	          /*输入待查询员工的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&e.rank);          /*输入待查询员工的工资名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchEmp(emp,n,e,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
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
          	 printEmp(emp,n);          /*按学号由小到大的顺序输出所有记录*/
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
