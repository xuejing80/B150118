#include<stdlib.h>
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
        printf("  1商品信息录入\n  2商品库存情况列表\n  3总体利润报表\n  4返回登录页面\n\n\n");
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
        printf("总体利润是:%.2f",totalprofit());
         printf("按任意键返回上一层");
         getchar();
         getchar();
         system("cls");
        adminabc();
        break;
    case 4:
        login();
        break    ;
    }


}



//登录函数
int login()
{
    printf("欢迎进入超市商品进销存系统\n");
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
            checkabc(0,0.0,0.0);
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
void checkabc(int id,double total,double profit){
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
    system("cls");
    checkcode();
    }
    else
    {
        printf("欢迎查看本日营销报表\n本次订单号：%d总价格：%.2f%利润：%.2f\n",id,total,profit);
         printf("按任意键返回上一层");
         getchar();
         getchar();
         system("cls");
        checkabc(id,total,profit);
    }
    return 0;
}


// 录入函数
void inputgoods()
{
    system("cls");
    char code[20];
    double price,chengben;
    char name[20],num[20];
    int s,num;

    do
    {
        printf("请分别输入货品信息：条码、商品名称、价格、成本、库存*以空格隔开*\n\n");
        scanf("%s%s%lf%lf%d",code,name,&price,&chengben,&num);
        printf("\n   条码:%s\n   名称:%s\n   价格:%10.2f\n   1成本:%10.2f\n",code,name,price,chengben,);
        if(addgoods(code,name,price,chengben,num))
            printf("添加成功");
        else
            printf("添加失败");
        printf("\n是否继续 1是 or 2否\n\n");
        scanf("%d",&s);
        if(s==2)
        {
            system("cls");
            adminabc();
        }
    }
    while (s==1);
}


//收银函数
void checkcode()
{
    char code[20],endcode[20]="end";
    goods good[100];
    int i=0;
    double total=0.0;
    order profit;
    printf("欢迎进入收银系统\n请输入商品条形码(输入end结束)：\n");
    do
    {
        scanf("%s",code);
        if(!strcmp(code,endcode))
            break;
        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {
                total = total+good[i-1].price;
                profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                profit.total = total;
               sale(good[i-1].code); //库存减一
                printf("商品名称：%10s 价格：%10.2f元 存量:%d \n总价:%10.2f元\n",good[i-1].name,good[i-1].price,good[i-1].num-1,total);
            }
            else
            {
                printf("本商品已售罄，请重新输入");
                continue;
            }
        }
        else
        {
            continue;

        }
    }
    while(1);
    createorder(profit.total,profit.profit);

}


//检查一维码是否合格函数
int checknum(const char*num)
{
    int i;
     for(i=0;i<20;i++)
            {
                if(num[i]=='\0') break;
                if(!(num[i]>='0'&&num[i]<='9'||num[i]=='\0'))
                   {//printf("%s",num);
                    return 1;
                    break;
                   }
            }

     return 0;

}
