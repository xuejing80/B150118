#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"zhubo.h"

void printHead( )      /*打印主播信息的表头*/
{
printf("%8s%8s%8s%8s%8s\n","姓名","性别","房间号","类型","总时间");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 主播信息管理 ********\n");
		printf("******** 4. 主播信息统计 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入主播记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除主播记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改主播记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、主播信息管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算总直播时间 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据总时间排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}

void menuCount( )    /*4、主播信息统计菜单函数*/
{
		printf("&&&&&&&& 1. 求直播最长时间 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求直播最短时间 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求直播平均时间 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按房间号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(zhubo zhu[],int n)    	     /*该函数完成基本信息管理*/
/*按房间号进行插入删除修改，学号不能重复*/
{
		int choice,t,find[NUM];
     zhubo z;
do
	    {
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readzhu(&z,1);       /*读入一条待插入的主播记录*/
					 n=insertzhu(zhu,n,z);   /*调用函数插入主播记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&z.num);  /*读入一个待删除的主播学号*/
					 n=deletezhu(zhu,n,z);   /*调用函数删除指定学号的主播记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&z.num);  /*读入一个待修改的主播房间号*/
				      t=searchzhu(zhu,n,z,1,find) ; /*调用函数查找指定主播的信息记录*/
				      if (t)                 /*如果该主播的记录存在*/
					 {
						  readzhu(&z,1);   /*读入一条完整的主播记录信息*/
					      zhu[find[0]]=z;    /*将刚读入的记录赋值给需要修改的数组记录*/
					  }
					 else                 /*如果该主播的记录不存在*/
 printf("this student is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(zhubo zhu[],int n)          /*该函数完成主播信息管理功能*/
{
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(zhu,n);         /*求所有主播的总分*/
					  break;
			case 2:   calcuRank(zhu,n);         /*根据所有主播的总时间排名次*/
				      break;
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[7][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最长、最短、平均*/
int i;
    printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
    for (i=0;i<3;i++)                           /*i控制哪天*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(zhubo zhu[],int n)               /*该函数完成主播信息统计功能*/
{
		int choice;
		double mark[7][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,zhu,n);                 /*调用此函数求七天的最长、最短、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("直播时间最长的是:\n",mark,0);  /*输出最长*/
				      break;
				case 2:   printMarkCourse("直播时间最短的是:\n",mark,1);  /*输出最短*/
				      break;
				case 3:   printMarkCourse("直播的平均时间是:\n",mark,2);  /*输出平均*/
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
				      scanf("%ld",&z.num);         /*输入待查询主播的学号*/
					  break;
				case 2:   printf("Input a zhubo\'s name will be searched:\n");
				      scanf("%s",z.name);	          /*输入待查询主播的姓名*/
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
			case 4: countManage(zhu,n);     /* 4. 主播信息统计*/
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
	sortzhu(zhu,n,1);                   /*存入文件前按总时间由小到大排序*/
	     saveFile(zhu,n);                   /*将结果存入文件*/
      return 0;
}
