#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define NUM 4

struct Data
{
	char name[20];
	char city[20];
	char sex[10];
	char age[10];
	char job[10];
};

struct Data SDatas[NUM]=
{
	"Sun","Weifang","Male","24","student",
	"Tom","Beijing","Male","31","doctor",
	"Marry","Shanghai","Female","19","techer",
	"Willing","Tianjing","Female","21","worker"
};

void qs_struct(items,left,right);
void quick_struct(items,count);
int BinarySeach(items,name,n);
void print_data(point);

int main(void)
{
	char name[30];
	int i; 
	printf("��ԭʼ��������\n");
	quick_struct(SDatas,NUM);
	printf("������Ҫ�����˵����֣�\n");
	scanf("%s",name);
	i = BinarySeach(SDatas,name,NUM);
	if(i == -1)
	{
		printf("û�в��ҵ�������Ϣ\n");
		return 0;
	}
	printf("���ҽ����\n");
	print_data(&SDatas[i]);
	return 1;
}


void quick_struct(items,count)
struct Data items[];
int count;
{
	qs_struct(items,0,count-1);
}

void qs_struct(items,left,right)
struct Data items[];
int left;
int right;
{
	register int i,j;
	char *x;
	struct Data temp;
	i = left;
	j = right;
	x = items[(left+right/2)].name;
	do
	{
		while((strcmp(items[i].name,x)<0)&&(i<right))
			i++;
		while((strcmp(items[j].name,x)>0)&&(j>left))
			j--;
		if(i<=j)
		{
			temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j)
		qs_struct(items,left,j);
	if(i<right)
		qs_struct(items,i,right);
}

int BinarySeach(items,name,n)
struct Data items[];
char name[];
int n;
{
	int low,high,mid;
	low = 0;
	high = n-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if((strcmp(items[mid].name,name)==0))
			return mid;
		else if((strcmp(items[mid].name,name)<0))
			low = mid+1;
		else high = mid-1;
	}
	return -1;
}

void print_data(point)
struct Data *point;
{
	if(point ==NULL)
		return;
	printf("	������%s\n",point->name);
	printf("	���У�%s\n",point->city);
	printf("	�Ա�%s\n",point->sex);
	printf("	���䣺%s\n",point->age);
	printf("	������%s\n",point->job);
}