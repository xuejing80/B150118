#include<stdio.h>
void menu( )        
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. �˶�Ա��Ϣ���� ********\n");
		printf("******** 3. �˶�Ա�ɼ����� ********\n");
		printf("******** 4. ���˻�ɼ�ͳ�� ********\n");
     printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     
{
		printf("%%%%%%%% 1. �����˶�Ա��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ���˶�Ա��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸��˶�Ա��Ϣ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )    
{
		printf("@@@@@@@@ 1. �����˶�Ա���Ƹ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. ���ݽ��Ƹ������� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )   
{		printf("&&&&&&&& 1. ����Ƹ��������˶�Ա &&&&&&&&\n");
		printf("&&&&&&&& 2. �����Ƹ��������˶�Ա &&&&&&&&\n");
		printf("&&&&&&&& 3. ��ͭ�Ƹ��������˶�Ա &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    
{
		printf("######## 1. ���˶�Ա��Ŀ��ѯ   ########\n");
		printf("######## 2. ���˶�Ա������ѯ   ########\n");
		printf("######## 3. ���˶�Ա�ɼ���ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage()    	     

{  
		int choice;
     
do
	    {   
         menuBase( );                  
         printf("ѡ����Ҫʹ�õ�ѡ��: ");
		 scanf("%d",&choice);	          
		 switch(choice)
		     {
			   case 1:	break;
			   case 2:  printf("�������˶�Ա��Ŀ\n");
					    break;
			   case 3:  printf("�������˶�Ա��Ŀ\n");
					    break;
			   case 0: break;
		    }
		}
		while(choice);
return 0;                             
}
void scoreManage()          
{  
	int choice;
	do
	{
		menuScore( );                        
		printf("ѡ����Ҫʹ�õ�ѡ��:\n");
		scanf("%d",&choice);	                 
		switch(choice)
		{
			case 1:   break;
			case 2:   break;		
			case 0:   break;
		}
	}while(choice);
}
void countManage()               
{
		int choice;
		do
		{
			menuCount( );                        
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:  break;
				case 2:  break;
				case 3:  break;
				case 0:  break;
			}
		}while (choice);
}
void searchManage()               
{
    int choice;
do
{
			menuSearch( );                         
			printf("ѡ����Ҫʹ�õ�ѡ��:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("���������ѯ�˶�Ա��Ŀ:\n");
				          break;
				case 2:   printf("���������ѯ�˶�Ա����:\n");
				      	  break;   
				case 3:   printf("���������ѯ�˶�Ա�ɼ�����:\n");
				          break;
				case 0:   break;
			}
		 
	    }while (choice);
}
int main()    
{
	int choice;
	menu();
    printf("��ѡ����Ҫʹ�õ�ѡ��: ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:  break;
			case 2:  baseManage();    
			   	     break;
			case 3:  scoreManage();     
					 break;
			case 4: countManage();     
					break;
			case 5: searchManage();     
				     break;
          case 0: break;
		}
		return 0;
}