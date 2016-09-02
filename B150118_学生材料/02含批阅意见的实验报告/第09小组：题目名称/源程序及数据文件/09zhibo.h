#ifndef _zhubo
#define _zhubo
#include <string.h>
#define NUM 20
 struct zhubo
 {

     char name[20];
     char sex[10];
     long num ;
     char time[20];
     int  people;
     int  Time;
     char game[10];
     int rank;
 };
 typedef struct zhubo zhubo;
 #define sizezhu sizeof(zhubo)
 int readzhu(zhubo *zhu , int n);

 void printzhu(zhubo *zhu , int n);

 int  calcuTotal(zhubo zhu[],int n);

 void sortzhu(zhubo  zhu[],int n,int condition);

 int searchzhu(zhubo  zhu[],int n,zhubo  z,int condition,int f[]) ;
 int insertzhu(zhubo  zhu[],int n,zhubo  z);
 int deletezhu(zhubo  zhu[],int n,zhubo  z);

#endif // _zhubo
