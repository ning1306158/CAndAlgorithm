#include<stdio.h>
#include<stdlib.h>
//���鳤�� 
#define SIZE 16
//���庯�� 
void quickSortLoop(int[],int,int );
void show(int[] ,int );

int main()
{
	int list[100];
	
	//�������SIZE��С��50������ 
	for(int i=0;i<SIZE;i++)
	{
		list[i]=rand()%50;
	}
	
	//չʾ����ǰ 
	show(list,SIZE);
	
	quickSortLoop(list,0,SIZE-1);
	
	//չʾ����� 
	show(list,SIZE);
	
	return 0; 
}
//�������� 
void quickSortLoop(int list[],int l_left,int l_right)
{
	//������ʵ�ּ�ջ 
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
			//�Ӵ���С�� 
			while(i<j&&list[j]>=t) j--;
	
			//��С������ 
			while(i<j&&list[i]<=t) i++;
	
			//��û���� ���н��� 
			if(i<j)
			{
				int temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
		//��׼����λ 
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
//��ӡ���� 
void show(int list[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",list[i]);		
	}
	putchar('\n');
}

