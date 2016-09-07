#include <stdio.h>
#include <string.h>
#include <malloc.h>

//定义运动员结构体 
struct Athlete{
	long project;        
	char name[20];  //姓名 
	char sex[10];   //性别 
	int  num[3];   //包括金银铜牌数目 
	int  total;
	int  form;
};

void copyAthlete(struct Athlete* dest,struct Athlete* src){     //复制运动员信息 
	dest->project = src->project;
	memcpy(dest->name,src->name,20*sizeof(char));
	memcpy(dest->sex,src->sex,10*sizeof(char));
	memcpy(dest->num,src->num,3*sizeof(int));
	dest->total = src->total;
	dest->form = src->form;
}

void listAthleteByGold(struct Athlete athletes[],int total){                    //按照金牌排序 
	int i,j;
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));     //temp用来交换 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));         //复制所有运动员信息，用于排序 
	
	for(i=0;i<total-1;i++){                                                //冒泡排序，根据金牌数量 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[0] > athletes_temp[j+1].num[0]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("获得金牌数量由少到多依次是：\n");                         //打印信息 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[0]);
	}
	
}

void listAthleteBySilver(struct Athlete athletes[],int total){                 //按照银牌排序 
	int i,j;
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));         //temp用来交换 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));                     //复制所有运动员信息，用于排序 
	
	for(i=0;i<total-1;i++){                                                        //冒泡排序，根据银牌数量 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[1] > athletes_temp[j+1].num[1]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("获得银牌数量由少到多依次是：\n");                                        //打印信息 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[1]);
	}
	
}


void listAthleteByCopper(struct Athlete athletes[],int total){                        //按照铜牌排序 
	int i,j; 
	struct Athlete athletes_temp[20];
	struct Athlete* temp = (struct Athlete*)malloc(sizeof(struct Athlete));             //temp用来交换 
	if(temp==NULL){
		printf("temp = NULL\n");
	} 
	memcpy(athletes_temp,athletes,total*sizeof(struct Athlete));                    //复制所有运动员信息，用于排序 
	
	for(i=0;i<total-1;i++){                                                        //冒泡排序，根据银牌数量 
		for(j=i;j<total-1-i;j++){
			if(athletes_temp[j].num[2] > athletes_temp[j+1].num[2]){
				copyAthlete(temp,&athletes_temp[j]);
				copyAthlete(&athletes_temp[j],&athletes_temp[j+1]);
				copyAthlete(&athletes_temp[j+1],temp);
			}
			
		}
	}
	printf("获得铜牌数量由少到多依次是：\n");                                         //打印信息 
	for(i=0;i<total;i++){
		printf("%10s%10s%10d\n",athletes_temp[i].name,athletes_temp[i].sex,athletes_temp[i].num[2]);
	}
	
}

void getMostGoldAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostGold = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[0]>mostGold){
			mostGold = athletes[i].num[0];                         //保存金牌最大值 
			j = i;
		}
	}
	printf("获得金牌数量最多的是运动员:%s\n", athletes[j].name);
}

void getMostSilverAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostSilver = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[1]>mostSilver){
			mostSilver = athletes[i].num[1];                  //保存银牌最大值 
			j = i;
		}
	}
	printf("获得银牌数量最多的是运动员:%s\n", athletes[j].name);
}

void getMostCopporAthlete(struct Athlete athletes[],int total){
	int i,j=0;
	int mostCoppor = 0;
	for(i=0; i<total; i++){
		if(athletes[i].num[2]>mostCoppor){
			mostCoppor = athletes[i].num[2];                //保存铜牌最大值 
			j = i;
		}
	}
	printf("获得铜牌数量最多的是运动员:%s\n", athletes[j].name);
}

void getAthleteByName(struct Athlete athletes[],int total){
	int i;
	char name[20];
	printf("请输入运动员姓名进行查询获奖情况，姓名:");
	scanf("%s", name);                                    //输入查询姓名 
	for (i = 0; i < total; i++){                                //查找姓名 
		if (strcmp(name, athletes[i].name) == 0){
			printf("姓名：%s 性别：%s 金牌数：%d 银牌数:%d 铜牌数:%d\n",athletes[i].name, athletes[i].sex, 
				athletes[i].num[0], athletes[i].num[1], athletes[i].num[2]);
			break;                                        //若已经找到，则跳出for循环 
		}
	}
	if (i == 20){
		printf("%s不存在\n", name);                     //i加到了20，说明前面一直没跳出for循环，也就是一直没找到 
	}
	
} 

int main(){
	FILE* filep = NULL;
	struct Athlete athletes[20];          //用来保存从文件读取的运动员信息 
	char name[20];
	int i = 0;
	int total;
	int choice;
	filep =	fopen("Athlete.txt","r");              //打开提前录入信息的文件 
	if (filep == NULL){
		printf("Athlete.txt do not exist\n");      //文件不存在，打开失败 
		return 0;
	}

	while (!feof(filep)){                           //读取文件信息，直到读取完毕 
		fscanf(filep, "%ld%s%s%d%d%d%d%d", &athletes[i].project, &athletes[i].name, &athletes[i].sex,
			&athletes[i].num[0], &athletes[i].num[1], &athletes[i].num[2], &athletes[i].total, &athletes[i].form);
		++i;
	}
	total = i - 1; 	                            //读取的运动员个数 
	printf("##########################################\n");             //打印菜单 
	printf("###  欢迎进入奥运会获奖运动员管理系统  ###\n");
	printf("###  1: 按名字查询运动员获奖情况       ###\n");
	printf("###  2: 查找金牌最多的运动员           ###\n");
	printf("###  3: 查找银牌最多的运动员           ###\n");
	printf("###  4: 查找铜牌最多的运动员           ###\n");
	printf("###  5: 按照金牌数目排序运动员         ###\n");
	printf("###  6: 按照银牌数目排序运动员         ###\n");
	printf("###  7: 按照铜牌数目排序运动员         ###\n");
	printf("###  8: 退出系统\n");
	printf("##########################################\n");
	while(1){
		printf("please input your choice:"); 
		scanf("%d", &choice);                                  //读取用户菜单选择 
		switch(choice){
			case 1:
				getAthleteByName(athletes,total);
				break;
			case 2:
				getMostGoldAthlete(athletes,total);
				break;
			case 3: 
			    getMostSilverAthlete(athletes,total);
			    break;
			case 4:
				getMostCopporAthlete(athletes,total);
				break;
			case 5:
				listAthleteByGold(athletes,total);
				break;
			case 6:
			    listAthleteBySilver(athletes,total);
			    break;
			case 7:
				listAthleteByCopper(athletes,total);
				break; 
			case 8:
				return;
			default:
				printf("input invalid\n");            //输入有误，重新输入 
				continue;
		}
	}

	
	
    return 0; 

}
