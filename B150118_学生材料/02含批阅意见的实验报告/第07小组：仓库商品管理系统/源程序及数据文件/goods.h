#ifndef _GOODS
#define _GOODS
#include<string.h>
#define NUM 2
struct Goods
{
	long num;
	char name[20];
    char  brand[10];
	int  changes[2];
	int  stock;
	int  rank;
};
typedef struct Goods Goods;
#define sizeGood sizeof(Goods)
int readGood(Goods good[],int n) ;
void printGood ( Goods  *good , int n) ;
int equal(Goods g1,Goods g2,int condition) ;
int larger(Goods g1,Goods g2,int condition) ; 
void reverse(Goods good[],int n) ;
void calcuStock(Goods good[],int n) ; 
void calcuRank(Goods good[],int n) ;
void calcuMark(double m[2][2],Goods good[],int n);
void sortGood(Goods good[],int n,int condition) ;
int searchGood(Goods good[],int n,Goods g,int condition,int f[ ]) ;
int insertGood(Goods good[],int n,Goods g) ;
int deleteGood(Goods good[],int n,Goods g);
#endif
