/* ①student.h文件的完整内容 */
#ifndef _MEDCINE             /*条件编译，防止重复包含的错误*/
#define _MEDCINE
#include <string.h>
#define COD 20                /*定义药品数量常量，此处可以根据实际需要修改常量值*/
struct Medcine                   /*学生记录的数据域*/
{
		long cod;
		char name[20];
		char type[10];
		char spec[10];
		long num;
                double price;
		long intime;
                long outtime;
                char term[10];
                long outterm;
};
typedef struct Medcine Medcine;
#define sizeMed sizeof(Medcine)      /*一种记录所需要的内存空间大小*/
int readMed(Medcine med[],int n);       /*读入药品记录值，学号为0或读满规定条数记录时停止*/
void printMed(Medcine  *med , int n);   /*输出所有药品记录的值*/

int equal(Medcine s1,Medcine s2,int condition);  /*根据condition条件判断两个Student类型数据相等否*/
int larger(Medcine s1,Medcine s2,int condition);  /*根据condition比较Student类型数据大小*/
void reverse(Medcine med[],int n);             /*学生记录数组元素逆置*/

void calcuNum(Medcine med[],int n);           /*计算所有学生的总分*/
void calcuIntime(Medcine med[],int n);           /*根据总分计算学生的名次，允许有并列名次*/
void calcuMark(double m[3][3],Medcine med[],int n); /*求三门课的最高、最低、平均分，m数组第一维*/
/*表示哪门课，第二维表示最高、最低、平均分*/

void sortMed(Medcine med[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchMed(Medcine med[],int n,Medcine s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertMed(Medcine med[],int n,Medcine s);                   /*向数组中插入一个元素按学号有序*/
int deleteMed(Medcine med[],int n,Medcine s);                   /*从数组中删除一个指定学号的元素*/
#endif
