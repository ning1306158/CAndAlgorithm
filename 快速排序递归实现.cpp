#include<stdio.h>
#include<stdlib.h>
//���鳤�� 
#define SIZE 16
//���庯�� 
void quickSortRecursion(int[],int,int );
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
	
	quickSortRecursion(list,0,SIZE-1);
	
	//չʾ����� 
	show(list,SIZE);
	
	return 0; 
}
//�ݹ�������� 
void quickSortRecursion(int list[],int left,int right)
{
	//�������� 
	if(left>=right) return;
	
	int i=left;
	int j=right;

	//�����׼�� 
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
//			printf("����%d��%d\n",list[i],list[j]);
//			show(list,SIZE);
		}

	}

	//��׼����λ 
	list[left]=list[i];
	list[i]=t;

//	printf("��׼����λ\n");
//	show(list,SIZE); 
//	printf("-------------------------\n");
	//��׼����������������� 
	quickSortRecursion(list,i+1,right);
	//��׼�����Ҽ����������� 
	quickSortRecursion(list,left,i-1);
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

