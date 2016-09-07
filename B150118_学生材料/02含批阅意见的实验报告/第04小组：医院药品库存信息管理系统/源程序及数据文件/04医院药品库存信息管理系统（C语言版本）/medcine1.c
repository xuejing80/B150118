/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"medcine.h"

void printHead( )      /*打印药品信息的表头*/
{
printf("%4s%10s%6s%6s%10s%6s%10s%10s%8s%10s\n","编码","药品名称","类型","规格","库存数量","价格","入库时间","出库时间","保质期","到期时间");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 药品库存信息   ********\n");
		printf("******** 2. 药品进出库管理 ********\n");
		printf("******** 3. 即将到期药品   ********\n");
        printf("******** 4. 根据条件查询   ********\n");
		printf("******** 0. 退出           ********\n");
}

void menuScore( )     /*2、药品进出库管理菜单函数*/
{
		printf("@@@@@@@@ 1. 药品进出库     @@@@@@@@\n");
        printf("@@@@@@@@ 2. 修改库存信息 @@@@@@@@\n");
        printf("@@@@@@@@ 3. 删除药品     @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}


void menuSearch()    /*4、根据条件查询菜单函数*/
{
		printf("######## 1. 按药品编码查询   ########\n");
		printf("######## 2. 按药品名称查询   ########\n");
		printf("######## 3. 按入库时间查询   ########\n");
		printf("######## 0. 返回上层菜单     ########\n");
}


int scoreManage(Medcine med[],int n)    	     /*该函数完成基本信息管理*/
/*按学号进行插入删除修改，学号不能重复*/
{  
	int choice,t,find[COD];
	Medcine s;
	do
	{   
		menuScore( );                  /*显示对应的二级菜单*/
		printf("请输入你的选择:\n");
		scanf("%d",&choice);	          /*读入选项*/
		switch(choice)
		{
		case 1:	 readMed(&s,1);       /*读入一条待插入的药品记录*/
				 n=insertMed(med,n,s);   /*调用函数插入药品进出库记录*/
				 saveFile(med,n);
				 break;
		case 2:   printf("请输入待修改的药品编码\n");
					 scanf("%ld",&s.cod);  /*读入一个待修改的药品编码*/
				      t=searchMed(med,n,s,1,find) ; /*调用函数查找指定药品的记录*/
				      if (t)                 /*如果该学号的记录存在*/
					 {
						  readMed(&s,1);   /*读入一条完整的药品库存信息*/
					      med[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }
					  else                 /*如果该药品编码的记录不存在*/ 
                     printf("该药品不存在，你不能对其进行操作\n"); /*输出提示信息*/
					  break;
		case 3:   printf("请输入待删除的药品编码\n");
					 scanf("%ld",&s.cod);  /*读入一个待删除的药品编码*/
					 n=deleteMed(med,n,s);   /*调用函数删除指定药品编码的药品记录*/
					 break;
		case 0: break;
		}
	}while(choice);
	return n;                             /*返回当前操作结束后的实际记录条数*/
}




void searchManage(Medcine med[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findcod,f[COD];
Medcine s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("请输入你的选择:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("输入待查询药品的编码:\n");
				      scanf("%ld",&s.cod);         /*输入待查询学生的学号*/
					  break;
				case 2:   printf("输入待查询药品的名称:\n");
				      scanf("%s",s.name);	          /*输入待查询药品的名称*/		  
				      break;   
				case 3:   printf("输入待查询药品的入库时间:\n");
				      scanf("%d",&s.intime);          /*输入待查询药品入库时间*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findcod=searchMed(med,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findcod)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findcod;i++)         /*循环控制f数组的下标*/
	      	 printMed(&med[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("该记录不存在!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Medcine med[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
			     	sortMed(med,n,1);         /*按编码由小到大的顺序排序记录*/ 
          	        printMed(med,n);          /*按编码由小到大的顺序输出所有记录*/
		 			break;
			case 2: n=scoreManage(med,n);   /* 2. 药品进出库管理*/ 
			   	     break;
			case 3: sortMed(med,n,3);
					printHead( );                  /*打印表头*/
					printMed(med,n);      /* 3. 其他信息统计*/
					break;
			case 4: searchManage(med,n);     /* 4. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Medcine med[COD];                /*定义实参一维数组存储药品记录*/
      int choice,n;
	 n=readFile(med);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(med);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("请输入你的选择: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(med,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("输入错误,请重新输入你的选择!\n");
	} while (choice);
	sortMed(med,n,1);                   /*存入文件前按药品编码由小到大排序*/ 
	     saveFile(med,n);                   /*将结果存入文件*/
      return 0;
}













/*②medcine.c文件的完整内容*/
#include "medcine.h"
#include <stdio.h>

int readMed(Medcine  *med , int n)          /*读入药品记录值，编码为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("输入药品信息\n");
		printf("药品编码:  ");
	     scanf("%ld", &med[i].cod);
		if (med[i].cod==0) break;
		printf("药品名称: ");
		scanf("%s",&med[i].name);	
		printf("药品类型:  ");
		scanf("%s",&med[i].type);
		printf("规格:\n");
		scanf("%s",&med[i].spec);
		printf("数量: ");
		scanf("%ld",&med[i].num);	
		printf("价格: ");
		scanf("%lf",&med[i].price);	
		printf("入库时间:  ");
		scanf("%ld",&med[i].intime);
		printf("出库时间: ");
		scanf("%ld",&med[i].outtime);	
		printf("保质期:  ");
		scanf("%s",&med[i].term);
		printf("保质期到期时间:  ");
		scanf("%ld",&med[i].outterm);
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printMed ( Medcine  *med , int n)       /*输出所有药品记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%2ld", med[i].cod);
		printf("%10s", med[i].name);
		printf("%8s", med[i].type);
		printf("%14s",med[i].spec);
	    printf("%6ld",med[i].num);
	    printf("%8.2f",med[i].price);
		printf("%10ld",med[i].intime);
	    printf("%4ld",med[i].outtime);
	    printf("%4s",med[i].term);
	    printf("%10ld\n",med[i].outterm);
	}
}

int equal(Medcine s1,Medcine s2,int condition)  /*如何判断两个Medcine记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编码*/
		return s1.cod==s2.cod;
	else if (condition==2)                /*如果参数condition的值为2，则比较名称*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较入库时间*/
	     return s1.intime==s2.intime;
 else if (condition==4)                /*如果参数condition的值为4，则比较数量*/
		return s1.num==s2.num;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Medcine s1,Medcine s2,int condition)  /*根据condition条件比较两个药品记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编码*/
		return s1.cod>s2.cod;
	if (condition==2)                    /*如果参数condition的值为2，则比较数量*/
		return s1.num>s2.num;
	if (condition==3)                    /*如果参数condition的值为2，则比较有效期到期时间*/
		return s1.outterm>s2.outterm;
	else return 1; /*其余情况返回1*/
}

void reverse(Medcine med[],int n)             /*数组元素逆置*/
{
	int i;
	Medcine temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=med[i];
		med[i]=med[n-1-i];
		med[n-1-i]=temp;
	}
}



void sortMed(Medcine med[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Medcine t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(med[minpos],med[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=med[i];
			med[i]=med[minpos];
			med[minpos]=t;
		}
	}
}

int searchMed(Medcine med[],int n,Medcine s,int condition,int f[ ])  /*在med数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(med[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertMed(Medcine med[],int n,Medcine s)              /*向med数组中依编码递增插入一个元素s*/
{
	int i;
	sortMed(med,n,1);                              /*先按编码排序*/
	for (i=0;i<n;i++)
	{
		if (equal(med[i],s,1))                      /*编码相同不允许插入，保证编码的唯一性*/
		{
		    printf("该药品编码存在,不能重复录入!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编码从小到大有序*/
	{
		if (!larger(med[i],s,1))                    /*如果s大于当前元素med[i]，则退出循环*/
		break;
		med[i+1]=med[i];                         /*否则元素med[i]后移一个位置*/
	}
	med[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteMed(Medcine med[],int n,Medcine s)            /*从数组中删除指定编码的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(med[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("该药品编码记录不存在！\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(med[i],s,1)成立*/ 
		med[j]=med[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}






