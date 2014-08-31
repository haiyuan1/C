#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define NUM 4

struct chain
{
	char name[20];
	char city[20];
	char sex[10];
	char age[10];
	char job[10];
	struct chain *next;
};

struct chain *create();
struct chain *SequelSeach(head,name);
void print_data(point);

struct chain Datas[NUM]=
{
	"Sun","Weifang","Male","24","student",NULL,
	"Tom","Beijing","Male","31","doctor",NULL,
	"Marry","Shanghai","Female","19","techer",NULL,
	"Willing","Tianjing","Female","21","worker",NULL
};

int main(void)
{
	struct chain *head;
	struct chain *p;
	char name[30];
	head = create();
	printf("������Ҫ���ҵ�����\n");
	scanf("%s",name);
	p = SequelSeach(head,name);
	print_data(p);
	return 0;
}

struct chain *create()
{
	struct chain *head, *tail, *p;
	int i;
	head = tail = NULL;
	printf("�������������뵽������:\n");
	for(i= 0;i < NUM; i++)
	{	
		p = (struct chain *)malloc (sizeof (struct chain));
		strcpy(p->name, Datas[i].name);
		strcpy(p->city,Datas[i].city);
		strcpy(p->sex,Datas[i].sex);
		strcpy(p->age,Datas[i].age);
		strcpy(p->job,Datas[i].job);
		p->next = NULL;
		if(head == NULL)
			head = tail = p;
		else 
			tail = tail ->next;
			tail ->next = p;
	}
	return head;
}

struct chain *SequelSeach(head,name)
struct chain *head;
char name[];
{
	struct chain *temp;
	temp = head;
	for(temp=head;temp!=NULL;)
	{
		if(strcmp(temp->name,name) == 0)
		break;
		else
			temp = temp->next;
	}
	if(temp ==NULL)
		printf("û�в��ҵ���������\n");
	return temp;
}

void print_data(point)
struct chain *point;
{
	if(point ==NULL)
		return;
	printf("���ҽ����\n");
	printf("	������%s\n",point->name);
	printf("	���У�%s\n",point->city);
	printf("	�Ա�%s\n",point->sex);
	printf("	���䣺%s\n",point->age);
	printf("	������%s\n",point->job);
}

