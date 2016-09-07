#include"goods.h"
#include<stdio.h>
int readGood(Goods *good,int n)     
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("请输入商品的信息\n");
		printf("编号:  ");
	     scanf("%ld", &good[i].num);
		if (good[i].num==0) break;
		printf("名称: ");
		scanf("%s",good[i].name);	
		printf("品牌:  ");
		scanf("%s",good[i].brand);
    	    good[i].stock=0;            
		printf("请输入商品的出库量和入库量:\n");
	     for (j=0;j<2;j++)
	    {
		    scanf("%d",&good[i].changes[j]);	
		}
		good[i].rank=0;                
	}
	return i;                       
}
void printGood ( Goods  *good , int n)       
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", good[i].num);
		printf("%8s", good[i].name);
		printf("%8s", good[i].brand);
		for (j=0;j<2;j++)
		   printf("%8d",good[i].changes[j]);
	    printf("%8d",good[i].stock);
	    printf("%6d\n",good[i].rank);
	}
}
int equal(Goods g1,Goods g2,int condition)  
{
	if (condition==1)                    
		return g1.num==g2.num;
	else if (condition==2)                
     {
	     if (strcmp(g1.name,g2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                
	     return g1.rank==g2.rank;
 else if (condition==4)               
		return g1.stock==g2.stock;
	else 
	
	return 1;                       
} 

int larger(Goods g1,Goods g2,int condition)  
{
	if (condition==1)                    
		return g1.num>g2.num;
	if (condition==2)                    
		return g1.stock>g2.stock;
	else return 1; 
}
void reverse(Goods good[],int n)             
{
	int i;
	Goods temp;
	for (i=0;i<n/2;i++)                   
	{
		temp=good[i];
		good[i]=good[n-1-i];
		good[n-1-i]=temp;
	}
}

void calcuStock(Goods good[],int n)         
{
	int i;
	for (i=0;i<n;i++)                    
	{
		good[i].stock =0;              
			good[i].stock =good[i].changes[0]-good[i].changes[1];
	}	
}

void calcuRank(Goods good[],int n)          
{
	int i ;                       
	sortGood(good,n,2);                  
	reverse(good,n);                      
	good[0].rank=1;                      
	for (i=1;i<n;i++)                     
	{
		if (equal(good[i],good[i-1],4))         
			good[i].rank=good[i-1].rank;      
	    else
			good[i].rank=i+1;             
	}
}
void calcuMark(double m[2][2],Goods good[],int n)
{
	int i,j;
     for (i=0;i<2;i++)            		 
{
				m[i][0]=good[0].changes[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<good[j].changes[i])
				m[i][0]=good[j].changes[i];
}
	 for (i=0;i<2;i++)                  
	{ 
		m[i][1]=good[0].changes[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>good[j].changes[i])
				m[i][1]=good[j].changes[i];
	}
	   
}
void sortGood(Goods good[],int n,int condition)  
{
	int i,j,minpos;                      
	Goods t;
	for (i=0;i<n-1;i++)                  
	{
		minpos=i;
		for (j=i+1;j<n;j++)             
			if (larger(good[minpos],good[j],condition))
				minpos=j;
		if (i!=minpos)                 
		{
			t=good[i];
			good[i]=good[minpos];
			good[minpos]=t;
		}
	}
}
int searchGood(Goods good[],int n,Goods g,int condition,int f[ ])  
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 
		if (equal(good[i],g,condition))  
		{
			f[j++]=i;                          
			find++;	                                                      
		}
	 return find;                                 
}

int insertGood(Goods good[],int n,Goods g)              
{
	int i;
	sortGood(good,n,1);                              
	for (i=0;i<n;i++)
	{
		if (equal(good[i],g,1))                      
		{
		    printf("这个记录已存在，不能再次插入!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          
	{
		if (!larger(good[i],g,1))                    
		break;
		good[i+1]=good[i];                        
	}
	good[i+1]=g;                                                                   
	n++;                                     
	return n;                                  
}

int deleteGood(Goods good[],int n,Goods g)            
{
	int i,j;
	for (i=0;i<n;i++)                           
		if (equal(good[i],g,1))   break;            
	if (i==n)                                 
	{
		printf("这个记录不存在!\n");    
		return n;
	}
	for (j=i; j<n-1; j++)                         
		good[j]=good[j+1];                       
                                                                            
	n--;                                      
	return n;                                  
}
