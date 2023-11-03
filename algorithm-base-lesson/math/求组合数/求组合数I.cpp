#include <iostream>

const int N = 2010, mod = 1e9 + 7;
int n, a, b;
int res[N][N];

void solve()
{
	for(int i = 0; i < N;i ++)
	{
		for(int j = 0; j <= i ;j++)
		{
			if(j == 0) res[i][j] = 1;
			else res[i][j] = (res[i-1][j] + res[i-1][j-1]) % mod;
		}
	}
}

int main()
{
	scanf("%d", &n);
	solve();
	while(n--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", res[a][b]);
	}
	
	return 0;
}
