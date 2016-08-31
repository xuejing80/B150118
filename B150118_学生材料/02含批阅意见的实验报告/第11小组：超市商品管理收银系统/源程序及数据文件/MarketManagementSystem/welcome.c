#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
// 管理员函数
void adminabc()
{
    int a;
    char b;
    do
    {
        printf("欢迎进入管理员页面\n\n");
        printf("  1商品信息录入\n  2商品库存情况列表\n  3总体利润报表\n  4最高盈利商品和最低盈利商品\n\n\n");
        printf("请输入命令：");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("输入有误，请重新输入!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a)
    {
    case 1:
        inputgoods();
        break;
    case 2:
       showgoods();
        break;
    case 3:
        printf("xxxx");
        break;
    case 4:
        printf("rrrr");
        break    ;
    }


}



//登录函数
int login()
{
    printf("欢迎进入超市商品净销存系统\n");
    printf("请登录！\n");
    printf("请输入用户名：");
    char user_name[200];
    char user_password[200];
    int c=0,i=0;
    scanf("%s",&user_name);
    printf("请输入密码：");
    while ((c=getch()) != '\r') //使密码输入的时候显示*号
    {
        user_password[i++] = c;
        putchar('*');
    }
    user_password[i] = '\0';
    char admin[] = "root";
    char adminpassword[] = "123456";
    char check[] = "check";
    char checkpassword[] = "123456";
    if(!strcmp(user_name,admin)&& !strcmp(user_password,adminpassword))
    {
        system("cls");
        printf("\n管理员你好\n");
        adminabc();
    }
    else
    {
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            system("cls");
            printf("\n收银员你好\n");
            checkabc();
        }
        else
        {

            printf("\n用户名或密码错误,请按回车重新登录\n");
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
//收银员函数
void checkabc(){
 int command;
    printf("欢迎进入收银员系统\n");
    printf("1、收银\n2、本日收银报表\n");
    do                  //检测是否输入正确的指令如果不是则重新输入
    {
        printf("请输入命令：");
        scanf("%d",&command);
         printf("\n");
        if(command!=1&&command!=2)
            printf("输入错误\n再次");

    }
    while(command!=1&&command!=2);
    if(command==1)           //1、进入收银员界面  2、进入本日收银报表
    {
        printf("欢迎进入收银员界面");
        checkcode();
    }
    else
    {
        printf("欢迎查看本日营销报表");
    }
    return 0;
}


// 录入函数
void inputgoods()
{   char code[20];
    double price,chengben;char name[20];
    int s,num;

    do{
    printf("请分别输入货品信息：条码、商品名称、价格、成本、库存*以空格隔开*\n\n");
    scanf("%s%s%lf%lf%d",code,name,&price,&chengben,&num);
    printf("\n   条码:%s\n   名称:%s\n   价格:%lf\n   成本:%f\n  库存:%d\n",code,name,price,chengben,num);
    if(addgoods(code,name,price,chengben,num))
        printf("添加成功");
    else
        printf("添加失败");
    printf("\n是否继续 1是 or 2否\n\n");
    scanf("%d",&s);
    if(s==2)
        adminabc();
    }
    while (s==1);




}


//收银函数
int checkcode()
{
    char code[20],endcode[20]="end";
    goods good[100];
    int i=0;
    double total=0.0;
    printf("欢迎进入收银系统\n请输入商品条形码(输入end结束)：\n");
    do
    {
        scanf("%s",code);
        if(!strcmp(code,endcode))
                break;
        if(ifexist(code)){
           good[i++] = readcode(code);
           total = total+good[i-1].price;
           printf("商品名称：%10s 价格：%10.2f元\n总价:%10.2f元\n",good[i-1].name,good[i-1].price,total);
        }else{
            continue;

        }
    }while(1);






}



