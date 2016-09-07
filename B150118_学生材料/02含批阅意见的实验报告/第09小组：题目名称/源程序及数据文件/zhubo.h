#ifndef _ZHUBO            /*条件编译，防止重复包含的错误*/
#define _ZHUBO
#include <string.h>
#define NUM 20                /*定义主播人数常量，此处可以根据实际需要修改常量值*/
struct zhubo                   /*主播记录的数据域*/
{

		char name[20];
		char sex[10];
		 long num[10];
		char game[10];
		int time[7];
		int total;
		int rank;
};
typedef struct zhubo zhubo;
#define sizezhu sizeof(zhubo)      /*一个主播记录所需要的内存空间大小*/
int readzhu(zhubo zhu[],int n);       /*读入主播记录值，读满规定条数记录时停止*/
void printzhu(zhubo  *zhu , int n);   /*输出所有主播记录的值*/

int equal(zhubo z1,zhubo z2,int condition);  /*根据condition条件判断两个主播类型数据相等否*/
int larger(zhubo z1,zhubo z2,int condition);  /*根据condition比较Student类型数据大小*/
void reverse(zhubo zhu[],int n);             /*主播记录数组元素逆置*/

void calcuTotal(zhubo zhu[],int n);           /*计算所有主播的总直播时间*/
void calcuRank(zhubo zhu[],int n);           /*根据总时间计算主播的名次，允许有并列名次*/
void calcuMark(double m[7][3],zhubo zhu[],int n);


void sortzhu(zhubo zhu[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchzhu(zhubo zhu[],int n,zhubo z,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertzhu(zhubo zhu[],int n,zhubo z);                   /*向数组中插入一个元素按房间号有序*/
int deleteStu(zhubo zhu[],int n,zhubo z);                   /*从数组中删除一个指定房间号的元素*/
#endif

