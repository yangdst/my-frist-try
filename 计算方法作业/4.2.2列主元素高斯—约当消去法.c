/**************************************************
	4.2.2列主元素高斯—约当消去法
				——P76
***************************************************/

#include<stdio.h>
#include<math.h>
#define ZZ 5
int main()
{
	float A[ZZ][ZZ + 1] = { {0,1,1,1}, {1,2,3,0}, {1,4,6,2} };//fangbianceshi
	float  temp;
	int N=3, i, j , k, r;
	/*可以注释到16到25行，则是课本例4.2.7，
	答案为-2、1、0			*/
	printf("请输入方程组中方程的个数:\n");
	scanf("%d", &N);
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
			printf("  %10.6f  ", A[i][j]);
		printf("\n");
	}

	//高斯-约当主要算法
	for (k = 0; k<N ; k++)
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

	printf("\n列主元素高斯-约当消元后的结果为:\n");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N + 1; j++)
			printf("  %10.6f  ", A[i][j]);
		printf("\n");
	}

	//输出结果
	printf("\n求得方程组的解:\n");
	for (i = 0; i<N; i++)
		printf("x%d=%f\n", i + 1, A[i][N]);
}
