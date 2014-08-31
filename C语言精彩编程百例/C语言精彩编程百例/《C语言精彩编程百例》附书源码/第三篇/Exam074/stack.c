#include <stdio.h>
#include <stdlib.h>
#define Max 100

int *p;
int *tos;
int *bos;

/*���һ�����ݷŵ���ջ�Զ���*/
void push(int i)
{
	if(p > bos)
	{
		printf("��ջ����\n");
		return;
	}
	*p = i;
	p++;
}

/*�Զ�ջ����ȡ��һ������*/
int pop(void)
{
	p--;
	if(p < tos)
	{
		printf("��ջ����\n");
		return 0;
	}
	return *p;
}

void main(void)
{
	int a,b;
	char s[80];
	p = (int *)malloc(Max*sizeof(int));
	if(!p)
	{
		printf("�����ڴ�ʧ��");
		exit(1);
	}
	tos = p;
	bos = p + Max -1;
	printf("�������һ������:\n");
	scanf("%d",&a);
	push(a);
	printf("������ڶ�������:\n");
	scanf("%d",&b);
	push(b);
	printf("�����������:\n");
	scanf("%s",s);
	switch (*s)
	{
	case '+':
		a = pop();
		b = pop();
		printf("�����a+b = %d\n",(a+b));
		push(a+b);
		break;
	case '-':
		a = pop();
		b = pop();
		printf("�����a-b = %d\n",(a-b));
		push(a-b);
		break;
	case '*':
		a = pop();
		b = pop();
		printf("�����a*b = %d\n",(a*b));
		push(a*b);
		break;	
	case '/':
		a = pop();
		b = pop();
		printf("�����a/b = %d\n",(a/b));
		push(a/b);
		break;
	default:
		printf("��������ȷ������\n");
	}
}

