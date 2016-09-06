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
        printf("       ******************************\n");
        printf("            欢迎进入管理员页面\n");
        printf("       ******************************\n");
        printf("  \t**    1商品信息录入       **\n  \t**    2商品库存情况列表   **\n  \t**    3总体利润报表       **\n  \t**    4返回登录页面       **\n");
        printf("        ****************************\n\n\n");
        printf("\t**请输入命令：");
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
        system("cls");
        login();
        break    ;
    }


}



//登录函数
int login()
{
    printf("\t\t\t***************************\n");
    printf("\t\t\t欢迎登录超市商品进销存系统\n");
    printf("\t\t\t***************************\n");
    printf("\t\t\t请输入用户名：");
    char user_name[200];
    char user_password[200];
    int c=0,i=0;
    scanf("%s",&user_name);
    printf("\t\t\t请输入密码：");
    while ((c=getch()) != '\r') //使密码输入的时候显示*号
    {
        user_password[i++] = c;
        putchar('*');
    }
    user_password[i] = '\0';
    char admin[] = "admin";
    char adminpassword[] = "123456";
    char check[] = "check";
    char checkpassword[] = "123456";
    if(!strcmp(user_name,admin)&& !strcmp(user_password,adminpassword))
    {
        system("cls");
        printf("\n\t\t\t\t管理员你好\n");
        adminabc();
    }
    else
    {
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            system("cls");
            printf("\t\t\t************************\n");
            printf("\t\t\t\t收银员你好\n");
            checkabc(0,0.0,0.0);
        }
        else
        {

            printf("\n\t\t\t用户名或密码错误,请按回车重新登录\n");
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
    printf("\t\t\t    欢迎进入收银员系统\n");
    printf("\t\t\t************************\n\n\n");
    printf("\t\t        1收银\n\t\t        2本日收银报表\n\t\t        3返回主界面\n\n\n");
    do                  //检测是否输入正确的指令如果不是则重新输入
    {
        printf("\t\t\t\t请输入命令：");
        scanf("%d",&command);
         printf("\n");
        if(command!=1&&command!=2)
            printf("\t\t\t\t输入错误\n再次");

    }
    while(command!=1&&command!=2&&command!=3);
    if(command==1)           //1、进入收银员界面  2、进入本日收银报表
    {
    system("cls");
    checkcode();
    }
    else
    {


        if(command==3)
        {
        system("cls");
        login();
        }
        else
        {
        system("cls");
        printf("\t\t\t\t**********************\n");
        printf("\t\t\t\t 欢迎查看本日营销报表\n\t\t\t\t**********************\n本次订单号：%d\n 总价格：%.2f%\n  利润：%.2f\n",id,total,profit);
         printf("\n\n\n按任意键返回上一层");
         getchar();
         getchar();
         system("cls");
        checkabc(id,total,profit);
        }
    }
    return 0;
}


// 录入函数
void inputgoods()
{
    system("cls");
    char code[20];
    char name[20],num[20],price[20],chengben[20],end[20] = "end";
    int s;

    do
    {
        printf("\n\n*************************************************************\n");
        printf("\t请分别输入货品信息(以空格隔开，输入end结束输入)\n");
        printf("*************************************************************\n\n");
        printf("\t****条码***商品名称***价格***成本***库存****\n\n");
        printf("\t");
        scanf("%s",code);
        if(!strcmp(code,end)){
                system("cls");
            adminabc();
        }
        scanf("%s%s%s%s",name,price,chengben,num);
        if(!checknum(num) && !checknum(code) && !checknum(chengben) && !checknum(price))
            {
             printf("\n\t\t\t***********************");
             printf("\n\t\t\t      条码:%s\n\t\t\t      名称:%s\n\t\t\t      价格:%s       \n\t\t\t      成本:%s       \n\t\t\t      库存:%s\n",code,name,price,chengben,num);
              printf("\t\t\t***********************\n");
            }
        else{
            printf("您的输入有误，请重新输入。\n");
             s = 1;
            continue;

            }
       if(addgoods(code,name,price,chengben,num))
            printf("\t**添加成功**");
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
     printf("\t\t\t        *****************\n");
   printf("\t\t\t\t欢迎进入收银系统\n\t\t\t        *****************\n请输入商品条形码(输入end结束):");
    do
    {
        scanf("%s",code);
                if(!strcmp(code,endcode))
            break;
        if(checknum(code)){
            printf("您的输入有误，请重新输入");
            continue;
        }

        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {
                total = total+good[i-1].price;
                profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                profit.total = total;
               sale(good[i-1].code); //库存减一
                printf("\n\n\t\t\t\t商品名称：%s \n\t\t\t\t 价格：%2f元 \n\t\t\t\t 存量:%d \n\t\t\t\t 总价:%2f元\n",good[i-1].name,good[i-1].price,good[i-1].num-1,total);
            }
            else
            {
                printf("\t\t\t\t本商品已售罄，请重新输入");
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
                if(!(num[i]>='0'&&num[i]<='9'||num[i]=='.'))
                   {//printf("%s",num);
                    return 1;
                    break;
                   }
            }

     return 0;

}
