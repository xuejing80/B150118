/* ①book.h文件的完整内容 */
#ifndef _BOOK             /*条件编译，防止重复包含的错误*/
#define _BOOK
#include <string.h>
#define NUM 20                /*定义图书数量常量，此处可以根据实际需要修改常量值*/
struct Book                   /*图书记录的数据域*/
{
		long num;
		char name[20];
		char writer[20];
		char category[20];
		long location;
        char information[20];
        char botime[40];
        char retime[40];
	
};
typedef struct Book Book;

#define sizeBoo sizeof(Book)      /*一本图书记录所需要的内存空间大小*/
int readBoo(Book *boo,int n);       /*读入图书记录值，编号为0或读满规定条数记录时停止*/
void readOneBook(Book *boo);          /*读入一条图书记录值，初始化boo*/
void printBoo(Book  *boo , int n);   /*输出所有图书记录的值*/

int equal(Book s1,Book s2,int condition);  /*根据condition条件判断两个Book类型数据相等否*/
int larger(Book s1,Book s2,int condition);  /*根据condition比较Book类型数据大小*/
void reverse(Book boo[],int n);             /*图书记录数组元素逆置*/


void sortBoo(Book boo[],int n);   /*冒泡排序法从小到大排序*/

int searchBoo(Book boo[],int n,Book s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
int insertBoo(Book boo[],int n,Book s);   /*向数组中插入一个元素按编号有序排列*/
int deleteBoo(Book boo[],int n,Book s);   /*从数组中删除一个指定编号的元素*/

#endif
