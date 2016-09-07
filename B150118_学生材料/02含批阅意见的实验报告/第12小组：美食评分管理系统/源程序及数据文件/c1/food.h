/* ①food.h文件的完整内容 */
#ifndef _FOOD             /*条件编译，防止重复包含的错误*/
#define _FOOD
#include <string.h>
#define NUM 20                /*定义菜品数量常量，此处可以根据实际需要修改常量值*/
struct Food                   /*菜品记录的数据域*/
{
		long num;
		char name[20];
		char style[10];
		char taste[10];
		double score[3];
		double total;
		int rank;
};
typedef struct Food Food;
#define sizeFoo sizeof(Food)      /*一个菜品记录所需要的内存空间大小*/
int readFoo(Food foo[],int n);       /*读入菜品记录值，序号为0或读满规定条数记录时停止*/
void printFoo(Food  *foo , int n);   /*输出所有菜品记录的值*/

int equal(Food s1,Food s2,int condition);  /*根据condition条件判断两个Food类型数据相等否*/
int larger(Food s1,Food s2,int condition);  /*根据condition比较Food类型数据大小*/
void reverse(Food foo[],int n);             /*菜品记录数组元素逆置*/
void calcuTotal(Food foo[],int n);           /*计算所有菜品的总分*/
void calcuRank(Food foo[],int n);           /*根据总分计算菜品的名次，允许有并列名次*/
void calcuMark(double m[3][3],Food foo[],int n); /*求评分项目的最高、最低、平均分，m数组第一维*/
/*表示哪个评分项目，第二维表示最高、最低、平均分*/
void sortFoo(Food foo[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/
int searchFoo(Food foo[],int n,Food s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertFoo(Food foo[],int n,Food s);                   /*向数组中插入一个元素按序号有序*/
int deleteFoo(Food foo[],int n,Food s);                   /*从数组中删除一个指定序号的元素*/
#endif