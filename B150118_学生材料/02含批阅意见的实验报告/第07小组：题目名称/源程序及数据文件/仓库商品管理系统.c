#include<stdio.h>
void menu( )        
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 物品信息管理 ********\n");
		printf("******** 3. 物品库存管理 ********\n");
		printf("******** 4. 物品库存统计 ********\n");
     printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     
{
		printf("%%%%%%%% 1. 插入物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改物品信息 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )    
{
		printf("@@@@@@@@ 1. 计算物品库存 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据价格排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )   
{		printf("&&&&&&&& 1. 求出库量最大的物品 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求入库量最大的物品 &&&&&&&&\n");
		printf("&&&&&&&& 3. 求销售额最大的物品 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    
{
		printf("######## 1. 按物品编号查询   ########\n");
		printf("######## 2. 按物品名称查询   ########\n");
		printf("######## 3. 按价格排名查询   ########\n");
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
			   case 2:  printf("请输入商品编号\n");
					    break;
			   case 3:  printf("请输入商品编号\n");
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
				case 1:   printf("请输入待查询商品编号:\n");
				          break;
				case 2:   printf("请输入待查询商品姓名:\n");
				      	  break;   
				case 3:   printf("请输入待查询商品价格排名:\n");
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