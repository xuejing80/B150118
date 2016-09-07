#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
//登录函数
int login()
{
    printf("欢迎进入超市商品进销存系统\n"); //登录UI加载
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
    char admin[] = "root"; //验证账号密码进入相应的函数
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

            printf("\n用户名或密码错误,请按回车重新登录\n"); //密码错误后显示递归调用
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
//收银员函数
void checkabc(int id,double total,double profit)
{
    int command;
    printf("欢迎进入收银员系统\n");
    printf("1、收银\n2、本日收银报表\n3、返回登录页面\nW");
    do                  //检测是否输入正确的指令如果不是则重新输入
    {
        printf("请输入命令：");
        scanf("%d",&command);
        printf("\n");
        if(command!=1&&command!=2)
            printf("输入错误\n再次输入");

    }
    while(command!=1&&command!=2&&command!=3);
    if(command==1)           //1、进入收银员界面  2、进入本日收银报表3.返回登录页面
    {
        system("cls");
        checkcode();
    }
    else
    { //本次订单的报表
        if(command == 3) //检测到三就回到登录页面
        {
            system("cls");
            login();
        }
        system("cls");
        printf("欢迎查看本日营销报表\n本次订单号：%d总价格：%.2f%利润：%.2f\n",id,total,profit);  //输出本次的营销报表
        printf("按任意键返回上一层");
        getchar();
        getchar();
        system("cls");
        checkabc(id,total,profit); //把利润等信息发回收银员主函数，调回主函数
    }
    return 0;
}

//收银函数
void checkcode()
{
    char code[20],endcode[20]="q",number[20],deletecode[20]="d";
    int flag=0;
    goods good[100]; //结构体数组储存已经收到的条码
    int i=0,c=1,d=0,e = 0;
    double total=0.0,numdouble,intnum[100];
    order profit;
    printf("欢迎进入收银系统\n请输入商品条形码以及你需要的数量(输入q结束,输入d进入删除模式)：\n");
    do
    {
        scanf("%s",code); //首先检测是不是输入了end
        if(!strcmp(code,endcode))
            break;
        //删除模式开始
        if(!strcmp(code,deletecode))
        {
            if(flag == 0) // 如果flag是0 就认为没有输入商品
            {
                printf("你还没有输入任何商品。请重新输入。");
                checkcode();
            }
            printf("您已进入删除模式，请输入要删除的商品条形码以及你需要删除的数量：(输入q结束)\n");
            printf("本次购买的商品：\n");
            printf("       条码         名称    数量     \n");
            for(d=0; d<i; d++) //输出现在正在订单里面的商品
            {
                printf("%10s%10s%10.0f\n",good[d].code,good[d].name,intnum[d+1]);
            }
            do
            {
                scanf("%s",code);
                if(!strcmp(code,endcode))
                    break;
                scanf("%s",number);
                if(checknum(code) || checknum(number)) // 输入过滤检测
                {
                    printf("您的输入有误，请重新输入");
                    continue;
                }
                numdouble = atof(number); //经过检测后的整型转换成实型
                if(numdouble <= 0)
                {
                    printf("您的输入有误，请重新输入");
                    continue;
                }
                if(ifexist(code))
                {
                    good[i++] = readcode(code);
                    if(good[i-1].num>0)

                    {
                        c=1;
                        for(; c<=numdouble; c++) //根据结构体数组的信息来减掉商品
                        {
                            total = total-good[i-1].price;
                            profit.profit = profit.profit - (good[i-1].price-good[i-1].chengben);
                            profit.total = total;
                            saleadd(good[i-1].code);
                        } //库存+一
                        printf("商品名称：%10s 价格：%10.2f元 删除数量:%10.0f \n现总价:%10.2f元\n",good[i-1].name,good[i-1].price,numdouble,total);
                    }
                    else
                    {
                        printf("本商品已售罄，请重新输入"); //检测商品是否卖空了
                        continue;
                    }
                }
                else
                {
                    continue;

                }
            }
            while(1);
            printf("\n请输入商品条形码以及你需要的数量(输入end结束)：\n");
            continue;
        }
        //删除模式结束
        //添加商品
        scanf("%s",number);
        if(checknum(code) || checknum(number))
        {
            printf("您的输入有误，请重新输入");
            continue;
        }
        numdouble = atof(number);
        intnum[++e] = numdouble;
        if(numdouble <= 0)
        {
            printf("您的输入有误，请重新输入");
            continue;
        }
        if(ifexist(code))
        {
            good[i++] = readcode(code);
            if(good[i-1].num>0)
            {
                c=1;
                for(; c<=numdouble; c++)
                {
                    total = total+good[i-1].price;
                    profit.profit = profit.profit + good[i-1].price-good[i-1].chengben;
                    profit.total = total;
                    sale(good[i-1].code);
                    flag = 1; //列表里已经有商品了。
                } //库存减一
                printf("商品名称：%10s 价格：%10.2f元 购买数量:%10.0f \n总价:%10.2f元\n",good[i-1].name,good[i-1].price,numdouble,total);
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
    createorder(profit.total,profit.profit);//创建订单，写入文件

}

// 管理员入口函数
void adminabc()
{
    int month;
    int a;
    char b;
    do
    {
        printf("欢迎进入管理员页面\n\n"); //UI初始化
        printf("  1商品信息录入\n  2商品库存情况列表\n  3总体利润报表\n  4返回登录页面\n\n\n");
        printf("请输入命令：");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("输入有误，请重新输入!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a) //根据命令进入入口函数
    {
    case 1:
        inputgoods();
        break;
    case 2:
        showgoods();
        break;
    case 3:
        printf("\t\t\t\t请输入查询月份：");
        scanf("%d",&month);
        while(month!=1&&month!=2&&month!=3&&month!=4&&month!=5&&month!=6&&month!=7&&month!=8&&month!=9&&month!=10&&month!=111&&month!=12)   //检验输入的是否为合法月份
        {
            printf("\t\t\t\t输入有误，请重新输入！");
            scanf("%d",&month);
        }

        printf ("\n\n\t\t\t\t********************\n");
        printf ("\t\t\t\t欢迎查看%d月营销报表\n",month);
        printf ("\t\t\t\t********************\n");

        printf("\n\n\t\t  本月订单清单:");

        printf("\n\n\n\n\t\t 本月零售总额:");
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

// 管理员录入函数
void inputgoods()
{
    system("cls");
    char code[20];
    char name[20],num[20],price[20],chengben[20],end[20] = "end";
    int s;

    do
    {
        printf("请分别输入货品信息：条码、商品名称、价格、成本、库存*以空格隔开* \n输入end返回主菜单\n\n");
        scanf("%s",code);
        if(!strcmp(code,end))
        {
            system("cls");
            adminabc();
        }
        scanf("%s%s%s%s",name,price,chengben,num);
        if(!checknum(num) && !checknum(code) && !checknum(chengben) && !checknum(price))  //调用检查函数检查输入是否合法
            printf("\n   条码:%s\n   名称:%s\n   价格:%s\n   成本:%s\n",code,name,price,chengben);
        else
        {
            printf("您的输入有误，请重新输入。\n");
            s = 1;
            continue;

        }
        if(addgoods(code,name,price,chengben,num))
            printf("添加成功");
        else
            printf("添加失败");
        printf("\n是否继续 1是 or 2否\n\n"); //循环递归
        scanf("%d",&s);
        if(s==2)
        {
            system("cls");
            adminabc();
        }
    }
    while (s==1);
}


//输入过滤函数
int checknum(const char*num)
{
    int i;
    for(i=0; i<20; i++)
    {
        if(num[i]=='\0') break;
        if(!(num[i]>='0'&&num[i]<='9'||num[i]=='\0'))
        {
            //printf("%s",num);
            return 1;
            break;
        }
    }

    return 0;

}
