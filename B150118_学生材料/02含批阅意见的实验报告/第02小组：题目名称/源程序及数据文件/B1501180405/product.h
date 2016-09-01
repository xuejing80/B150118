/* ①product.h文件的完整内容 */
#ifndef _PRODUCT             /*条件编译，防止重复包含的错误*/
#define _PRODUCT 
#include <string.h>
#define NUM 20                /*定义商品人数常量，此处可以根据实际需要修改常量值*/
struct Product                   /*商品记录的数据域*/
{
		long num;
		char name[20];
		char brand[10];
		int price;
		double count;
		int total;
		int rank;
};
typedef struct Product Product;
#define sizePro sizeof(Product)      /*一个商品记录所需要的内存空间大小*/
int readPro(Product pro[],int n);       /*读入商品记录值，编号为0或读满规定条数记录时停止*/
void printPro(Product  *pro , int n);   /*输出所有商品记录的值*/

int equal(Product s1,Product s2,int condition);  /*根据condition条件判断两个Product类型数据相等否*/
int larger(Product s1,Product s2,int condition);  /*根据condition比较Product类型数据大小*/
void reverse(Product pro[],int n);             /*商品记录数组元素逆置*/

void calcuTotal(Product pro[],int n);           /*计算所有商品的总价格*/
void calcuRank(Product pro[],int n);           /*根据价格计算商品名次，允许有并列名次*/
void calcuMark(double m,Product pro[],int n); /*求库存较多较少商品*/
/*表示哪门课，第二维表示最高、最低、平均分*/

void sortPro(Product pro[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchPro(Product pro[],int n,Product s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertPro(Product pro[],int n,Product s);                   /*向数组中插入一个元素按编号有序*/
int deletePro(Product pro[],int n,Product s);                   /*从数组中删除一个指定编号的元素*/
#endif
