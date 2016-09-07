#include<stdio.h>
#include "welcome.h"
#include<stdlib.h>
#include <time.h>
//条码是否存在函数
int ifexist(char code[])
{
    int a = 0;
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")) //文件打开
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //读取文件
            if(!strcmp(code,read.code))
            {
                fclose(fp);
                a = 1;
                break;
            }
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
    if(a==0)
        printf("条码不存在，请重新输入\n");
    return a;
}
//总利润计算
double totalprofit()
{
    int id;
    double total=0,profit=0,abc=0;
    FILE *fp;
    if(fp = fopen(".\\2.txt","r"))//文件打开
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %lf %lf\n",&id,&total,&profit);//读取所有订单信息，并计算总和利润
            abc = abc+profit;
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
    return total;
}




//扫码 返回查询到的条码信息
struct goods readcode(char code[])
{
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r"))
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code)) //查找需要的条码
            {
                fclose(fp);
                break;
            }
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
    return read;
}

//显示现有的全部商品
void showgoods()
{
    system("cls");
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")) //文件打开
    {
        printf("   条码           名称       售价      成本     存量   \n");
        while(!feof(fp))
        {

            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);  //读取文件
            printf("%10s   %10s %10.2f %10.2f   %10d\n",read.code,read.name,read.price,read.chengben,read.num);
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
    printf("请按任意键返回上一层菜单");
    getchar();
    getchar();
    system("cls");
    adminabc();

}
//添加新的商品
int addgoods(char code[],char name[],char price[],char chengben[],char num[])
{
    FILE *fp;
    if(fp = fopen(".\\1.txt","a+")) //打开文件
    {
        fprintf(fp,"\n%s %s %s %s %s",code,name,price,chengben,num); //按照一定的格式来写入文件
        fclose(fp);
        return 1;
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
        return 0;
    }
}

//写入条码信息，创建订单
void createorder(double price,double profit)
{
    int id;
    order add;
    add.id = neworder();//调用随机函数产生订单号
    add.total = price;
    add.profit = profit;
    printf("订单创建完成\n");
    FILE *fp;
    if(fp = fopen(".\\2.txt","a+"))
    {
        id = neworder();
        fprintf(fp,"\n%d %.2f %.2f",id,add.total,add.profit);//写入文件并显示本次订单价格
        fclose(fp);
        printf("\n\n本次订单号：%d总价格：%.2f\n\n",id,add.total);
        checkabc(add.id,add.total,add.profit);
        return 1;
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
        return 0;
    }

}
//库存减一
void sale(char code[])
{
    goods read;
    FILE *fp;
    char c,d[20],e[20];
    int i=-2;
    if(fp = fopen(".\\1.txt","r+"))//打开文件
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);//读取数据进入结构体变量
            if(!strcmp(code,read.code))
            {
                while(c != ' ') //文件指针查找到第一个空格处
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);//文件指针定位完成
                sprintf(e,"0%d\n",read.num-1);//加0复写，防止位数变化产生错误
                fputs(e,fp);
                fclose(fp); //关闭文件
                break;
            }
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
}
//库存+1 思路同上
void saleadd(char code[])
{
    goods read;
    FILE *fp;
    char c,d[20],e[20];
    int i=-2;
    if(fp = fopen(".\\1.txt","r+"))
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code))
            {
                while(c != ' ')
                {
                    fseek(fp,-1,1);
                    c = fgetc(fp);
                    fseek(fp,-1,1);
                }
                fseek(fp,1,1);
                sprintf(e,"0%d\n",read.num+1);
                fputs(e,fp);
                fclose(fp);
                break;
            }
        }
    }
    else
    {
        printf("文件加载错误，请检查数据库文件");
    }
}


//随机创建订单号
int neworder()
{
    int id;
    goods read;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //随机产生订单号
    return id;
}
