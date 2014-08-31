#include <stdio.h>
#include <stdlib.h>

struct tree
{
	char info;
	struct tree *left;
	struct tree *right;
};

struct tree *root;		/*���ĵ�һ�����*/
struct tree *construct(struct tree *root, struct tree *r, char info);
void print(struct tree *r, int l);

int main(void)
{
	char s[80];
	root = NULL;
	do
	{
		printf("������һ���ַ�:");
		gets(s);
		root = construct(root,root,*s);
	}while(*s);
	print(root,0);
	return 0;
}

struct tree *construct(
	struct tree *root, 
	struct tree *r, 
	char info)
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
		r->info = info;
		if(!root)
			return r;
		if(info < root->info)
			root->left = r;
		else 
			root->right = r;
		return r;
	}
	if(info < r->info)
		construct(r,r->left,info);
	else
		construct(r,r->right,info);

	return root;	
}

void print(struct tree *r, int l)
{
	int i;
	if(!r)
		return;
	print(r->left,l+1);
	for(i = 0;i < l;++i)
		printf(" ");
	printf("%c\n",r->info);
	print(r->right,l+1);
}

