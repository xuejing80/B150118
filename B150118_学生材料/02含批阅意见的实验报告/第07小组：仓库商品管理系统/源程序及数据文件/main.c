#include <stdio.h>
#include <stdlib.h>


#include"file.h" 
#include"goods.h"
void printHead()     /*打印商品信息的表头*/
{
	printf("%8s%10s%8s%10s%10s%6s%6s\n","编号","名称","品牌","入库量","出库量","库存","排名");
}
void menu( )     /*一级菜单函数*/   
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 物品信息管理 ********\n");
		printf("******** 3. 物品库存管理 ********\n");
		printf("******** 4. 物品库存统计 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )    /*商品库存管理菜单函数*/ 
{
		printf("@@@@@@@@ 1. 计算物品库存 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据库存排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )   /*商品库存统计菜单函数*/
{		printf("&&&&&&&& 1. 求出库量最大和入库量最大的物品 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求出库量最小和入库量最小的物品 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单       &&&&&&&&\n");
}

void menuSearch()    /*根据条件查询菜单函数*/
{
		printf("######## 1. 按物品编号查询   ########\n");
		printf("######## 2. 按物品名称查询   ########\n");
		printf("######## 3. 按库存排名查询   ########\n");
		printf("######## 0. 返回上层菜单     ########\n");
}

int baseManage(Goods good[],int n)    	     

{  
		int choice,t,find[NUM];
		Goods g;
     
do
	    {   
         menuBase( );                  
         printf("选择你要使用的选项:\n ");
		 scanf("%d",&choice);	          
		 switch(choice)
		     {
			   case 1: readGood(&g,1);
				       n=insertGood(good,n,g);
				       break;
			   case 2:  printf("请输入商品编号\n");
				   scanf("%ld",&g.num);
				   n=deleteGood(good,n,g);
					    break;
			   case 3:  printf("请输入商品编号\n");
				   scanf("%ld",&g.num);
				   t=searchGood(good,n,g,1,find);
if (t)                 
					 {
						  readGood(&g,1);  
					      good[find[0]]=g;     					 
					  }					 
					 else                 
 printf("这个物品不存在不能被修改.\n"); 
					    break;
			   case 0: break;
		    }
		}
		while(choice);
return n;                             
}
void scoreManage(Goods good[],int n)          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("选择你要使用的选项:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:   calcuStock(good,n);
				      break;
			case 2:   calcuRank(good,n); 
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *s,double m[2][2],int k)   
{                 
int i;
    printf(s);                                  
    for (i=0;i<2;i++)                           
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}
void countManage(Goods good[],int n)               
{
		int choice;
		double mark[2][2];
		do
		{
			menuCount( );  
			calcuMark(mark,good,n);
			printf("选择你要使用的选项:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  printMarkCourse("入库量和出库量最大的分别是:\n",mark,0);
					break;
				case 2:  printMarkCourse("入库量和出库量最小分别是:\n",mark,1);
					break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage(Goods good[],int n)               
{
    int i,choice,findnum,f[NUM];
	Goods g;
do
{
			menuSearch( );                         
			printf("选择你要使用的选项:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("请输入待查询商品编号:\n");
					scanf("%ld",&g.num);
				          break;
				case 2:   printf("请输入待查询商品名称:\n");
					scanf("%s",&g.name);
				      	  break;   
				case 3:   printf("请输入待查询商品排名:\n");
					scanf("%d",&g.rank);
				          break;
				case 0:   break;
			}
		 
	    
if(choice>=1&&choice<=3)
{
	findnum=searchGood(good,n,g,choice,f);
	if(findnum)
	{
		printHead();
		for(i=0;i<findnum;i++)
			printGood(&good[f[i]],1);
	}
	else
		printf("这个物品不存在!\n");}
}
while(choice);
}
int runMain(Goods good[],int n,int choice)    
{
		switch(choice)
		{
			case 1: printHead();
				sortGood(good,n,1);
				printGood(good,n);
				break;
			case 2:  n=baseManage(good,n);    
			   	     break;
			case 3:  scoreManage(good,n);     
					 break;
			case 4: countManage(good,n);     
					break;
			case 5: searchManage(good,n);     
				     break;
          case 0: break;
		}
		return n;
}
int main( )
{
		Goods good[NUM];                
      int choice,n;
	 n=readFile(good);                  
	 if (!n)                          
	     {
		    n=createFile(good);              
}	 	 
	do
	     {
	         menu();                      
	         printf("请选择你要使用的选项: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(good,n,choice);    
	         else 
		          printf("选项错误，请重新输入!\n");
	} while (choice);
	sortGood(good,n,1);                   
	     saveFile(good,n);                   
      return 0;
}


