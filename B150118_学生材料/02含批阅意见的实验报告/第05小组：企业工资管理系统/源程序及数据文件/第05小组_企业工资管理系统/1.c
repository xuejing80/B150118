#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <math.h>
#define N 100


struct employee
{
	char num[10];
	char name[10];
	char tel[11];
    char sex[2];
	int addr;                                                     /*地址*/
	char deptnum[4];                                              /*部门编号*/
    char deptname[25];                                            /*部门名称*/
	int basepay;                                                /*基本工资*/
	int bonus;                                                  /*奖金*/
	int meritpay;                                               /*绩效工资*/
	int sumpay;                                                 /*综合工资*/
	int totalpay;                                               /*实得工资*/
}em[20];

void print();                                                    /*创建主菜单*/
void create();                                                   /*创建管理系统*/
void display();                                                  /*显示*/
void searchbase();                                               /*基本情况查询*/
/* schbase_num  sch_dept与schbase_name函数被searchbase调用 */
void sch_num(FILE *fp); 
void sch_name(FILE *fp); 
void sch_dept(FILE *fp);
void search();                                                    /*查询*/
void searchpay();                                           /*工资查询*/
void schpay_num(FILE *fp,FILE *f);                                /*工资查询*/
void delete1();                                                    /*删除*/
/* del_num函数被delete1调用 */
void del_num(FILE *fp,FILE *f);
void sort();                                                      /*排序*/
/* sort_sumpay与sort_totalpay函数被sort调用 */
void sort_sumpay();
void sort_totalpay();
void main()
{   
    int mi;
    char choose,yes_no;
    printf("欢迎进入企业工资管理系统！\n\n");
    printf("请输入密码:\n");
	scanf("%d",&mi);
	if(mi==12345678)
	do
	{
		print();                                                    /*显示主菜单*/
		printf("         ");
		choose=getch(); 
		switch(choose)
		{
		case '1':	create();		break;		                    /*创建*/
		case '2':	display();   	break;		                    /*显示*/
		case '3':	search();		break;	                      	/*查询 */
		case '4':	delete1();		break;		                    /*删除*/
		case '5':	sort();		    break;		                    /*排序*/
		case '0':	break;		
		default:printf("\n        此为非法选项   \n");
		}
		if(choose=='0')
			break;
		printf("        要继续选择吗(Y/N)?   ");
		do 
		{
			yes_no=getch();
		}while(yes_no!='Y'&&yes_no!='y'&&yes_no!='N'&&yes_no!='n');
	}while(yes_no=='Y'||yes_no=='y');
    else
	{
		printf("密码输入错误，系统将自动退出\n");
	}
}

