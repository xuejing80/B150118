
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"food.h"

void printHead( )      /*打印菜品信息的表头*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","序号","菜名","菜系","色","香","味","总分","名次");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 菜品评分管理 ********\n");
		printf("******** 4. 评分项目统计 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入菜品记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除菜品记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改菜品记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、菜品评分菜单函数*/
{
		printf("@@@@@@@@ 1. 计算菜品总分 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据总分排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、评分项目菜单函数*/
{
		printf("&&&&&&&& 1. 求评分最高分 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求评分最低分 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求评分平均分 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按序号查询   ########\n");
		printf("######## 2. 按菜名查询   ########\n");
		printf("######## 3. 按名次查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Food foo[],int n)    	     /*该函数完成基本信息管理*/
/*按序号进行插入删除修改，序号不能重复*/
{  
		int choice,t,find[NUM];
     Food s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readFoo(&s,1);       /*读入一条待插入的菜品记录*/
					 n=insertFoo(foo,n,s);   /*调用函数插入菜品记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的菜品序号*/
					 n=deleteFoo(foo,n,s);   /*调用函数删除指定序号的菜品记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的菜品序号*/
				      t=searchFoo(foo,n,s,1,find) ; /*调用函数查找指定序号的菜品记录*/
				      if (t)                 /*如果该学号的记录存在*/
					 {
						  readFoo(&s,1);   /*读入一条完整的菜品记录信息*/
					      foo[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该序号的记录不存在*/ 
 printf("this food is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(Food foo[],int n)          /*该函数完成菜品评分管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(foo,n);         /*求所有菜品的总分*/
					  break;
			case 2:   calcuRank(foo,n);         /*根据所有菜品的总分排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高分、最低分、平均分*/
int i;
    printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
    for (i=0;i<3;i++)                           /*i控制哪一个评分项目*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Food foo[],int n)               /*该函数完成评分成绩统计功能*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,foo,n);                 /*调用此函数求三个评分项目的最高、最低、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("三个评分项目的最高分分别是:\n",mark,0);  /*输出最高分*/
				      break;
				case 2:   printMarkCourse("三个评分项目的最低分分别是:\n",mark,1);  /*输出最低分*/
				      break;
				case 3:   printMarkCourse("三个评分项目的平均分分别是:\n",mark,2);  /*输出平均分*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Food foo[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Food s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a food\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询菜品的序号*/
					  break;
				case 2:   printf("Input a food\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询菜品的名字*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*输入待查询菜品的排名*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchFoo(foo,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printFoo(foo[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Food foo[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortFoo(foo,n,1);         /*按序号由小到大的顺序排序记录*/ 
          	 printFoo(foo,n);          /*按序号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(foo,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(foo,n);     /* 3. 菜品评分管理*/
					break;
			case 4: countManage(foo,n);     /* 4. 菜品评分统计*/
					break;
			case 5: searchManage(foo,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Food foo[NUM];                /*定义实参一维数组存储菜品记录*/
      int choice,n;
	 n=readFile(foo);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(foo);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(foo,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortFoo(foo,n,1);                   /*存入文件前按序号由小到大排序*/ 
	     saveFile(foo,n);                   /*将结果存入文件*/
      return 0;
}