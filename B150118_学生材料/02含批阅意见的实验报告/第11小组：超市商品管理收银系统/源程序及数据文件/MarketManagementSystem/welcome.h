//结构体声明部分
struct goods{
    char code[20];
    char name[30];
    double price;
    double chengben;
    int num;
    };
typedef struct goods goods;

//函数声明部分
int login();
void adminabc();
void checkabc();
struct goods readcode();
void inputgoods();
int checkcode();
int ifexist();
