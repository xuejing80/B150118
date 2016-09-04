#include <stdio.h>
#include <stdlib.h>
#include"zhibo.h"

FILE *fp;

void printHead( )
{
printf("%8s%8s%8d%10s%8d%8d%6s\n","姓名","性别","房间号","直播时间","总人数","总时间","游戏");
}

void menu( )
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 主播信息管理 ********\n");
		printf("******** 4. 考试成绩统计 ********\n");
     printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )
{
		printf("%%%%%%%% 2. 删除主播记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改主播记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )
{
		printf("@@@@@@@@ 1. 计算直播时间 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据时间排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}

void menuCount( )
{
    	printf("&&&&&&&& 1. 求直播最长 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求人数最多 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求直播平均 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()
{
		printf("######## 1. 按姓名查询   ########\n");
		printf("######## 2. 按房间查询   ########\n");
		printf("######## 3. 按游戏查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}


int baseManage(zhubo zhu[],int n)
{
		int choice,t,find[NUM];
     zhubo z;
do
	    {
menuBase( );
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);
		    switch(choice)
		     {
			   case 1:	 readzhu(&z,1);
					 n=insertzhu(zhu,n,z);
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&z.num);
					 n=deletezhu(zhu,n,z);
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&z.num);
				      t=searchStu(zhu,n,z,1,find) ;
				      if (t)
					 {
						  readzhu(&z,1);
					      zhu[find[0]]=z;
					  }
					 else
 printf("this zhubo is not in,can not be modified.\n");
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;
}

void scoreManage(zhubo zhu[],int n)
{

    int choice;
	do
	{
		menuScore( );
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   calcuTotal(zhu,n);
					  break;
			case 2:   calcuRank(zhu,n);
				      break;
			case 0:   break;
		}
	}while(choice);
}



void countManage(zhubo zhu[],int n)               /*该函数完成考试成绩统计功能*/
{
		int choice;
		int max,pj,most;
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/

			int calcumost(most, zhu , n) ;                 /*调用此函数求主播的时间最长最高、人气最高、直播平均值*/
			int calcupj(pj, zhu  , n);  /*求直播平均时间*/
			int calcumax(max,  zhu , n) ; /*求直播时间最长*/
			printf("choose one operation you want to do:\n");

			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("直播时间最长的是:\n",max,0);  /*输出直播时间最长*/
				      break;
				case 2:   printMarkCourse("直播人气最高的是:\n",most,1);  /*输出人气最高*/
				      break;
				case 3:   printMarkCourse("直播的平均时间是:\n",pj,2);  /*输出平均时间*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(zhubo zhu[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
    zhubo z;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a zhubo\'s num will be searched:\n");
				      scanf("%ld",&z.num);         /*输入待查询主播的房间号*/
					  break;
				case 2:   printf("Input a zhubo\'s name will be searched:\n");
				      scanf("%s",z.name);	          /*输入待查询主播的姓名*/
				      break;
				case 3:   printf("Input a game will be searched:\n");
				      scanf("%d",&z.game);          /*输入待主播的游戏*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{
				findnum=searchzhu(zhu,n,z,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printzhu(&zhu[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }
	    }while (choice);
}

int runMain(zhubo zhu[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortzhu(zhu,n,1);         /*按学号由小到大的顺序排序记录*/
          	 printzhu(zhu,n);          /*按学号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(zhu,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(zhu,n);     /* 3. 主播信息管理*/
					break;
			case 4: countManage(zhu,n);     /* 4. 直播信息统计*/
					break;
			case 5: searchManage(zhu,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		zhubo zhu[NUM];                /*定义实参一维数组存储主播记录*/
      int choice,n;
	 n=readFile(zhu);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(zhu);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(zhu,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortzhu(zhu,n,1);                   /*存入文件前按学号由小到大排序*/
	     saveFile(zhu,n);                   /*将结果存入文件*/
      return 0;
}
