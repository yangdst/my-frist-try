/**************************************************
	4.2.2����Ԫ�ظ�˹��Լ����ȥ��
				����P76
***************************************************/

#include<stdio.h>
#include<math.h>
#define ZZ 5
int main()
{
	float A[ZZ][ZZ + 1] = { {0,1,1,1}, {1,2,3,0}, {1,4,6,2} };//fangbianceshi
	float  temp;
	int N=3, i, j , k, r;
	/*����ע�͵�16��25�У����ǿα���4.2.7��
	��Ϊ-2��1��0			*/
	printf("�����뷽�����з��̵ĸ���:\n");
	scanf("%d", &N);
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
			printf("  %10.6f  ", A[i][j]);
		printf("\n");
	}

	//��˹-Լ����Ҫ�㷨
	for (k = 0; k<N ; k++)
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
		else
		if (r > k)
		{
			for (j = k; j <=N; j++)		
			{
				temp = A[k][j];
				A[k][j] = A[r][j];
				A[r][j] = temp;
			}
			for (j = k+1 ; j <= N; j++)
				A[k][j] = A[k][j] / A[k][k];

			for (i = 0; i < N; i++)
			{
				if (i != k)
				{
					for (j = k+1 ; j <= N ; j++)
					{
						A[i][j] = A[i][j]-A[k][j]*A[i][k];
					}
				}
			}
		}
	}

	printf("\n����Ԫ�ظ�˹-Լ����Ԫ��Ľ��Ϊ:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("  %10.6f  ", A[i][j]);
		printf("\n");
	}

	//������
	printf("\n��÷�����Ľ�:\n");
	for (i = 0; i<N; i++)
		printf("x%d=%f\n", i + 1, A[i][N]);
}
