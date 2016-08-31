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
        break;
    case 2:
        printf("dddd");
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
// 录入函数
void inputgoods()
{printf("请分别输入货品信息：code、*以空格隔开*");




}


//收银员函数



