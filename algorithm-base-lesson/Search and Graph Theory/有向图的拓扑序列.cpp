#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx;
int q[N];
int in[N];
int n, m;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	in[b]++;
}

void bfs()
{
	int hh = 0, tt = -1;
	for(int i = 1;i <= n; i++)
	{
		if(in[i] == 0) q[++tt] = i;
	}
	while(hh <= tt)
	{
		int t = q[hh++];
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			in[j]--;
			if(in[j] == 0) q[++tt] = j;
		}
	}
	if(tt != n - 1) cout << -1 << endl;
	else 
	{
		for(int i = 0; i <= tt; i++)
		{
			cout << q[i] << " ";
		}
		puts("");
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0;i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	bfs();
	
	return 0;
}
