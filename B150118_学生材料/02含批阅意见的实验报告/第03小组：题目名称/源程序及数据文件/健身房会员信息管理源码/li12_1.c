/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"vvip.h"

void printHead( )      /*打印会员信息的表头*/
{
printf("%8s%10s%8s%10s%10s%10s%10s%10s%10s%10s\n","会员号","姓名","性别","入会日期","第一季度","第二季度","第三季度","第四季度","总次数","次数排序");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 会员健身次数管理 ********\n");
		printf("******** 4. 季度健身次数统计 ********\n");
            printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入会员记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除会员记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改会员记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuTime( )     /*3、会员健身次数管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算会员健身总次数 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据总次数排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、会员健身次数统计菜单函数*/
{
		printf("&&&&&&&& 1. 求健身最多次数 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求健身最少次数 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求季度健身平均次数 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按会员号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		printf("######## 3. 按次数排序查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Vvip vip[],int n)    	     /*该函数完成基本信息管理*/
/*按会员号进行插入删除修改，会员号不能重复*/
{  
		int choice,t,find[NUM];
     Vvip v;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readVip(&v,1);       /*读入一条待插入的会员记录*/
					 n=insertVip(vip,n,v);   /*调用函数插入会员记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&v.num);  /*读入一个待删除的会员号*/
					 n=deleteVip(vip,n,v);   /*调用函数删除指定会员号的会员记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&v.num);  /*读入一个待修改的会员号*/
				      t=searchVip(vip,n,v,1,find) ; /*调用函数查找指定会员号的会员记录*/
				      if (t)                 /*如果该会员号的记录存在*/
					 {
						  readVip(&v,1);   /*读入一条完整的会员记录信息*/
					      vip[find[0]]=v;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该会员号的记录不存在*/ 
 printf("this vvip is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void timeManage(Vvip vip[],int n)          /*该函数完成会员健身次数信息管理功能*/
{  
	int choice;
	do
	{
		menuTime( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(vip,n);         /*求所有会员的总次数*/
					  break;
			case 2:   calcuRank(vip,n);         /*根据所有会员的总次数排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkQuarter(char *v,double m[4][4],int k)   /*打印健身次数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高次数、最低次数、平均次数*/
int i;
    printf(v);                                  /*这里的v传入的是输出健身次数的提示信息*/
    for (i=0;i<4;i++)                           /*i控制哪一季度*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Vvip vip[],int n)               /*该函数完成健身次数统计功能*/
{
		int choice;
		double mark[4][4];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,vip,n);                 /*调用此函数求四个季度的最高、最低、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkQuarter("四个季度的最高次数分别是:\n",mark,0);  /*输出最高次数*/
				      break;
				case 2:   printMarkQuarter("四个季度的最低次数分别是:\n",mark,1);  /*输出最低次数*/
				      break;
				case 3:   printMarkQuarter("四个季度的平均次数分别是:\n",mark,2);  /*输出平均次数*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Vvip vip[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Vvip v;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a vvip\'s num will be searched:\n");
				      scanf("%ld",&v.num);         /*输入待查询会员的会员号*/
					  break;
				case 2:   printf("Input a vvip\'s name will be searched:\n");
				      scanf("%s",v.name);	          /*输入待查询会员的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&v.rank);          /*输入待查询会员的名次*/
				      break;
                        case 0:   break;
 			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchVip(vip,n,v,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printVip(&vip[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Vvip vip[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortVip(vip,n,1);         /*按会员号由小到大的顺序排序记录*/ 
          	 printVip(vip,n);          /*按会员号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(vip,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: timeManage(vip,n);     /* 3. 会员健身次数管理*/
					break;
			case 4: countManage(vip,n);     /* 4. 会员健身次数统计*/
					break;
			case 5: searchManage(vip,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Vvip vip[NUM];                /*定义实参一维数组存储会员记录*/
      int choice,n;
	 n=readFile(vip);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(vip);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(vip,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortVip(vip,n,1);                   /*存入文件前按会员号由小到大排序*/ 
	     saveFile(vip,n);                   /*将结果存入文件*/
      return 0;
}

