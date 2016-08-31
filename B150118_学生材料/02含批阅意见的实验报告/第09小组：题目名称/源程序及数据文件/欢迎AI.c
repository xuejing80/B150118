#include <stdio.h>
int main()
{
welcome();
return 0;
}
void welcome() /*欢迎主界面*/
{
system("CLS");
printf("\n\n\n\n\n\n\t\t\t★★★★★★★★★★★★★★★★★★★★\n");
printf("\t\t\t★ ★                              ★ ★\n");
printf("\t\t\t★ ★                              ★ ★\n");
printf("\t\t\t★ ★ 欢迎使用直播平台主播管理系统 ★ ★\n");
printf("\t\t\t★ ★                              ★ ★\n");
printf("\t\t\t★ ★                              ★ ★\n");
printf("\t\t\t★★★★★★★★★★★★★★★★★★★★\n");
printf("\n\t\t\t按任意键继续...");
getch();
login();
}
void login() /*登录界面*/
{
int select;
system("CLS");
system("CLS");
printf("\n\n\n\n\n\t\t\t※※※※※※※※※※\n");
printf("\t\t\t※ ※          ※ ※\n");
printf("\t\t\t※ ※1.注册用户※ ※\n");
printf("\t\t\t※----------------※\n");
printf("\t\t\t※ ※2.登录系统※ ※\n");
printf("\t\t\t※----------------※\n");
printf("\t\t\t※ ※3.退出系统※ ※\n");
printf("\t\t\t※ ※          ※ ※\n");
printf("\t\t\t※※※※※※※※※※\n");
label:
printf("\n\t\t\t请选择【1-3】:");
scanf("%d",&select);
switch(select)
{
case 1:
regist();
break;
case 2:
loginsystem();
break;
case 3:
exitsystem();
break;
default:
{
printf("\t\t\t无此项，请重新选择\n");
goto label;
}
}
}
void regist() /*注册用户*/
{
char cleck[30],ctemp; /*存放键盘输入的密码*/
int count=0;
while(1)
{
printf("\t\t\t管理员密码:");
int i=0;
while((ctemp=getch())!='\r')
{

cleck[i++]=ctemp;
putchar('*');
}
cleck[i]='\0';
if(strcmp(cleck,"123456")==0)
{
printf("\n\t\t\t密码正确\n");
break;
}
else
{
printf("\n\t\t\t密码错误\n");
exit(0);
}
}
printf("注册用户\n");
printf("注册成功!\n");
printf("按任意返回登录界面...");
getch();
login();
system("CLS");
}
void loginsystem() /*登录系统*/
{
printf("登录系统\n");
}
void exitsystem() /*安全退出系统*/
{
printf("安全退出系统\n");
}

