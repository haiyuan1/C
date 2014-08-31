#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 4

struct data
{
	char name[20];
	char school[20];
	char city[20];
	char province[20];
}info;

struct data addrs[NUM]=
{
	"WenHai","BIT","JiLin","JiLin",
	"TongWei","BIT","ZhengJiang","JiangSu",
	"SunYou","BIT","WeiFang","ShangDong",
	"XiaoMing","PKU","TaiYuan","ShanXi"

};
/*�Ժ���Ҫ�õ��ĺ�����������*/
void quick_disk(FILE *fp,int count);
void qs_disk(FILE *fp,int left,int right);
void exchangedata(FILE *fp,long i, long j);
char *get_name(FILE *fp, long rec);
void print_data(struct data *p);
struct data *get_data(FILE *fp,long rec);

int main(void)
{
	int i;
	FILE *fp;					/*�ļ�ָ��*/
	/*�Զ�д��ʽ�����ı��ļ�fp*/
	if((fp = fopen("datalist.txt","w+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(1);
	}
	printf("��δ���������д���ļ�\n");
	/*������Sdata[NUM]д���ļ���*/
	fwrite(addrs,sizeof(addrs),1,fp);
	/*���ļ��е�����Sdata[NUM]����ȡ������ӡ*/
	for(i=0;i<NUM;i++)
	{
		struct data *p;
		p = get_data(fp,i);		/*�õ�Sdata[i]��ָ��*/
		print_data(p);			/*���ṹ��Sdata[i]������Ա������ӡ��*/
		printf("\n");
	}

	fclose(fp);					/*�ر��ļ�ָ��*/
	/*�Զ����Ʒ�ʽ�ٴδ��ļ�datalist.txt*/
	if((fp=fopen("datalist.txt","rb+"))==NULL)
	{
		printf("�����Զ�д��ʽ���ļ�\n");
		exit(1);
	}

	printf("���ļ���������\n");
	/*�����ַ������������ı��е��ַ����ṹ������*/
	quick_disk(fp,NUM);			

	printf("�������\n");
	/*�������������������ݴ�ӡ����*/
	for(i=0;i<4;i++)
	{
		struct data *p;
		p = get_data(fp,i);
		print_data(p);
		printf("\n");
	}
	fclose(fp);

	return 0;
}
/*Ӧ�ÿ������򷽷����ַ�����������*/
void quick_disk(FILE *fp,int count)
{
	qs_disk(fp,0,count-1);
}
/*������*/
void qs_disk(FILE *fp,int left,int right)
{
	long int i,j;
	char x[30];
	i = left;
	j = right;
	/*�Ƚ��ַ���xΪSdata�����м�һ���ṹ������name��Ա����*/
	strcpy(x,get_name(fp,(long)(i+j)/2));
	do
	{	/*�Ƚϵ�ǰ�ṹ������name��Ա�����ڱȽ��ַ���x�Ĵ�С*/
		while((strcmp(get_name(fp,i),x)<0)&&(i<right))
			i++;
		while((strcmp(get_name(fp,j),x)>0)&&(j>left))
			j--;
		if(i<=j)
		{
			exchangedata(fp,i,j);		/*����i��j��Ӧ������*/
			i++;
			j--;
		}
	}while(i<j);

	if(left<j)					/*�������ô���������ֱ��j�ﵽ���ݵ������*/
		qs_disk(fp,left,(int)j);
	if(i<right)					/*�������ô���������ֱ��i�ﵽ���ݵ����Ҷ�*/
		qs_disk(fp,(int)i,right);
}
/*����i��j���ļ��ж�Ӧ������*/
void exchangedata(FILE *fp,long i,long j)
{
	char a[sizeof(info)],b[sizeof(info)];
	fseek(fp,sizeof(info)*i,SEEK_SET);		/*�ҵ�i���ļ��ж�Ӧ������λ��*/
	fread(a,sizeof(info),1,fp);				/*����λ�����ݶ����ַ�������a��*/

	fseek(fp,sizeof(info)*j,SEEK_SET);		/*�ҵ�j���ļ��ж�Ӧ������λ��*/
	fread(b,sizeof(info),1,fp);				/*����λ�����ݶ����ַ�������b��*/

	fseek(fp,sizeof(info)*j,SEEK_SET);		/*�ҵ�j���ļ��ж�Ӧ������λ��*/
	fwrite(a,sizeof(info),1,fp);			/*���ղŶ���a�е�����д�뵽��λ��*/
	fseek(fp,sizeof(info)*i,SEEK_SET);		/*�ҵ�i���ļ��ж�Ӧ������λ��*/
	fwrite(b,sizeof(info),1,fp);			/*���ղŶ���b�е�����д�뵽��λ��*/
	/*����ļ���i��j����Ӧ���ݵĽ���*/
}
/*�õ��ļ�fp�б���rec��Ӧ�Ľṹ�������name��Ա����*/
char *get_name(FILE *fp,long rec)
{
	struct data *p;
	p = &info;
	rewind(fp);
	/*�ҵ��ýṹ������õ�λ��*/
	fseek(fp,rec*sizeof(struct data),SEEK_SET);
	/*�������ָ��p*/
	fread(p,sizeof(struct data),1L,fp);
	return p->name;			/*���ظýṹ�������name��Ա����*/
}
/*�õ��ļ�fp�б���rec��Ӧ�Ľṹ�������ָ��*/
struct data *get_data(FILE *fp,long rec)
{
	struct data *p;
	p = &info;
	rewind(fp);
	/*�ҵ��ýṹ������õ�λ��*/
	fseek(fp,rec*sizeof(info),SEEK_SET);
	/*�������ָ��p*/
	fread(p,sizeof(info),1,fp);
	return p;				/*���ظýṹ��ָ��*/
}
/*��ָ��p��Ӧ�Ľṹ��ĸ�����Ա������ӡ����*/
void print_data(struct data *p)
{
	printf("������%s\n",p->name);
	printf("ѧУ��%s\n",p->school);
	printf("���У�%s\n",p->city);
	printf("ʡ  ��%s\n",p->province);
}

