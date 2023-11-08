#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int happy[N];
int n;
int e[N], ne[N], idx;
int h[N];
bool is_sir[N];
int dp[N][2];

void add(int a, int b)
{
	e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}

void dfs(int u)
{
	dp[u][1] = happy[u];
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int x = e[i];
		dfs(x);
		dp[u][0] += max(dp[x][0], dp[x][1]);
		dp[u][1] += dp[x][0];
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &happy[i]);
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		is_sir[a] = true;
		add(a, b);
	}
	int root = 1;
	while(is_sir[root])
	{
		root++;
	}
	dfs(root);
	printf("%d\n", max(dp[root][0], dp[root][1]));
	
	return 0;
}
