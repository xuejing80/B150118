#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"book.h"
 
void printHead( )      /*打印图书信息的表头*/
{
	printf("%s\t%s\t\t%s\t%s\t%s\t%s\t%s\t%s\n","编号","书名","作者","类别","位置","信息","借阅时间","应归还时间");
}

void menu()      /*顶层菜单函数*/
{
	printf("*****1.显示基本信息*****\n");
    printf("*****2.基本信息管理*****\n");
    printf("*****3.图书信息管理*****\n");
    printf("*****4.根据条件查询*****\n");
    printf("*****0.退出        *****\n");
}
void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 排序所有图书 %%%%%%%%\n");
        printf("%%%%%%%% 4. 修改图书记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}
void menuMessage( )     /*3、图书信息管理菜单函数*/
{

		printf("@@@@@@@@ 1. 显示图书所在位置 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 显示借阅人信息   @@@@@@@@\n");
        printf("@@@@@@@@ 3. 显示借阅时间     @@@@@@@@\n");
		printf("@@@@@@@@ 4. 显示应归还时间   @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单     @@@@@@@@\n");
}
 
void menuSearch()    /*4、根据条件查询菜单函数*/
{
		printf("######## 1. 按编号查询   ########\n");
		printf("######## 2. 按书名查询   ########\n");
		printf("######## 3. 按作者查询   ########\n");
		printf("######## 4. 按类别查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Book boo[],int n)    	     /*该函数完成基本信息管理*/
                                             /*按编号进行插入删除修改，编号不能重复*/
{  int choice,t,find[NUM];
   Book s;
   do
   {   
	   menuBase( );                  /*显示对应的二级菜单*/
       printf("choose one operation you want to do:\n");
	   scanf("%d",&choice);	          /*读入选项*/
	   switch(choice)
	   {
	     case 1:readOneBook(&s);       /*读入一条待插入的图书记录，初始化s*/
				n=insertBoo(boo,n,s);/*调用函数插入图书记录*/
				break;
		 case 2:printf("Input the number deleted\n");
			    scanf("%ld",&s);  /*读入一个待删除的图书编号*/
				n=deleteBoo(boo,n,s);   /*调用函数删除指定编号的图书记录*/
				break;
         case 3:printf("Input the number sorted\n");
				scanf("%ld",&s);  /*读入一个待排序的图书编号*/
				sortBoo(boo,n) ; /*调用函数排序指定编号的图书*/
                break;
		 case 4:printf("Input the number modified\n");
			    scanf("%ld",&s);  /*读入一个待修改的图书编号*/
				t=searchBoo(boo,n,s,1,find) ; /*调用函数查找指定编号的图书记录*/
				if (t)                 /*如果该图书的记录存在*/
				{
					readBoo(&s,1);   /*读入一条完整的图书记录信息*/
					boo[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
				}					 
				else                 /*如果该编号的记录不存在*/ 
                printf("this book is not in,can not be modified.\n"); /*输出提示信息*/
				break;
			    case 0: break;
		}
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void messageManage(Book boo[],int n)          /*该函数完成图书信息管理功能*/
{  
	int choice,num,i,resultnum;
	do
	{
		menuMessage( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);  /*读入二级选项*/
		if (choice==0) break;
		else if (choice <1|| choice >4)
		{ printf("输入不合法\n");
		continue;}
		printf("请输入编号:\n");
		scanf("%d",&num);
		for (i = 0;i < n;i++) if (boo[i].num==num) resultnum=i;
		switch(choice)
		{
			case 1:
				
				printf("图书所在位置为：\n%d\n\n",boo[resultnum].location);         /*显示图书所在位置*/
					  break;
			case 2:   
			
				printf("借阅人信息为：\n%s\n\n",boo[resultnum].information);     /*显示借阅人信息*/
					  break;
			case 3:   
				printf("借阅时间为：\n%s\n\n",boo[resultnum].botime);         /*显示借阅时间*/
				      break;	
			case 4:    
				printf("应归还时间为：\n%s\n\n",boo[resultnum].retime);       /*显示归还时间*/
				      break;	
			case 0:   break;
		}
	}while(choice);
}







void searchManage(Book boo[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
    Book s;
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
				      scanf("%s",&s.name);	          /*输入待查询书本的名字*/		  
				      break;   
				case 3:   printf("Input a writer will be searched:\n");
				      scanf("%s",&s.writer);            /*输入待查询书本的作者*/
			          break;
				case 4:   printf("Input a category will be searched:\n");
				      scanf("%s",&s.category);          /*输入待查询书本的类别*/
					  break;
				case 0:   break;
			}	
                 if (choice>=1&&choice<=4)
			{ 
				findnum=searchBoo(boo,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)        /*循环控制f数组的下标*/
	      	         printBoo(&boo[f[i]],1);        /*每次输出一条记录*/
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
				    printBoo(boo,n);
					break;
			case 2: n=baseManage(boo,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: messageManage(boo,n);     /* 3. 图书信息管理*/
					break;
        	case 4: searchManage(boo,n);     /* 4. 根据条件查询*/
				     break;
            case 0: break;
		}
		return n;
}




int main()
{
	int n,m,choice,z;
	Book boo[2000];

	printf("欢迎进入图书馆图书管理系统\n\n");
	printf("1 进入系统\n0 退出系统\n\n\n");
	scanf("%d",&z);
	if(z==0)
		return 0;
    if(z==1)
    printf("请输入密码：\n");
	scanf("%d",&m);
    if(m==888888)
	{ 
            n=readFile(boo);              /*首先读取文件，记录条数返回赋值给n*/
	        if(!n)                        /*如果原来的文件为空*/
			{
				n=createFile(boo);        /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
			}
			do
			{
	        menu();                      /*显示主菜单*/
	        printf("Please input your choice: ");
	        scanf("%d",&choice);
	        if (choice>=0&&choice<=4)
	             n=runMain(boo,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	        else 
		         printf("error input,please input your choice again!\n");
			} while (choice);
			
	     sortBoo(boo,n);                   /*存入文件前按编号由小到大排序*/ 
	     saveFile(boo,n);                   /*将结果存入文件*/
	}
	else
	{
		printf("密码输入错误，系统将自动退出\n");
		return 0;
	}
	return 0;
}




