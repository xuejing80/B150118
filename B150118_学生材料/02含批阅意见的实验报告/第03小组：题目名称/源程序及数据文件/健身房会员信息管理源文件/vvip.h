/* ①vvip.h文件的完整内容 */
#ifndef _VVIP            /*条件编译，防止重复包含的错误*/
#define _VVIP
#include <string.h>
#define NUM 20                /*定义会员人数常量，此处可以根据实际需要修改常量值*/
struct Vvip                   /*会员记录的数据域*/
{
		long num;
		char name[20];
		char sex[10];
		int time[4];
                char date[20];
		int total;
		int rank;
};
typedef struct Vvip Vvip;
#define sizeVip sizeof(Vvip)      /*一个会员记录所需要的内存空间大小*/
int readVip(Vvip vip[],int n);       /*读入会员记录值，会员号为0或读满规定条数记录时停止*/
void printVip(Vvip  *vip , int n);   /*输出所有会员记录的值*/

int equal(Vvip v1,Vvip v2,int condition);  /*根据condition条件判断两个Vvip类型数据相等否*/
int larger(Vvip v1,Vvip v2,int condition);  /*根据condition比较Vvip类型数据大小*/
void reverse(Vvip vip[],int n);             /*会员记录数组元素逆置*/

void calcuTotal(Vvip vip[],int n);           /*计算所有会员的总分*/
void calcuRank(Vvip vip[],int n);           /*根据总次数计算会员的名次，允许有并列名次*/
void calcuMark(double m[4][4],Vvip vip[],int n); /*求四个季度的最高、最低、平均次数，m数组第一维*/
/*表示哪门课，第二维表示最高、最低、平均分*/

void sortVip(Vvip vip[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchVip(Vvip vip[],int n,Vvip s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertVip(Vvip vip[],int n,Vvip v);                   /*向数组中插入一个元素按会员号有序*/
int deleteVip(Vvip vip[],int n,Vvip v);                   /*从数组中删除一个指定会员号的元素*/
#endif
