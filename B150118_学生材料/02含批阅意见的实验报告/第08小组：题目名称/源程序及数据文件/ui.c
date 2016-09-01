#include<stdio.h>
void menu( )        
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 运动员信息管理 ********\n");
		printf("******** 3. 运动员成绩管理 ********\n");
		printf("******** 4. 奥运会成绩统计 ********\n");
     printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     
{
		printf("%%%%%%%% 1. 插入运动员信息 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除运动员信息 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改运动员信息 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )    
{
		printf("@@@@@@@@ 1. 计算运动员奖牌个数 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据奖牌个数排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )   
{		printf("&&&&&&&& 1. 求金牌个数最多的运动员 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求银牌个数最多的运动员 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求铜牌个数最多的运动员 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    
{
		printf("######## 1. 按运动员项目查询   ########\n");
		printf("######## 2. 按运动员姓名查询   ########\n");
		printf("######## 3. 按运动员成绩查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage()    	     

{  
		int choice;
     
do
	    {   
         menuBase( );                  
         printf("选择你要使用的选项: ");
		 scanf("%d",&choice);	          
		 switch(choice)
		     {
			   case 1:	break;
			   case 2:  printf("请输入运动员项目\n");
					    break;
			   case 3:  printf("请输入运动员项目\n");
					    break;
			   case 0: break;
		    }
		}
		while(choice);
return 0;                             
}
void scoreManage()          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("选择你要使用的选项:\n");
		scanf("%d",&choice);	                 
		switch(choice)
		{
			case 1:   break;
			case 2:   break;		
			case 0:   break;
		}
	}while(choice);
}
void countManage()               
{
		int choice;
		do
		{
			menuCount( );                        
			printf("选择你要使用的选项:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  break;
				case 2:  break;
				case 3:  break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage()               
{
    int choice;
do
{
			menuSearch( );                         
			printf("选择你要使用的选项:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("请输入待查询运动员项目:\n");
				          break;
				case 2:   printf("请输入待查询运动员姓名:\n");
				      	  break;   
				case 3:   printf("请输入待查询运动员成绩排名:\n");
				          break;
				case 0:   break;
			}
		 
	    }while (choice);
}
int main()    
{
	int choice;
	menu();
    printf("请选择你要使用的选项: ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:  break;
			case 2:  baseManage();    
			   	     break;
			case 3:  scoreManage();     
					 break;
			case 4: countManage();     
					break;
			case 5: searchManage();     
				     break;
          case 0: break;
		}
		return 0;
}