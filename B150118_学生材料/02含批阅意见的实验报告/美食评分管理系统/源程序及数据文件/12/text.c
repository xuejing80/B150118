
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"food.h"

void printHead( )      /*��ӡ��Ʒ��Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","���","����","��ϵ","ɫ","��","ζ","�ܷ�","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ʒ���ֹ��� ********\n");
		printf("******** 4. ������Ŀͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. �����Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸Ĳ�Ʒ��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3����Ʒ���ֲ˵�����*/
{
		printf("@@@@@@@@ 1. �����Ʒ�ܷ� @@@@@@@@\n");
		printf("@@@@@@@@ 2. �����ܷ����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4��������Ŀ�˵�����*/
{
		printf("&&&&&&&& 1. ��������߷� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��������ͷ� &&&&&&&&\n");
		printf("&&&&&&&& 3. ������ƽ���� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����β�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Food foo[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Food s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readFoo(&s,1);       /*����һ��������Ĳ�Ʒ��¼*/
					 n=insertFoo(foo,n,s);   /*���ú��������Ʒ��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*����һ����ɾ���Ĳ�Ʒ���*/
					 n=deleteFoo(foo,n,s);   /*���ú���ɾ��ָ����ŵĲ�Ʒ��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*����һ�����޸ĵĲ�Ʒ���*/
				      t=searchFoo(foo,n,s,1,find) ; /*���ú�������ָ����ŵĲ�Ʒ��¼*/
				      if (t)                 /*�����ѧ�ŵļ�¼����*/
					 {
						  readFoo(&s,1);   /*����һ�������Ĳ�Ʒ��¼��Ϣ*/
					      foo[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*�������ŵļ�¼������*/ 
 printf("this food is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void scoreManage(Food foo[],int n)          /*�ú�����ɲ�Ʒ���ֹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(foo,n);         /*�����в�Ʒ���ܷ�*/
					  break;
			case 2:   calcuRank(foo,n);         /*�������в�Ʒ���ܷ�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��߷֡���ͷ֡�ƽ����*/
int i;
    printf(s);                                  /*�����s������������������ʾ��Ϣ*/
    for (i=0;i<3;i++)                           /*i������һ��������Ŀ*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Food foo[],int n)               /*�ú���������ֳɼ�ͳ�ƹ���*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,foo,n);                 /*���ô˺���������������Ŀ����ߡ���͡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("����������Ŀ����߷ֱַ���:\n",mark,0);  /*�����߷�*/
				      break;
				case 2:   printMarkCourse("����������Ŀ����ͷֱַ���:\n",mark,1);  /*�����ͷ�*/
				      break;
				case 3:   printMarkCourse("����������Ŀ��ƽ���ֱַ���:\n",mark,2);  /*���ƽ����*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Food foo[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Food s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a food\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*�������ѯ��Ʒ�����*/
					  break;
				case 2:   printf("Input a food\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ��Ʒ������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯ��Ʒ������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchFoo(foo,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printFoo(foo[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Food foo[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortFoo(foo,n,1);         /*�������С�����˳�������¼*/ 
          	 printFoo(foo,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(foo,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(foo,n);     /* 3. ��Ʒ���ֹ���*/
					break;
			case 4: countManage(foo,n);     /* 4. ��Ʒ����ͳ��*/
					break;
			case 5: searchManage(foo,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Food foo[NUM];                /*����ʵ��һά����洢��Ʒ��¼*/
      int choice,n;
	 n=readFile(foo);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(foo);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(foo,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortFoo(foo,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(foo,n);                   /*����������ļ�*/
      return 0;
}