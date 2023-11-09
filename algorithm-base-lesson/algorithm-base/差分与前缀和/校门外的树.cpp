#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010;

int ans[N];
int l, m;

void add(int ll, int rr, int d)
{
	ans[ll] += d;
	ans[rr + 1] -= d;
}

int main()
{
	scanf("%d%d", &l, &m);
	for(int i = 0; i <= l; i++) add(i, i, 1);
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b, -1);
	}
	for(int i = 1; i <= l; i++) ans[i] += ans[i-1];
	int res = 0;
	for(int i = 0;i <= l; i++)
	{
		if(ans[i] == 1) res++;
	}
	printf("%d\n", res);
	
	return 0;
}

//https://ac.nowcoder.com/acm/problem/16649
