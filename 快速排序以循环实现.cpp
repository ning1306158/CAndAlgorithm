#include<stdio.h>
#include<stdlib.h>
//数组长度 
#define SIZE 16
//定义函数 
void quickSortLoop(int[],int,int );
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
	
	quickSortLoop(list,0,SIZE-1);
	
	//展示排序后 
	show(list,SIZE);
	
	return 0; 
}
//快速排序 
void quickSortLoop(int list[],int l_left,int l_right)
{
	//用数组实现简单栈 
	int stack[500];
	int top=0;
	stack[top++]=l_left;	
	stack[top++]=l_right;	
	while(top>-1)
	{
		int right=stack[--top];
		int left=stack[--top];
		int i=left;
		int j=right;
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
			}
		}
		//基准数归位 
		list[left]=list[i];
		list[i]=t;
		if(i+1<right)
		{
			stack[top++]=i+1;
			stack[top++]=right;
		}
		if(left<i-1)
		{
			stack[top++]=left;
			stack[top++]=i-1;
		}
	}
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

