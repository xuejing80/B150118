#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   
#define N 100


struct student
{
	char num[10];
	char name[10];
	char tel[11];
    char sex[2];
	int add;                                                       /*地址*/
	char deptnum[3];                                              /*部门编号*/
    char deptname[25];                                            /*部门名称*/
	float basepay;                                                /*基本工资*/
	signed int bonus;                                           /*奖金*/
	float meritpay;                                       /*绩效工资*/
	float sumbasepay;                                          /*总基本工资*/
	float totalpay;                                          /*实得学分*/
}stu[12];

void print();                                                    /*创建主菜单*/
void create();                                                   /*创建管理系统*/
void display();                                                  /*显示*/
void searchbase();                                               /*基本情况查询*/
/* schbase_num  sch_dom与schbase_name函数被searchbase调用 */
void sch_num(FILE *fp); 
void sch_name(FILE *fp); 
void sch_dom(FILE *fp);
void search();                                                    /*查询*/
void searchpay();                                           /*工资查询*/
void schpayum(FILE *fp,FILE *f);                                /*工资查询*/
void delete1();                                                    /*删除*/
/* del_num函数被delete1调用 */
void del_num(FILE *fp,FILE *f);
void sort();                                                      /*排序*/
/* sort_sumscore与sort_count函数被sort调用 */
void sort_sumscore();
void sort_count();

void main()
{  
	char choose,yes_no;
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