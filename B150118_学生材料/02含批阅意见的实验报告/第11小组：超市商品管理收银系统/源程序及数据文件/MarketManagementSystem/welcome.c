#include<stdio.h>
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

return 0;
}

