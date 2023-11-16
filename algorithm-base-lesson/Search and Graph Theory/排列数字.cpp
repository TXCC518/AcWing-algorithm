#include <iostream>

using namespace std;

const int N = 10;
int a[N];
bool st[N];
int n;

void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
		puts("");
		return;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(!st[i])
		{
			st[i] = true;
			a[u] = i;
			dfs(u + 1);
			st[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
}
