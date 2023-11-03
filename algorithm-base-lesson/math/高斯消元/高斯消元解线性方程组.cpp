#include <iostream>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-8;
double res[N][N];
int n;

int goous()
{
	int c, r;
	for(c = 0, r = 0; c < n;c++)
	{
		int l = r;
		// 找到当前列中绝对值最大的数，将绝对值最大的数所在的行与当前行互换
		for(int i = r; i < n; i++)
		{
			if(fabs(res[i][c]) > fabs(res[l][c]))
			{
				l = i;
			}
		}
		if(fabs(res[l][c]) < eps) continue;
		for(int i = c; i <= n; i++) swap(res[l][i], res[r][i]);
		// 将当前行的第一个参数修改为1
		for(int i = n; i >= c; i--) res[r][i] /= res[r][c];
		// 将当前行往后的每一行的当前列参数修改为0
		for(int i = r + 1; i < n; i++)
		{
			if(fabs(res[i][c]) > eps)
			{
				for(int j = n; j >= c; j--) res[i][j] -= res[r][j] * res[i][c];
			}
		}
		r++;
	}
	if(r < n)
	{
		// 如果剩余的表达式中，出现 0 = res[i][n]，则没有解，反之有无穷多个解
		for(int i = r; i < n; i++)
		{
			if(fabs(res[i][n]) > eps) return 2;
		}
		return 1;
	}
	// 在最后一行中，xn直接等于res[n-1][n]
	// 从倒数第二行往前遍历，每次减去当前表达式除了要求的x的其他部分
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = i + 1; j < n; j++) res[i][n] -= res[i][j] * res[j][n];
	}
	
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{   
			scanf("%lf", &res[i][j]);
		}
	}
	int r = goous();
	if(r == 2) puts("No solution");
	else if(r == 1) puts("Infinite group solutions");
	else
	{
		for(int i = 0; i < n; i++)
		{
			printf("%.2lf\n", res[i][n]);
		}
	}
	
	return 0;
}
