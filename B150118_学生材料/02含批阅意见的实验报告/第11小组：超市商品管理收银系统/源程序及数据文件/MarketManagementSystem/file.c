#include<stdio.h>
#include "welcome.h"
#include<stdlib.h>
#include <time.h>
//扫码 返回查询到的条码信息
struct goods readcode(char code[]){
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")){
        while(!feof(fp)){
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code))
            {
                fclose(fp);
                break;
            }
        }
        printf("没有这个条码的商品");
    }
    else{
        printf("文件加载错误，请检查数据库文件");
    }
    return read;
}
//写入条码信息，创建订单
long neworder(){
    int id;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //随机产生订单号
    FILE *fp;
    if(fp = fopen(".\\2.txt","r")){
    while(!feof(fp)){
        fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
        if(!strcmp(code,read.code))
            {
                fclose(fp);
                break;
            }
        }
    }
    else{
        printf("文件加载错误，请检查数据库文件");
    }
}
