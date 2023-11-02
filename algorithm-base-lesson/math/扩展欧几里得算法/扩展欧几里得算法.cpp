#include <iostream>

using namespace std;

int n;
int x, y;

int exgcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int t = y;
	y = x - a / b * y;
	x = t;
	
	return d;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int d = exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
