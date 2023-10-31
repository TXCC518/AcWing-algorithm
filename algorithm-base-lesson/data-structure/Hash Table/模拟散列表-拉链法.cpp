#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int h[N];
int e[N], ne[N], idx;
int n, x;

void insert(int u)
{
	int t = (u % N + N) % N;
	e[idx] = u;
	ne[idx] = h[t];
	h[t] = idx++;
}

bool find(int u)
{
	int t = (u % N + N) % N;
	for(int i = h[t]; i != -1; i = ne[i])
	{
		if(e[i] == u) return true;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	while(n--)
	{
		char op[2];
		scanf("%s%d", &op, &x);
		if(op[0] == 'I')
		{
			insert(x);
		}
		else
		{
			if(find(x)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}
