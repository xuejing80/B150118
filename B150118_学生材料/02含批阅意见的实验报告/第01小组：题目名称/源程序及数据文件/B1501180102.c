#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"

void printHead( )      /*打印图书信息的表头*/
{
printf("%8s%10s%8s%6s%6s%8s%6s\n","书名","作者","类别","类似图书推荐","类似图书推荐","类似图书推荐","阅览量");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 图书信息管理 ********\n");
		printf("******** 4. 阅览量统计 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuAmount( )     /*3、图书信息管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算日阅览量 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 计算月阅览量 @@@@@@@@\n");
        printf("@@@@@@@@ 3. 计算年阅览量 @@@@@@@@\n");
		printf("@@@@@@@@ 4. 排序日阅览量 @@@@@@@@\n");
		printf("@@@@@@@@ 5. 排序月阅览量 @@@@@@@@\n");
		printf("@@@@@@@@ 6. 排序年阅览量 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuQuantity( )    /*4、图书阅览量统计菜单函数*/
{
		printf("&&&&&&&& 1. 求每日、月、年最高阅览量 &&&&&&&&\n");
		printf("&&&&&&&& 2. 求每日、月、年最低阅览量 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按编号查询   ########\n");
		printf("######## 2. 按书名查询   ########\n");
		printf("######## 3. 按作者查询   ########\n");
		printf("######## 4. 按类别查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}
int baseManage(Book boo[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
		int choice,t,find[NUM];
     Book s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readBook(&s,1);       /*读入一条待插入的图书记录*/
					 n=insertBook(boo,n,s);   /*调用函数插入图书记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的图书编号*/
					 n=deleteBook(boo,n,s);   /*调用函数删除指定编号的图书记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的图书编号*/
				      t=searchBook(boo,n,s,1,find) ; /*调用函数查找指定编号的图书记录*/
				      if (t)                 /*如果该图书的记录存在*/
					 {
						  readBook(&s,1);   /*读入一条完整的图书记录信息*/
					      book[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
 printf("this book is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(Book boo[],int n)          /*该函数完成图书管理功能*/
{  
	int choice;
	do
	{
		menuAmount( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(boo,n);         /*求图书日阅览量*/
					  break;
			case 2:   calcuTotal(boo,n);         /*求图书月阅览量*/
					  break;
			case 3:   calcuTotal(boo,n);         /*求图书年阅览量*/
					  break;
			case 4:   calcuRank(boo,n);         /*排序日阅览量*/
				      break;	
			case 5:   calcuRank(boo,n);         /*排序月阅览量*/
				      break;	
			case 6:   calcuRank(boo,n);         /*排序年阅览量*/
				      break;	
			case 0:   break;
		}
	}while(choice);
}

void quantityManage(Book boo[],int n)               /*该函数完成阅览量统计功能*/
{
		int choice;
		do
		{
			menuQuantity( );                        /*显示对应的二级菜单*/
			readValue(value,boo,n);                 /*调用此函数求每日、月、年最高和最低阅览量*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printValueQuantity("最高阅览量为:\n",value,0);  /*输出最高阅览量*/
				      break;
				case 2:   printValueQuantity("最低阅览量为:\n",value,1);  /*输出最低阅览量*/
				      break;
				case 0:   break;
			}
		}while (choice);
}


void searchManage(book boo[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
book s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a book\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询书本的编号*/
					  break;
				case 2:   printf("Input a book\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询书本的名字*/		  
				      break;   
				case 3:   printf("Input a writer will be searched:\n");
				      scanf("%d",&s.writer);            /*输入待查询书本的作者*/
			          break;
				case 3:   printf("Input a category will be searched:\n");
				      scanf("%d",&s.category);          /*输入待查询书本的类别*/
					  break;
				case 0:   break;
			}	
                 if (choice>=1&&choice<=4)
			{ 
				findnum=searchBoo(boo,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printBoo(&boo[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}
int runMain(Book boo[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortBook(boo,n,1);         /*按编号由小到大的顺序排序记录*/ 
          	     printBook(boo,n);          /*按编号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(boo,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: amountManage(boo,n);     /* 3. 图书信息管理*/
					break;
			case 4: quantityManage(boo,n);     /* 4. 阅览量统计*/
					break;
			case 5: searchManage(boo,n);     /* 5. 根据条件查询*/
				     break;
            case 0: break;
		}
		return n;
}
int main( )
{
		Book boo[NUM];                /*定义实参一维数组存储图书记录*/
      int choice,n;
	 n=readFile(boo);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(boo);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(boo,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortBoo(boo,n,1);                   /*存入文件前按编号由小到大排序*/ 
	     saveFile(boo,n);                   /*将结果存入文件*/
      return 0;
}
