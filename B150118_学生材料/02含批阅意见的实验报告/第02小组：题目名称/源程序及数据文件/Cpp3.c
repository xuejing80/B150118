/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"product.h"

void printHead( )      /*打印商品信息的表头*/
{
printf("%8s%10s%8s%6s%6s\n","","商品编号","名称","品牌","价格","库存");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2.商品信息管理 ********\n");
		printf("******** 3.商品库存统计 ********\n");
     printf("********  4. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入商品记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除商品记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改商品记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuPrice( )     /*3、商品价格管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算商品总价 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 根据价格排名 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、商品库存统计菜单函数*/
{
		printf("&&&&&&&& 1. 求库存较多 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求库存最少 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按商品编号查询   ########\n");
		printf("######## 2. 按名称查询   ########\n");
		printf("######## 3. 按品牌查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Product pro[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
		int choice,t,find[NUM];
     Product s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readPro(&s,1);       /*读入一条待插入的商品记录*/
					 n=insertPro(pro,n,s);   /*调用函数插入商品记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的商品编号*/
					 n=deletePro(pro,n,s);   /*调用函数删除指定编号的商品记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的商品编号*/
				      t=searchPro(pro,n,s,1,find) ; /*调用函数查找指定编号的商品记录*/
				      if (t)                 /*如果该编号的记录存在*/
					 {
						  readPro(&s,1);   /*读入一条完整的商品记录信息*/
					      pro[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
 printf("this product is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void priceManage(Product pro[],int n)          /*该函数完成商品价格管理功能*/
{  
	int choice;
	do
	{
		menuPrice( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(pro,n);         /*求所有商品的总价格*/
					  break;
			case 2:   calcuRank(pro,n);         /*根据商品的价格排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void countManage(Student stu[],int n)               /*该函数完成商品库存统计功能*/
{
		int choice;
		double mark[2][2];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(count,pro,n);                 /*调用此函数求库存较多及较少商品*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("库存较多商品是:\n",mark,0);  /*输出库存较多商品*/
				      break;
				case 2:   printMarkCourse("库存较少商品是:\n",mark,1);  /*输出库存较少商品*/
				      break;
				case 0:   break;
			}
		}while (choice);
}






void searchManage(Product pro[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Product s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a product\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询商品的编号*/
					  break;
				case 2:   printf("Input a product\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询商品的名称*/		  
				      break;   
				case 3:   printf("Input a brand will be searched:\n");
				      scanf("%d",&s.brand);          /*输入待查询商品的品牌*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchPro(pro,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printPro(&pro[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Product pro[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortPro(pro,n,1);         /*按编号由小到大的顺序排序记录*/ 
          	 printPro(pro,n);          /*按编号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(pro,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: priceManage(pro,n);     /* 3. 商品价格管理*/
					break;
			case 4: countManage(pro,n);     /* 4. 库存统计*/
					break;
			case 5: searchManage(stu,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}


int baseManage(Product pro[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
		int choice,t,find[NUM];
    Product  s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readPro(&s,1);       /*读入一条待插入的商品记录*/
					 n=insertPro(pro,n,s);   /*调用函数插入商品记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的商品编号*/
					 n=deletePro(pro,n,s);   /*调用函数删除指定编号的商品记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的商品编号*/
				      t=searchPro(pro,n,s,1,find) ; /*调用函数查找指定编号的商品记录*/
				      if (t)                 /*如果该编号的记录存在*/
					 {
						  readPro(&s,1);   /*读入一条完整的商品记录信息*/
					      pro[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
 printf("this product is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}


int main( )
{
		Product pro[NUM];                /*定义实参一维数组存储商品记录*/
      int choice,n;
	 n=readFile(pro);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(pro);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pro,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPro(pro,n,1);                   /*存入文件前按编号由小到大排序*/ 
	     saveFile(pro,n);                   /*将结果存入文件*/
      return 0;
}

