#include<stdio.h>
#include<stdlib.h>

//����ṹ�� 
struct node{
	int val;
	struct node * next;
	struct node * pre;
};
typedef struct node tag;
typedef struct node* Ptag;
//�ṹ���С 
int size=sizeof(tag);

//���庯�� 
void list_insert(Ptag* ,int ,int );
void list_show(Ptag*);
void list_show_pre(Ptag*);
void list_del(Ptag *,int );
int main()
{
	int a=0,b=0; 
	tag *t=NULL;
	int sel=0;
	
	while(true)
	{
	printf("�����빦�ܴ���:\n");
	printf("1չʾ:\n");
	printf("2���:\n");
	printf("3ɾ��:\n");
	printf("4�����ӡ:\n");
	printf("0�˳�:\n");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:{
			list_show(&t);
			break;
		}
		case 2:{
		printf("����������λ�ú���:\n");
		scanf("%d %d",&a,&b);
		list_insert(&t,a,b);
		list_show(&t);
			break;
		}
		case 3:{
		printf("������ɾ����λ��:\n");
		scanf("%d",&a);
		list_del(&t,a);
		list_show(&t);
			break;
		}
		case 4:{
			list_show_pre(&t);
			break;
		}
		case 0:{
			exit(0);
			break;			
		}
		default:{
			break;
		}
	}
	}
}
//�����б� indexΪλ�� valΪֵ 
void list_insert(Ptag* head,int index,int val)
{
	if(index<1)
	{
		printf("����λ�ô���!\n");	
		return; 
	}
	Ptag thead=*head;
	if(index==1)
	{
		if(thead==NULL)
		{
			Ptag p1=(Ptag)malloc(size);
			p1->val=val;
			p1->next=p1;
			p1->pre=p1; 
			*head=p1; 
			return;
		}
		else
		{
			Ptag p1=(Ptag)malloc(size);
			p1->val=val;
			p1->next=thead;
			p1->pre=thead->pre;
			p1->pre->next=p1;
			thead->pre=p1; 
			*head=p1; 
			return ;	
		}
	}
	if(thead==NULL)
	{
		printf("����λ�ô���!\n");	
		return ;		
	}
	for(int i=2;i<index;i++)
	{
		if(thead->next!=*head)
		{
			thead=thead->next;
		}
		else
		{
			printf("����λ�ô���!\n");	
			return ;
		}
	}
	Ptag p1=NULL;
	p1=(Ptag)malloc(size);
	p1->val=val;
	p1->next=thead->next;
	p1->pre=thead;
	p1->next->pre=p1; 
	thead->next=p1;
}
//��ӡ�б� 
void list_show(Ptag *head)
{
	Ptag thead=*head; 
	if(thead!=NULL)
	{
		printf("%d",thead->val) ;
		thead=thead->next;
	}
	else
	{
		printf("�б�Ϊ��!");
	}
	while(thead!=*head)
	{
		printf("->%d",thead->val) ;
		thead=thead->next;
	}
	putchar('\n');
}
//�����ӡ�б� 
void list_show_pre(Ptag *head)
{
	Ptag thead=*head; 
	if(thead!=NULL)
	{
		printf("%d",thead->val) ;
		thead=thead->pre;
	}
	else
	{
		printf("�б�Ϊ��!");
	}
	while(thead!=*head)
	{
		printf("->%d",thead->val) ;
		thead=thead->pre;
	}
	putchar('\n');
}
//����λ��ɾ�� 
void list_del(Ptag *head,int index)
{
	Ptag thead=*head;
	if(index<1)
	{
		printf("ɾ��λ�ô���!\n");	
		return; 
	}
	if(index==1)
	{
		Ptag tmp=thead;
		thead=thead->next;
		free(tmp);
		return; 
	}
	for(int i=2;i<index;i++)
	{
		if(thead->next!=NULL)
		{
			thead=thead->next;
		}
		else
		{
			printf("ɾ��λ�ô���!\n");	
			return ;
		}
	}
	Ptag tmp=thead->next;
	thead->next=tmp->next;
	free(tmp);
}

