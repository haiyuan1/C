#include <stdio.h>
#include <stdlib.h> 

struct chain
{
	int value;
	struct chain *next;
};

struct chain *create()
{
	struct chain *head, *tail, *p;
	int x,i;
	head = tail = NULL;
	printf("�������ĸ��������ݣ�Ȼ��س�:\n");
	for(i= 0;i < 4; i++)
	{	
		scanf("%d",&x);
		p = (struct chain *)malloc (sizeof (struct chain));
		p->value = x;
		p->next = NULL;
		if(head == NULL)
			head = tail = p;
		else 
			tail = tail ->next = p;
	}
	return head;
}

struct chain *inlink(head,a,b)
struct chain *head;
int a, b;
{
	struct chain *p, *q, *s;
	s = (struct chain *)malloc(sizeof(struct chain));
	s->value = b;
	/*�ձ����*/
	if(head == NULL)
	{
		head = s;
		s->next = NULL;
	}
	/*����s�����Ϊ�±�ͷ*/
	if(head->value == a)
	{
		s->next = head;
		head = s;
	}
	else
	{
		p = head;
	/*����������Ѱ��������ֵΪa�Ľ��*/
		while ((p->value != a)&&(p->next != NULL))
		{
			q = p;
			p = p->next;
		}
		if(p->value == a)			//�ҵ�������Ϊa�Ľ��
		{
			q->next = s;
			s->next = p;
		}
	/*������s��Ϊ��β*/
		else
		{
			p->next = s;
			s->next = NULL;
		}
	}
	return(head);
}

struct chain *dellink(head,a)
struct chain *head;
int a;
{
	struct chain *p,*q;
	if(head == NULL)
		printf("������\n");
	else if(head ->value == a)
	/*����ĵ�һ����㼴Ϊa���*/
	{
		p = head;
		head = head->next;
	}
	else
	{
		p = head;
		while ((p->value != a)&&(p->next != NULL))
		/*����������������Ϊa�Ľ��*/
		{
			q = p;
			p = p->next;
		}
		if(p->value != a)
		/*��������������ֵΪa�Ľ��*/
			printf("û��Ҫɾ�������� %d\n",a);
		else 
		{
			q ->next = p->next;
			free(p);
		}
	}
	return(head);
}

void main()
{
	struct chain *q,*head;
	int a, b;
	q = create();
	head = q;
	while(q)			//��ʾ����
	{
		printf("%d\n",q->value);
		q = q->next;
	}
	printf("�������²���ı�Ԫ����λ���Ǹ�����֮ǰ��");
	scanf("%d",&a);
	printf("\n ������Ҫ����ı�Ԫ���ݣ� ");
	scanf("%d",&b);
	
	q = inlink(head,a,b);
	head = q;
	while(q)			//��ʾ����
	{
		printf("%d\n",q->value);
		q = q->next;
	}

	printf("������Ҫɾ����Ԫ�����ݣ� ");
	scanf("%d",&a);
	q = dellink(head,a);
	while(q)			//��ʾ����
	{
		printf("%d\n",q->value);
		q = q->next;
	}
}
