/*����һ����������*/
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
	int x;
	head = tail = NULL;
	printf("Input data.\n");
	while (scanf("%d",&x) == 1)	/*����������һ�����͵����ݣ���ô����ִ��*/
	{	
p = (struct chain *)malloc (sizeof (struct chain));
/*����ΪҪ�´����ı�Ԫp����һ���ڴ�ռ�*/
		p->value = x;
		p->next = NULL;
		if(head == NULL)
			head = tail = p;
		else 
/*tailΪ�����ڶ�����Ԫָ�룬tail->ʼ��ָ�����һ����Ԫ*/
			tail = tail ->next;	
			tail ->next = p;	
	}
	return head;
}

void main(){
	struct chain *p,*q;
	q = create();
	while(q) {
		printf("%d\n",q->value);
		p = q->next;
		free(q);
		q = p;
	}
}
