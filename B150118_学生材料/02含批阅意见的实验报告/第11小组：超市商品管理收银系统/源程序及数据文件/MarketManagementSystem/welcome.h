//结构体声明部分
struct goods{
    char code[20];
    char name[30];
    double price;
    double chengben;
    int num;
    };
typedef struct goods goods;

struct order{
    int id;
    double total;
    double profit;
    };
typedef struct order order;
//函数声明部分
int login();
void adminabc();
void checkabc(int id,double total,double profit);
struct goods readcode();
void inputgoods();
void checkcode();
int ifexist();
void createorder();
int neworder();
void sale();
double totalprofit();
int checknum();
