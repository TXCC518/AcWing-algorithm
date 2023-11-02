#include <iostream>

using namespace std;

int n, a, b;

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d", &a, &b);
		int res = gcd(a, b);
		printf("%d\n", res);
	}
	
	return 0;
}
