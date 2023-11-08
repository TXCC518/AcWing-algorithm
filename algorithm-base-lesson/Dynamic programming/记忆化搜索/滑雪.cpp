#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;
int n, m;
int h[N][N];
int dp[N][N];

int ax[4] = {-1, 0, 1, 0}, by[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 1;
	for(int i = 0; i < 4; i++)
	{
		int a = x + ax[i], b = y + by[i];
		if(a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
		{
			dp[x][y] = max(dp[x][y], dfs(a, b) + 1);
		}
	}
	
	return dp[x][y];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j++) scanf("%d", &h[i][j]);
	memset(dp, -1, sizeof h);
	int res = 0;
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			res = max(res, dfs(i, j));
		}
	}
	
	printf("%d\n", res);
	
	return 0;
}
