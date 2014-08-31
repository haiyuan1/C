#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define NUM 4

struct tree
{
	char name[20];
	char city[20];
	char sex[10];
	char age[10];
	char job[10];
	struct tree *left;
	struct tree *right;
};

struct tree Datas[NUM]=
{
	"Willing","Tianjing","Female","21","worker",NULL,NULL,
	"Tom","Beijing","Male","31","doctor",NULL,NULL,
	"Sun","Weifang","Male","24","student",NULL,NULL,
	"Marry","Shanghai","Female","19","techer",NULL,NULL
};

struct tree *construct(
	struct tree *root, 
	struct tree *r, 
	struct tree *Data)
{
	if(!r)
	{
		r = (struct tree *)malloc(sizeof(struct tree));
		if(!r)
		{
			printf("�ڴ����ʧ�ܣ�");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		strcpy(r->name,Data->name);
		strcpy(r->city,Data->city);
		strcpy(r->sex,Data->sex);
		strcpy(r->age,Data->age);
		strcpy(r->job,Data->job);
		if(!root)
			return r;
		if(strcmp(Data->name,root->name)<0)
			root->left = r;
		else 
			root->right = r;
		return r;
	}
	if(strcmp(Data->name,r->name)<0)
		construct(r,r->left,Data);
	else
		construct(r,r->right,Data);

	return root;	
}

struct tree *Search(root,name)
struct tree *root;
char name[];
{
	struct tree *p;
	if(root == NULL)
		printf("����Ϊ��\n");
	p = root;
	while(strcmp(p->name,name)!=0)
	{
		if(strcmp(p->name,name)>0)
			p = p->left;
		else
			p = p->right;
		if(p == NULL)
			break;
	}
	return(p);
}

void print(struct tree *r)
{
	if(!r)
		return;
	print(r->left);
	printf("%s\n",r->name);
	print(r->right);
}

void print_currentData(struct tree *point)
{
	if(point == NULL)
		return;
	printf("	������%s\n",point->name);
	printf("	���У�%s\n",point->city);
	printf("	�Ա�%s\n",point->sex);
	printf("	���䣺%s\n",point->age);
	printf("	������%s\n",point->job);
}

int main(void)
{
	int i;
	char c[10];
	char swap[20];
	char name[20];
	struct tree *root,*p;
	struct tree *temp;
	p = NULL;
	temp = NULL;
	root = NULL;
	for(i = 0;i<NUM;i++)
		root =construct(root,root,&Datas[i]);
	printf("������Ա���ϣ�\n");
	print(root);
	printf("������Ҫ���ҵ��˵�����\n");
	scanf("%s",name);
	p = Search(root,name);
	if(p == NULL)
	{
		printf("û�и�������\n");
		printf("�Ƿ�Ҫ�����������[y/n]\n");
		scanf("%s",c);
		if(strcmp(c,"y")==0)
		{
			temp = (struct tree *)malloc(sizeof(struct tree));
			if(!temp)
			{
				printf("�ڴ����ʧ�ܣ�");
				exit(0);
			}
			printf("���������������\n");
			scanf("%s",swap);
			strcpy(temp->name,swap);
			printf("������������ڳ��У�\n");
			scanf("%s",swap);
			strcpy(temp->city,swap);
			printf("����������Ա�[Male/Female]��\n");
			scanf("%s",swap);
			strcpy(temp->sex,swap);
			printf("������������䣺\n");
			scanf("%s",swap);
			strcpy(temp->age,swap);
			printf("��������˹�����\n");
			scanf("%s",swap);
			strcpy(temp->job,swap);
			temp->left = NULL;
			temp->right = NULL;
			root =construct(root,root,temp);
			print_currentData(temp);
			printf("������Ա���ϣ�\n");
			root = root;
			print(root);
		}
		else 
			return 0;
	}
	print_currentData(p);
	return 1;
}

