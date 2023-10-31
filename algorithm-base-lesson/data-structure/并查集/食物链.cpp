#include <iostream>

using namespace std;

const int N = 5e4 + 10;
int q[N], len[N];
int n, k;

int find(int u)
{
	if(q[u] != u)
	{
		int t = find(q[u]);
		len[u] += len[q[u]];
		q[u] = t;
	}
	return q[u];
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) q[i] = i;
	int res = 0;
	while(k--)
	{
		int d, x, y;
		scanf("%d%d%d", &d, &x, &y);
		int qx = find(x), qy = find(y);
		if(x > n || y > n) res++;
		else
		{
			if(d == 1)
			{
				if(qx == qy && (len[x] - len[y]) % 3) res++;
				else if(qx != qy)
				{
					q[qx] = qy;
					len[qx] = len[y] - len[x];
				}
			}
			else
			{
				if(qx == qy && (len[x] - len[y] - 1) % 3) res++;
				else if(qx != qy)
				{
					len[qx] = len[y] - len[x] + 1;
					q[qx] = qy;
				}
			}
		}
	}
	printf("%d\n", res);
}
