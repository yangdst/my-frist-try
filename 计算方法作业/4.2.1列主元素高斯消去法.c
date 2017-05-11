/**************************************************
		4.2.1列主元素高斯消去法
				——P74
***************************************************/
#include<stdio.h>
#include<math.h>
#define ZZ 8

int main()
{
	float A[ZZ][ZZ + 1] = { { 12, -3, 3, 15 }, { -18, 3, -1, -15 }, {1,1,1,6} };//为了方便测试，直接赋了初值
	float temp,x[ZZ];
	int N=3 ,i , j , k, r;
	/*可以注释到15到24行，则是课本例4.2.5
		答案为1、2、3.			*/
	printf("请输入方程组中方程的个数:\n");
	scanf("%d",&N);
	printf("请输入方程组中方程的系数:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			scanf("%f", &A[i][j]);
		}
	}

	printf("\n方程组的增广矩阵为:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("%15.10f  ", A[i][j]);
		printf("\n");
	}
	//列主元素高斯消去法主要算法
	for(k = 0; k<N - 1; k++)   
	{
		r = k;               //最大行号赋给r
		for (i = k + 1; i<N; i++)
		{
			if (fabs(A[i][k])>fabs(A[r][k]))
				r = i;
		}
		if (A[r][k] == 0)
		{
			printf("\n方程组的系数矩阵为奇异矩阵！\n");
			break;
		}

		if (r > k) //交换行
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

	printf("\n列主元素高斯消元后的结果为:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("%15.10f  ", A[i][j]);
		printf("\n");
	}
	//回代过程
	x[N - 1] = A[N - 1][N] / A[N - 1][N - 1];
	for (i = N - 2; i >= 0; i--)
	{
		temp = A[i][N];
		for (j = N - 1; j>i; j--)
			temp = temp - x[j] * A[i][j];
		x[i] = temp / A[i][i];
	}
	printf("\n求得方程组的解:\n");
	for (i = 0; i<N; i++)
		printf("x%d=%f\n", i+1 ,x[i]);

}
