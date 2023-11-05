//#include <iostream>
//
//using namespace std;
//const int N = 1010;
//
//int w[N], v[N];
//int dp[N][N];
//int n, V;
//
//int main()
//{
//	scanf("%d%d", &n, &V);
//	for(int i = 1; i <= n; i ++) scanf("%d%d", &v[i], &w[i]);
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j <= V; j++)
//		{
//			if(j < v[i]) dp[i][j] = dp[i-1][j];
//			else dp[i][j] = max(dp[i-1][j-v[i]] + w[i], dp[i-1][j]);
//		}
//	}
//	
//	printf("%d\n", dp[n][V]);
//	
//	return 0;
//}

// 二维数组优化成一维数组
#include <iostream>

using namespace std;
const int N = 1010;

int n, V;
int w[N], v[N];
int dp[N];

int main()
{
	scanf("%d%d", &n, &V);
	for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = V; j >= v[i]; j--)
		{
			dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
		}
	}
	
	printf("%d\n", dp[V]);
	
	return 0;
}
