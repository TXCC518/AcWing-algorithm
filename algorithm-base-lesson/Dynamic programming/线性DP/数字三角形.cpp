#include <iostream>

using namespace std;

const int N = 510;
int n;
int a[N][N];
int dp[N][N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= i + 1; j++) dp[i][j] = -0x3f3f3f3f;
	}
	dp[1][1] = a[1][1];
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
		}
	}
	int res = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
	{
		if(dp[n][i] > res) res = dp[n][i];
	}
	printf("%d\n", res);
	
	return 0;
}
