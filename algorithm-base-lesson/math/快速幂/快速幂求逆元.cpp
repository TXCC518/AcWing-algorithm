#include <iostream>

using namespace std;

typedef long long LL;
int n;

LL qmi(int a, int b, int q)
{
	LL res = 1;
	while(b)
	{
		if(b & 1)
		{
			res = res * a % q;
		}
		a = (LL)a * a % q;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int a, p;
		scanf("%d%d", &a, &p);
		LL res = qmi(a, p-2, p);
		
		if(a % p == 0) puts("impossible");
		else printf("%lld\n", res);
	}
	
	return 0;
}
