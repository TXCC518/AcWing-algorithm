#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;
int n, a;
int son[M][2], idx;

void insert(int u)
{
	int p = 0;
	for(int i = 30; i >= 0; i--)
	{
		int t = u >> i & 1;
		if(!son[p][t]) son[p][t] = ++idx;
		p = son[p][t];
	}
}

int find(int u)
{
	int p = 0;
	int sum = 0;
	for(int i = 30; i >= 0; i--)
	{
		int t = u >> i & 1;
		if(son[p][!t]) t = !t;
		sum = sum * 2 + t;
		p = son[p][t];
	}
	return sum;
}

int main()
{
	int res = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		insert(a);
		int t = find(a);
		res = max(res, t ^ a);
	}
	printf("%d\n", res);
	
	return 0;
}
