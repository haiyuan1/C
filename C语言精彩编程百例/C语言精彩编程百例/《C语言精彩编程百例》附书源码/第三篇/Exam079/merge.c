#include <stdio.h>

void Mpass(int x[],int y[],int k,int n);	/*������Ϊ����*/
void Msort(int x[],int y[],int n);			/*������Ϊ����*/

int main(void)
{
	/*Ҫ����������������*/
	int a[] = {26,5,37,1,61,11,59,15,48,19};
	int y[10];				/*������ʱ�洢����*/
	int i;
	printf("Դ����Ϊ��	   ");	/*��Դ���ݴ�ӡ����*/
	for(i = 0;i<10;i++)
	printf("[%2d]",a[i]);
	Msort(a,y,10);		/*��Դ���ݽ��кϲ�����*/
	printf("\n����������Ϊ:  ");
	for(i = 0;i<10;i++)			/*����������ӡ����*/
	printf("%4d",a[i]);
	printf("\n");
	return 0;
}

void Mpass(x,y,k,n)
int x[];					/*Ҫ���������*/
int y[];					/*���ڴ洢��ʱ���ݵ�����*/
int k;				/*��ʾ��ǰ�����������ɳ���Ϊk��������������*/
int n;				/*Ҫ�������еĳ���Ϊn*/
	
{
	int i,j;
	int	strat1,end1;	/*��Ӧ��һ������������L1��ʼ����ֹλ�ú�*/
	int	strat2,end2;	/*��Ӧ�ڶ�������������L2��ʼ����ֹλ�ú�*/
	int	m;				/*��ʾ����y�е�ǰ��¼Ӧ���õ�λ�ú�*/
	strat1 = 0;
	m = 0;
	while(strat1+k<=n-1)		/*����һ��������û��ռ������x����*/
	{
		strat2 = strat1+k;		/*Ϊ����������������ʼ��ֹλ�úŸ�ֵ*/
		end1 = strat2-1;
		/*����ڶ��������г��Ȳ���k��������ֹλ�ú�Ϊn-1*/
		end2 = (strat2+k-1<=n-1)?strat2+k-1:n-1;
		for(i = strat1,j = strat2;i<=end1&&j<=end2;m++)
		{
			if(x[i]<=x[j])
			{
				y[m] = x[i];
				i++;
			}
			else
			{
				y[m] = x[j];
				j++;
			}
		}
		while(i<= end1)
		{
			y[m] = x[i];
			m++;
			i++;
		}
		while(j<= end2)
		{
			y[m] = x[j];
			m++;
			j++;
		}
		strat1 = end2+1;
	}
	/*����һ��������ʣ������м�¼���ηŵ�����y��*/
	for(i=strat1;i<n;i++,m++)		
		y[m] = x[i];
}

void Msort(x,y,n)
int x[];			/*Ҫ���������*/
int y[];			/*���ڴ洢��ʱ���ݵ�����*/
int n;				/*���鳤��*/
{
	int i,k,count;
	k = 1;
	count = 1;
	while(k<n)				/*�������б���������Сʱ*/
	{
		Mpass(x,y,k,n);		/*�鲢������������*/	
		for(i= 0;i<n;i++)
			x[i] = y[i];	/*��������*/
		printf("\n��%2d����Ľ��==>  ",count++);
			for(i = 1;i<n+1;i++)
		{
			if((i ==n)&&((i%(2*k)!=0)))
				printf("%4d]",x[i-1]);
			else
			{
				if((i%(2*k)==1))
					printf("[%2d",x[i-1]);
				else if((i%(2*k))==0)
					printf("%4d]",x[i-1]);
				else
					printf("%4d",x[i-1]);
			}
		}
		k = 2*k;		/*һ�ι鲢���µ����������еĳ���*/
	}
}



