#include <iostream>

using namespace std;

int n, x, y;

int exgcd(int a, int m, int &x, int &y)
{
	if(!m)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(m, a % m, x, y);
	int t = y;
	y = x - a / m * y;
	x = t;
	
	return d;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int a, b, m;
		scanf("%d%d%d", &a, &b, &m);
		int d = exgcd(a, m, x, y);
		
		if(b % d) puts("impossible");
		else
		{
			int res = (long long)x * (b / d) % m;
			printf("%d\n", res);
		}
	}
	
	return 0;
}
