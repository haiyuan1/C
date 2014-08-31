#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node
{
	char Data[80];
	struct node *Next;
}nodetype;

typedef struct head
{
	int Num;			/*�к�*/
	int Len;			/*�����ַ��ĸ���*/
	nodetype *Next;
}headtype;

headtype Head[MAX];

void Initial();
int MenuSelect();
void EnterData();
void DeleteLine();
void List();
void ClearBuffer();

main()
{
	char choice;
	Initial();
	while(1)
	{
		choice = MenuSelect();
		switch (choice)
		{
			case 1:EnterData();
				break;
			case 2:DeleteLine();
				break;
			case 3:List();
				break;
			case 4:exit(0);
		}
	}
}

void ClearBuffer()
{
	while(getchar()!='\n');
}

void Initial()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		Head[i].Len=0;
	}
}

int MenuSelect()
{
	int i;
	i=0;
	printf(" 1. Enter\n");
	printf(" 2. Delete\n");
	printf(" 3. List\n");
	printf(" 4. Exit\n");
	while(i<=0||i>4)
	{
		printf("������˵�ѡ���\n");
		scanf("%d",&i);
		ClearBuffer();
	}
	return(i);
}

void EnterData()
{
	nodetype *p,*find();
	int i,j,m,LineNumber,k;
	char StrBuffer[100];
	while(1)
	{
		printf("��������Ҫ������к�(0~100):\n");
			scanf("%d",&LineNumber);
		ClearBuffer();
		if(LineNumber<0||LineNumber>=MAX)
			return;
		printf("������Ҫ��������ݣ���@��Ϊ��������\n");
		i=LineNumber;
		Head[i].Num=LineNumber;
		Head[i].Next=(nodetype *)malloc(sizeof(nodetype));
		p=Head[i].Next;
		m=1;
		j=-1;
		StrBuffer[0]=0;
		k=0;
		do
		{
			j++;
			if(!StrBuffer[k])
			{
				
				scanf("%s",StrBuffer);
				k=0;
			}
			if(j>=80*m)
			{
				m++;
				p->Next=(nodetype *)malloc(sizeof(nodetype));
				p=p->Next;
			}
			p->Data[j%80] = StrBuffer[k++];
		}while(p->Data[j%80]!='@');
		Head[i].Len = j;
	}
}

void DeleteLine()
{
	nodetype *p,*q;
	int i,j,m,LineNumber;
	while(1)
	{
		printf("����Ҫɾ�����к�(0~100)��\n");
		scanf("%d",&LineNumber);
		if(LineNumber<0||LineNumber>=MAX)
			return;
		i = LineNumber;
		p=Head[i].Next;
		m=0;
		if(Head[i].Len>0)
		{
			m=(Head[i].Len-1)/80+1;		/*���Ҹ����õ�����������*/
		}
		for(j=0;j<m;j++)
		{
			q=p->Next;
			free(p);
			p=q;
		}
		Head[i].Len=0;
		Head[i].Num=0;
	}
}

void List()
{
	nodetype *p;
	int i,j,m,n;
	for(i=0;i<MAX;i++)
	{
		if(Head[i].Len>0)
		{
			printf("��%d�������ݣ������ǣ�\n",Head[i].Num);
			n=Head[i].Len;
			m=1;
			p=Head[i].Next;
			for(j=0;j<n;j++)
				if(j>=80*m)
				{
					p=p->Next;
					m++;
				}
				else
				printf("%c",p->Data[j%80]);
				printf("\n");
		}
	}
	printf("\n");
}
		