#include <stdio.h>
#define Max 100

void SetNull(front, rear)
int *front, *rear;
{
	*front = 0;
	*rear = 0;
}

int Empty(front,rear)
int *front, *rear;
{
	if(*front == *rear)
		return(1);
	else
		return(0);
}

int EnQueue(q,x,front,rear)
int q[];
int x;
int *front,*rear;
{
	*rear = (*rear+1) % Max;
	if(*front == *rear)

	{
		printf("���з�������\n");
		return(-1);
	}
	else
	{
		q[*rear] = x;
		return(0);
	}
}

int DelQueue(q,y,front,rear)
int q[];
int *y;
int *front,*rear;
{
	*front = (*front +1)%Max;
	if(*front == *rear)
	{
		printf("���з�������\n");
		return(-1);
	}
	else
	{
		*y = q[*front];
		return(0);
	}
}

void main()
{
	int q[Max];
	int f = 0, r = 0;	/*f��r�ֱ��Ӧ���е�ͷ��β���������д洢�����λ��*/
	int i,x,m,n;
	int a;
	SetNull(&f,&r);			/*��ն���*/
	printf("Ҫ������е��ַ�������\n");
	scanf("%d",&m);
	printf("������е��������ݣ�\n");
	for (i=0; i<m; i++)
	{
		i=i;
		scanf("%d",&x);
		a = EnQueue(q,x,&f,&r);
		if(a == -1)
			break;
	}
	printf("Ҫ������е��ַ�������");
	scanf("%d",&n);
	printf("����Ӷ�������ȡ�����ݣ�\n");
	for (i = 0; i<n; i++)
	{
		if(DelQueue(q,&x,&f,&r) == -1)
			break;
		printf("%d\n",x);
	}
	if(Empty(&f,&r) == 1)
		printf("����Ϊ��");
	else
		printf("�����л���%d������",(m-n));
}
	
