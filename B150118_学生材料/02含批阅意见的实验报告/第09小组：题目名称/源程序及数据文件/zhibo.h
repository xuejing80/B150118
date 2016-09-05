#ifndef _zhubo
#define _zhubo
#include <string.h>
#include <stdlib.h>
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
 void calcuRank(zhubo zhu[],int n) ;
 int  calcuTotal(zhubo zhu[],int n);
 int calcumost(int m[NUM], zhubo zhu[] ,int n) ; /*求直播人数最多*/
 void sortzhu(zhubo  zhu[],int n,int condition);
 int calcupj(int m[NUM], zhubo zhu[] ,int n);  /*求直播平均时间*/
 int searchzhu(zhubo  zhu[],int n,zhubo  z,int condition,int f[]) ;
 int insertzhu(zhubo  zhu[],int n,zhubo  z);
 int deletezhu(zhubo  zhu[],int n,zhubo  z);
 int equal(zhubo z1,zhubo z2,int condition);
 int larger(zhubo z1,zhubo z2,int condition);
 void reverse(zhubo zhu[],int n) ;
int calcumax(int m[NUM], zhubo zhu[] ,int n) ; /*求直播时间最长*/
#endif // _zhubo
