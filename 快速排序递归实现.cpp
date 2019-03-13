#include<stdio.h>
#include<stdlib.h>
//数组长度 
#define SIZE 16
//定义函数 
void quickSortRecursion(int[],int,int );
void show(int[] ,int );

int main()
{
	int list[100];
	
	//随机生成SIZE个小于50的整数 
	for(int i=0;i<SIZE;i++)
	{
		list[i]=rand()%50;
	}
	
	//展示排序前 
	show(list,SIZE);
	
	quickSortRecursion(list,0,SIZE-1);
	
	//展示排序后 
	show(list,SIZE);
	
	return 0; 
}
//递归快速排序 
void quickSortRecursion(int list[],int left,int right)
{
	//跳出条件 
	if(left>=right) return;
	
	int i=left;
	int j=right;

	//定义基准数 
	int t=list[left];

	while(i<j)
	{
		//从大往小找 
		while(i<j&&list[j]>=t) j--;

		//从小往大找 
		while(i<j&&list[i]<=t) i++;

		//还没遇到 进行交换 
		if(i<j)
		{
			int temp=list[i];
			list[i]=list[j];
			list[j]=temp;
//			printf("交换%d和%d\n",list[i],list[j]);
//			show(list,SIZE);
		}

	}

	//基准数归位 
	list[left]=list[i];
	list[i]=t;

//	printf("基准数归位\n");
//	show(list,SIZE); 
//	printf("-------------------------\n");
	//基准数以左继续快速排序 
	quickSortRecursion(list,i+1,right);
	//基准数以右继续快速排序 
	quickSortRecursion(list,left,i-1);
}
//打印数组 
void show(int list[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",list[i]);		
	}
	putchar('\n');
}

