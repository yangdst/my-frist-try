/**************************************************
		4.2.1����Ԫ�ظ�˹��ȥ��
				����P74
***************************************************/
#include<stdio.h>
#include<math.h>
#define ZZ 8

int main()
{
	float A[ZZ][ZZ + 1] = { { 12, -3, 3, 15 }, { -18, 3, -1, -15 }, {1,1,1,6} };//Ϊ�˷�����ԣ�ֱ�Ӹ��˳�ֵ
	float temp,x[ZZ];
	int N=3 ,i , j , k, r;
	/*����ע�͵�15��24�У����ǿα���4.2.5
		��Ϊ1��2��3.			*/
	printf("�����뷽�����з��̵ĸ���:\n");
	scanf("%d",&N);
	printf("�����뷽�����з��̵�ϵ��:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			scanf("%f", &A[i][j]);
		}
	}

	printf("\n��������������Ϊ:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("%15.10f  ", A[i][j]);
		printf("\n");
	}
	//����Ԫ�ظ�˹��ȥ����Ҫ�㷨
	for(k = 0; k<N - 1; k++)   
	{
		r = k;               //����кŸ���r
		for (i = k + 1; i<N; i++)
		{
			if (fabs(A[i][k])>fabs(A[r][k]))
				r = i;
		}
		if (A[r][k] == 0)
		{
			printf("\n�������ϵ������Ϊ�������\n");
			break;
		}

		if (r > k) //������
		{
			for (j = k ; j <= N; j++)
			{
				temp = A[k][j];
				A[k][j] = A[r][j];
				A[r][j] = temp;
			}
		}
		for (i = k + 1; i<N; i++)
		{
			A[i][k] = A[i][k] / A[k][k];
			for (j=k + 1; j<=N; j++)
			{
				A[i][j] = A[i][j] - A[i][k] * A[k][j];
			}
		}
	}

	printf("\n����Ԫ�ظ�˹��Ԫ��Ľ��Ϊ:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("%15.10f  ", A[i][j]);
		printf("\n");
	}
	//�ش�����
	x[N - 1] = A[N - 1][N] / A[N - 1][N - 1];
	for (i = N - 2; i >= 0; i--)
	{
		temp = A[i][N];
		for (j = N - 1; j>i; j--)
			temp = temp - x[j] * A[i][j];
		x[i] = temp / A[i][i];
	}
	printf("\n��÷�����Ľ�:\n");
	for (i = 0; i<N; i++)
		printf("x%d=%f\n", i+1 ,x[i]);

}
