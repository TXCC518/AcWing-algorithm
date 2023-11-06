#include <iostream>

using namespace std;

const int N = 1010;
char a[N];
char b[N];
int n, m;
int dp[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s%s", a + 1, b + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			if(a[i] == b[j])
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			}
		}
	}
	printf("%d\n", dp[n][m]);
	
	return 0;
}
