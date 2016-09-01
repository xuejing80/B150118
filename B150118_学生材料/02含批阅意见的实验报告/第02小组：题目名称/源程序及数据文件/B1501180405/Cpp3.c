/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"product.h"

int baseManage(Product pro[],int n);

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

void countManage(Product pro[],int n)               /*该函数完成商品库存统计功能*/
{
		int choice;
		double count=0.0;
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(count,pro,n);                 /*调用此函数求库存较多及较少商品*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("库存较多商品是:\n",count);  /*输出库存较多商品*/
				      break;
				case 2:   printf("库存较少商品是:\n",count);  /*输出库存较少商品*/
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
			case 5: searchManage(pro,n);     /* 5. 根据条件查询*/
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
/*②product.c文件的完整内容*/
#include "product.h"
#include <stdio.h>

int readPro(Product  *pro , int n)          /*读入商品记录值，编号为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one product\'s information\n");
		printf("num:  ");
	     scanf("%ld", &pro[i].num);
		if (pro[i].num==0) break;
		printf("name: ");
		scanf("%s",pro[i].name);	
		printf("brand:  ");
		scanf("%s",pro[i].brand);
    	    pro[i].total=0;                /*总价需要计算求得，初值置为0*/
		printf("Input the price of the product:\n");
	    scanf("%d",&pro[i].price);
    	printf("count:  ");
		scanf("%s",pro[i].count);
		pro[i].rank=0;                 /*名次需要根据库存来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printPro ( Product  *pro , int n)       /*输出所有商品记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", pro[i].num);
		printf("%8s", pro[i].name);
		printf("%8s", pro[i].brand);
		printf("%6d",pro[i].price);
    	printf("%6d",pro[i].count);
	    printf("%5d\n",pro[i].rank);
	}
}

int equal(Product s1,Product s2,int condition)  /*如何判断两个Product记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较名称*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较库存*/
		return s1.count==s2.count;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Product s1,Product s2,int condition)  /*根据condition条件比较两个Product记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return s1.num>s2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较价格*/
		return s1.price>s2.price;	
	if (condition==3)                    /*如果参数condition的值为3，则比较库存*/
		return s1.count>s2.count;		
	else return 1; /*其余情况返回1*/
}

void reverse(Product pro[],int n)             /*数组元素逆置*/
{
	int i;
	Product temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=pro[i];
		pro[i]=pro[n-1-i];
		pro[n-1-i]=temp;
	}
}

void calcuTotal(Product pro[],int n)         /*计算所有商品的总价格*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有商品记录*/
	{
		pro[i].total =0;
		for (j=0;j<3;j++)               /*内层循环控制商品价格*/
			pro[i].total +=pro[i].price;
	}	
}

void sortPro(Product pro[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Product t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(pro[minpos],pro[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=pro[i];
			pro[i]=pro[minpos];
			pro[minpos]=t;
		}
	}
}


int searchPro(Product pro[],int n,Product s,int condition,int f[ ])  /*在pro数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(pro[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertPro(Product pro[],int n,Product s)              /*向Pro数组中依学号递增插入一个元素s*/
{
	int i;
	sortPro(pro,n,1);                              /*先按编号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(pro[i],s,1))                      /*编号相同不允许插入，保证编号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编号从小到大有序*/
	{
		if (!larger(pro[i],s,1))                    /*如果s大于当前元素pro[i]，则退出循环*/
		break;
		pro[i+1]=pro[i];                         /*否则元素pro[i]后移一个位置*/
	}
	pro[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deletePro(Product pro[],int n,Product s)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(pro[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(pro[i],s,1)成立*/ 
		pro[j]=pro[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}
void calcuRank(Product pro[],int n)          /*根据价格计算所有商品的排名，价格相同者名次相同*/
{
	int i ;                       
	sortPro(pro,n,2);                     /*先调用sortPro算法，按价格由小到大排序*/
	reverse(pro,n);                      /*再逆置，则按价格由大到小排序了*/
	pro[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(pro[i],pro[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/
			pro[i].rank=pro[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			pro[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m,Product pro[],int n) 
{
	int i;
	for (i=0;i<1000;i++)                 /*求库存较高*/		
	{ 
		m=pro[0].count;     
			if (m>800)
				m=pro[i].count;
	}
	for (i=0;i<1000;i++)                  /*求库存较低*/
	{ 
		m=pro[0].count;      
			if (m<10)
				m=pro[i].count;
	}
}
