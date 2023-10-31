#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 3, M = 0x3f3f3f3f;
int h[N];
int n, x;

int find(int u)
{
	int t = (u % N + N) % N;
	while(h[t] != M && h[t] != u)
	{
		t++;
		if(t == N) t = 0;
	}
	return t;
}

int main()
{
	scanf("%d", &n);
	memset(h, 0x3f, sizeof h);
	while(n--)
	{
		char op[2];
		scanf("%s%d", &op, &x);
		if(op[0] == 'I')
		{
			int t = find(x);
			h[t] = x;
		}
		else
		{
			int t = find(x);
			if(h[t] == x) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}
