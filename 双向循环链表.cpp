#include<stdio.h>
#include<stdlib.h>

//定义结构体 
struct node{
	int val;
	struct node * next;
	struct node * pre;
};
typedef struct node tag;
typedef struct node* Ptag;
//结构体大小 
int size=sizeof(tag);

//定义函数 
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
	printf("请输入功能代码:\n");
	printf("1展示:\n");
	printf("2添加:\n");
	printf("3删除:\n");
	printf("4反向打印:\n");
	printf("0退出:\n");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:{
			list_show(&t);
			break;
		}
		case 2:{
		printf("请输入插入的位置和数:\n");
		scanf("%d %d",&a,&b);
		list_insert(&t,a,b);
		list_show(&t);
			break;
		}
		case 3:{
		printf("请输入删除的位置:\n");
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
//插入列表 index为位置 val为值 
void list_insert(Ptag* head,int index,int val)
{
	if(index<1)
	{
		printf("插入位置错误!\n");	
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
		printf("插入位置错误!\n");	
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
			printf("插入位置错误!\n");	
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
//打印列表 
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
		printf("列表为空!");
	}
	while(thead!=*head)
	{
		printf("->%d",thead->val) ;
		thead=thead->next;
	}
	putchar('\n');
}
//反向打印列表 
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
		printf("列表为空!");
	}
	while(thead!=*head)
	{
		printf("->%d",thead->val) ;
		thead=thead->pre;
	}
	putchar('\n');
}
//根据位置删除 
void list_del(Ptag *head,int index)
{
	Ptag thead=*head;
	if(index<1)
	{
		printf("删除位置错误!\n");	
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
			printf("删除位置错误!\n");	
			return ;
		}
	}
	Ptag tmp=thead->next;
	thead->next=tmp->next;
	free(tmp);
}

