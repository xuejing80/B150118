/* ①EMPLOYEE.h文件的完整内容 */
#ifndef _EMPLOYEE            /*条件编译，防止重复包含的错误*/
#define _EMPLOYEE
#include <string.h>
#define NUM 5                /*定义员工人数常量，此处可以根据实际需要修改常量值*/
struct Employee                   /*员工记录的数据域*/
{
		long num;
		char name[20];
		char sex[10];
		int score[3];
		int total;
		int rank;
};
typedef struct Employee Employee;
#define sizeEmp sizeof(Employee)      /*一个员工记录所需要的内存空间大小*/
int readEmp(Employee emp[],int n);       /*读入员工记录值，工号为0或读满规定条数记录时停止*/
void printEmp(Employee *emp , int n);   /*输出所有员工记录的值*/

int equal(Employee e1,Employee e2,int condition);  /*根据condition条件判断两个employee类型数据相等否*/
int larger(Employee e1,Employee e2,int condition);  /*根据condition比较employee类型数据大小*/
void reverse(Employee emp[],int n);             /*员工记录数组元素逆置*/

void calcuTotal(Employee emp[],int n);           /*计算所有员工的总工资*/
void calcuRank(Employee emp[],int n);           /*根据总工资计算员工的名次，允许有并列名次*/
void calcuMark(double m[3][3],Employee emp[],int n); /*求所有员工的总税费、总基本工资、总奖金，m数组第一维*/
/*表示哪一项工资内容，第二维表示总税费、总基本工资、总奖金*/

void sortEmp(Employee emp[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchEmp(Employee emp[],int n,Employee e,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertEmp(Employee emp[],int n,Employee e);                   /*向数组中插入一个元素按员工有序*/
int deleteEmp(Employee emp[],int n,Employee e);                   /*从数组中删除一个指定员工的元素*/
#endif
