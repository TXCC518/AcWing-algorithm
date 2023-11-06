#include <iostream>

using namespace std;

const int N = 310;
int a[N];
int n;
int dp[N][N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) a[i] += a[i-1];
	for(int len = 1; len <= n; len ++)
	{
		for(int i = 1; i + len <= n; i++)
		{
			int l = i, r = i + len;
			dp[l][r] = 0x3f3f3f3f;
			for(int k = i; k < r; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + a[r] - a[l-1]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	
	return 0;
}