void print()                                                      /*显示菜单界面*/
{  
	printf("\n\n");
	printf("                         企业工资管理系统  ");
	printf("\n");
	printf("       ╭════════════■□■□════╮\n");
	printf("	|	     请输入选项编号(0-5):         |\n"); 
	printf("	|-----------------------------------------|\n");
	printf("	|	1--创建员工信息     	          |\n"); 
	printf("	|	2--显示员工信息     	          |\n");
	printf("	|	3--查询员工信息                   |\n");
	printf("	|	4--删除员工信息                   |\n");
	printf("	|	5--排序员工信息    	          |\n");
	printf("	|	0--退出				  |\n");  
	printf("	|-----------------------------------------|\n");
	printf("        ╰════■□■□════════════╯\n");
    printf("\n");
    printf("     欢迎进入企业工资管理系统——请选择要进行的操作!\n ");

}
void create()
{
	int i,n;
	FILE *fp; 
	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","rw+");
	if(fp==NULL)
	{
		printf("\n		打开文件失败!\n");
		return;
	} 
	rewind(fp);
	printf("\n");
	printf("\t\t请输入员工个数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n请输入员工工号、部门编号、部门名称、基本工资、奖金、绩效工资、综合工资\n");
		scanf("%s %s %s %d %d %d %d" ,&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay);
	}
	for(i=0;i<n;i++)
    { 
	
		if( em[i].bonus==-1)
			em[i].sumpay=em[i].basepay+em[i].meritpay;
		else
			em[i].sumpay= em[i].basepay+ em[i].meritpay+ em[i].bonus;
		if(0<em[i].sumpay&&em[i].sumpay<=1500)
			em[i].totalpay=em[i].sumpay*97/100;
		if(1500<em[i].sumpay&&em[i].sumpay<=4500)
			em[i].totalpay=em[i].sumpay*90/100;
		if(4500<em[i].sumpay&&em[i].sumpay <=9000)
			em[i].totalpay=em[i].sumpay*80/100;
		if(9000<em[i].sumpay&&em[i].sumpay<=35000)
		    em[i].totalpay=em[i].sumpay*75/100;
		if(em[i].sumpay>35000)
			em[i].totalpay=em[i].sumpay*70/100;
		
fprintf(fp,"%-4s%-7s%-5s%-5.0f%-8d%-5d%-8d%-8d%-8d\n",em[i].num ,em[i].deptnum,em[i].deptname,em[i].basepay,em[i].bonus,em[i].meritpay,em[i].sumpay,em[i].totalpay);

	}	
	
        fclose(fp);
		printf("创建成功!!\n");

}
void display()
{    
	int i=0;
	int n=0;
	struct employee;
	FILE *fp;  

	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","r");
	if(fp==NULL)
	{
		printf("		打开文件失败!\n");
		return;
	}   
	
	printf("\n员工工号  部门编号  部门名称   基本工资   奖金   绩效工资   综合工资   实得工资\n"); 
	while(feof(fp)==0)
	{	
		fscanf(fp,"%s%s%s%d%d%d%d%d\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);
		printf("%-5s     %-10s%-7s    %-7d    %-8d %-8d  %-8d  %-8d\n",em[i].num ,em[i].deptnum,em[i].deptname,em[i].basepay,em[i].bonus,em[i].meritpay,em[i].sumpay,em[i].totalpay);
		n++;
	}
	if(n==0)
		printf("		文件中无记录!\n"); 
	else 
		printf("		文件中共有%d个记录!\n",n);  
	fclose(fp);



}
void search()
{
	char c;
	FILE *fp;
	
	fp=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r");
	if(fp==NULL)
	{
		printf("		打开文件失败!\n");
		return;
	}             
	
	printf("	查询基本信息(b),还是查询员工工资(r)?     ");
	c=getch();
	if(c=='b'||c=='B')
		searchbase();		                                        /*查询基本信息*/
	if(c=='r'||c=='R')
		searchpay();		                                    /*查询工资*/
    if(c!='b'&&c!='B'&&c!='r'&&c!='R')
		printf("\n		此为非法字符!\n");	 
		fclose(fp);
}	
void searchbase()
{
	char c;
	FILE *fp;
	
	fp=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r");
	if(fp==NULL)
	{
		printf("		打开文件失败!\n");
		return;
	}             
	
	printf("\n		按工号查询(h),按姓名查询(m)，还是按部门查询(d)?   ");
	c=getch();
	if(c=='h'||c=='H')
		sch_num(fp);		                                        /*按工号查询*/
	else if(c=='m'||c=='M')
		sch_name(fp);		                                        /*按姓名查询*/
    else 
	{
		if(c=='d'||c=='D')
		sch_dept(fp);		                                        /*按部门查询*/
	else 
		printf("		此为非法字符!\n");	 
	}
	fclose(fp);
}
void sch_num(FILE *fp)
{
	int flag=0,n=0;
	char tempnum[6];
	struct employee temp; 
	FILE *fp1;
	
	fp1=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r");
	
	printf("		请输入要查询的工号:");
	gets(tempnum);  
	while(feof(fp)==0)
	{
		fscanf(fp,"%10s%25s%5s%8s%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempnum,temp.num)==0)
		{
			if(flag==0)  
				printf("       工号            姓名        性别    部门编号       电话号码\n"); 
			printf("%10s%17s%11s%12s%16s\n",temp.num,temp.name,temp.sex,temp.deptnum,temp.tel);
			flag=1;
			n++;
		} 
	
	}
	if(n==0)
		printf("		文件中无记录!\n"); 
	else 
	{if(flag==0)
			printf("		文件中无此人!\n"); 
	}
	fclose(fp1);
}	  

void sch_name(FILE *fp)
{
	int flag=0,n=0;
	char tempname[10];
	struct employee temp; 
	FILE *fp1;
	
	fp1=fopen("c:\\第06小组_企业工资管理系统\\empoloyee.txt","r");
	
	printf("		请输入要查询记录的姓名:");
	gets(tempname);  
	while(feof(fp)==0)
	{
		fscanf(fp,"%10s%25s%5s%8s%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempname,temp.name)==0)
		{
			if(flag==0)  
				printf("        工号            姓名        性别    部门编号        电话号码\n"); 
			printf("%10s%17s%11s%12s%16s\n",temp.num,temp.name,temp.sex,temp.deptnum,temp.tel);
			flag=1;
		} 
		n++;
	}
	if(n==0)
		printf("		文件中无记录!\n"); 
	else 
	{if(flag==0)
			printf("		文件中无此人!\n");  
	}
	fclose(fp1);
}

void sch_dept(FILE *fp)
{
	int flag=0,n=0;
	int i;
	char tempdept[4];
	FILE *fp1;
	
	fp1=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r");
	 
	printf("		请输入要查询记录的部门编号:");
	scanf("%s",&tempdept);
	printf("\n");
   for(i=0;i<4;i++)
	{ while(feof(fp)==0)
	   { fscanf(fp,"%14s%15s%16s%12s%13s\n",em[i].num,em[i].name,em[i].sex,&em[i].deptnum,em[i].tel); 
		   
			 if(tempdept==em[i].deptnum)
		   {
			if(flag==0)  
			    		printf("        工号            姓名        性别     部门编号     电话号码\n"); 
			printf("%10s%17s%11s%12s%16s\n",em[i].num,em[i].name,em[i].sex,em[i].deptnum,em[i].tel);
			flag=1;
			n++;
		   } 
	    
		}		   	
	 }
		
	
	if(n==0)
		printf("		文件中无记录!\n"); 
    else 
		printf("		此部门有%d人!\n",n);  
	fclose(fp1);
	
}
	 
void searchpay()
{
   
	FILE *fp,*f;
	f=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r");
	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","r");
	if(fp==NULL)
	{
		printf("		打开文件失败!\n");
		return;
	}             
	schpay_num(fp,f);
	 	fclose(f);
	fclose(fp);
}

void schpay_num(FILE *fp,FILE *f)
{
	int n=0;
    float flag=0;

    char tempnum[6];
	struct employee temp; 
	
	printf("\n		请输入要查询的工号:");
	gets(tempnum); 
 	
	while(feof(f)==0){
		fscanf(f,"%4s%5s%6s%8s%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
		if(strcmp(tempnum,temp.num)==0)
		{
		printf("	    工号	 	      姓名      \n");
			printf("     %10s  %25s\n",temp.num,temp.name);
		}    
		
	}
 
	printf("部门编号   部门名称  	        奖金           综合工资    \n");
 
	while(feof(fp)==0)
	{
		fscanf(fp,"%4s%5s%6s%6d%6d%7d%8d%8d\n",&temp.num,&temp.deptnum,&temp.deptname,&temp.basepay,&temp.bonus,&temp.meritpay,&temp.sumpay,&temp.totalpay); 
	
		
		if(strcmp(tempnum,temp.num)==0)
		{
				
			
			printf("%s%15s%18d%18d\n",temp.deptnum,temp.deptname,temp.bonus,temp.sumpay);
			flag=temp.totalpay;
			n++;
		} 
	
	}
   if(n==0)
		printf("		文件中无记录!\n"); 
	else 
	{if(flag==0)
			printf("		文件中无此人!\n");
		else
		{printf("\n实得工资为:");
         printf("%6f",flag);
         printf("\n");
		}
	}
}	  
 

void delete1()
{    
   FILE *fp,*f;
   f=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","r");
   fp=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","r+");
   if(fp==NULL||f==NULL)
   {
	 printf("	打开文件失败!\n");
	 return;
   }   

  del_num(fp,f);

}	

void del_num(FILE *fp,FILE *f)
{ int t;
  FILE *fp1;
  char tempnum[6];
  struct employee temp;
  printf("		请输入要删除记录的工号:");
  gets(tempnum);    
  fp1=fopen("c:\\第06小组_企业工资管理系统\\employee1.txt","w+");
  //保存employee.TXT删除后的数据
  while(feof(fp)==0)
  {
     fscanf(fp,"%s%25s%5s%8s%15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel); 
     if(strcmp(tempnum,temp.num)==0) continue;
     fprintf(fp1,"%5s %20s  %5s %8s %15s\n",&temp.num,&temp.name,&temp.sex,&temp.deptnum,&temp.tel);
  }
 
  //重新删除后的数据写回employee.TXT
  remove("c:\\第06小组_企业工资管理系统\\employee.txt.txt");
  fp=fopen("c:\\第06小组_企业工资管理系统\\employee.txt","w+");	
  rewind(fp1);
  t=getc(fp1);
  while(!feof(fp1))
  {
     putc(t,fp);
     t=getc(fp1);
  }

  fclose(fp);
  
  //保存pay.dat删除后的数据
  fp1=fopen("c:\\第06小组_企业工资管理系统\\employee1.txt","w+");
  while(feof(f)==0)
  {
     fscanf(f,"%s%s%s%d%d%d%d%d\n",&temp.num,&temp.deptnum,&temp.deptname,&temp.basepay,&temp.bonus,&temp.meritpay,&temp.sumpay,&temp.totalpay); 
     if(strcmp(tempnum,temp.num)==0) continue;
     fprintf(fp1,"%-10s%-7s%-15s%-8d%-5d%-8d%-8d%-8d\n",temp.num ,temp.deptnum,temp.deptname,temp.basepay,temp.bonus,temp.meritpay,temp.sumpay,temp.totalpay);
  }
//重新删除后的数据写回pay.dat
   f=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","w+");	
   rewind(fp1);
   t=getc(fp1);
   while(!feof(fp1))
	{
		putc(t,f);
        t=getc(fp1);
	}



	fclose(f);
    fclose(fp1);
    remove("c:\\第06小组_企业工资管理系统\\employee1.txt");
	printf("               已删除员工信息\n");
}	


void sort()
{
	char c;
	FILE *fp;
	
	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","a+");
	if(fp==NULL)
	{
		printf("		打开文件失败!\n");
		return;
	}   
	fclose(fp);
	
	printf("      按实得工资排序(c),还是按综合工资排序(s)?    ");
	c=getch();
	if(c=='s'||c=='S')
		sort_sumpay();		                                       /*按综合工资排序*/
	else if(c=='c'||c=='C')
		sort_totalpay();		                                           /*按实得工资排序*/
	else
		printf("\n		此为非法字符!\n");	 	
}	 

void sort_sumpay()
{   char c;
    int i=0;
	int n=0;
    int j,k;
	FILE *fp;
	float a[12];
	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","r");
	if(fp==NULL)
	{
		printf("\n		打开文件失败!\n");
		return;
	}  

	while(feof(fp)==0)
	{ fscanf(fp,"%s%s%s%d%d%d%d%d\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);

	a[i]=em[i].sumpay;
	  i++;
	}
	i--;
//选择排序
  for( k=0;k<i;k++)
	  for( j=k+1;j<=i;j++)
	  if(a[k]>a[j])
	  {float d=a[j];
	   a[j]=a[k];
	   a[k]=d;
	  }
	printf("\n		按升序(u)，还是按降序(d)?\n\n");
	c=getch();    
if(c=='u'||c=='U')                                                 
    for(j=0;j<=i;j++)                                  /*按综合工资工资的升序排列*/
	{       
		for(k=0;k<=i;k++) 
		   if(fabs(a[j]-em[k].sumpay)<10e-6)
           {
			   printf("%-10s%-7s%-15s%-8d%-5d%-8d%-8d%-8d\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               break;
		   }
	}
	else if(c=='d'||c=='d')
       for( j=i;j>=0;j--)
	   {    
		   for(k=0;k<=i;k++)
		   if(fabs(a[j]-em[k].sumpay)<10e-6)
		   {
            	printf("%-10s%-7s%-15s%-8d%-5d%-8d%-8d%-8d\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               break;
		   }
		
		}	
	   else
	      printf("\n 错误字符!\n");
	   	
	fclose(fp);
}


void sort_totalpay()
{
	char c;
    int i=0;
	int n=0;
    int j,k;
	FILE *fp;
	float a[20];
	fp=fopen("c:\\第06小组_企业工资管理系统\\pay.dat","r");
	if(fp==NULL)
	{
		printf("\n		打开文件失败!\n");
		return;
	}  

	while(feof(fp)==0)
	{ fscanf(fp,"%s%s%s%d%d%d%d%d\n",&em[i].num ,&em[i].deptnum,&em[i].deptname,&em[i].basepay,&em[i].bonus,&em[i].meritpay,&em[i].sumpay,&em[i].totalpay);

	a[i]=em[i].totalpay;
	  i++;
	}
	i--; 
//选择排序
  for( k=0;k<i;k++)
	  for( j=k+1;j<=i;j++)
	  if(a[k]>a[j])
	  {float d=a[j];
	   a[j]=a[k];
	   a[k]=d;
	  }
	printf("\n		按升序(u)，还是按降序(d)?\n\n");
	c=getch();    
if(c=='u'||c=='U')                                                      /* 按综合工资的升序排列 */
{  
 for(j=0;j<=i;j++)
	{       
		for(k=0;k<=i;k++)
		   if(fabs(a[j]-em[k].totalpay)<10e-6)
           {    
			   printf("%-10s%-7s%-15s%-8d%-5d%-8d%-8d%-8d\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
               em[k].totalpay=0;
			   break;
		   }
	}

}
	else if(c=='d'||c=='d')
	{
       for( j=i;j>=0;j--)
	   {    
		   for(k=0;k<=i;k++)
		   if(fabs(a[j]-em[k].totalpay)<10e-6)
		   {
            	printf("%-10s%-7s%-15s%-8d%-5d%-8d%-8d%-8d\n",em[k].num ,em[k].deptnum,em[k].deptname,em[k].basepay,em[k].bonus,em[k].meritpay,em[k].sumpay,em[k].totalpay);
                  em[k].totalpay=0;
				break;
		   }
		
		}

	   }
	   else{
	      printf("\n 错误字符!\n");
	   }
	
	
	fclose(fp);
}
