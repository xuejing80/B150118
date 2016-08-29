#include<stdio.h>
#include<string.h>
//登录函数
int login(){
printf("欢迎进入超市商品净销存系统\n");
printf("请登录！\n");
printf("请输入用户名：");
char user_name[20];
char user_password[20];
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
    printf("\n管理员你好");
}
else{
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            printf("\n收银员你好");
        }
        else{
    printf("\n用户名或密码错误,请重新登录\n");
     printf("\n");
    login();
        }
}
return 0;
}

//收银员函数
int check()
{
    printf("hello word");


}

