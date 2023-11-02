#include <iostream>

using namespace std;

typedef long long LL;

int n;

LL qmi(int a, int b, int p)
{
	LL res = 1;
	LL t = a;
	while(b)
	{
		if(b & 1)
		{
			res = res * t % p;
		}
		t = t * t % p;
		b = b >> 1;
	}
	
	return res;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		int res = qmi(a, b, p);
		
		printf("%lld\n", res);
	}
	
	return 0;
}
