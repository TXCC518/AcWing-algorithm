//#include <iostream>
//
//using namespace std;
//
//const int N = 1010;
//int n, m;
//int v[N], w[N];
//int dp[N][N];
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j <= m; j++)
//		{
//			if(j < v[i]) dp[i][j] = dp[i-1][j];
//			for(int k = 0; j >= k * v[i]; k++)
//			{
//				dp[i][j] = max(dp[i][j], dp[i-1][j - k * v[i]] + k * w[i]);
//			}
//		}
//	}
//	printf("%d\n", dp[n][m]);
//	
//	return 0;
//}

// 优化成二维
//#include <iostream>
//
//using namespace std;
//
//const int N = 1010;
//int n, m;
//int v[N], w[N];
//int dp[N][N];
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j <= m; j++)
//		{
//			if(j < v[i]) dp[i][j] = dp[i-1][j];
//			else dp[i][j] = max(dp[i-1][j], dp[i][j-v[i]] + w[i]);
//		}
//	}
//	printf("%d\n", dp[n][m]);
//	
//	return 0;
//}

// 优化成一维
#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int dp[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = v[i]; j <= m; j++)
		{
			dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
		}
	}
	printf("%d\n", dp[m]);
	
	return 0;
}
