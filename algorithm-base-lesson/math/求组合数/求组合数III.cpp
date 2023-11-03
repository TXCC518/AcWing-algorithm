#include <iostream>

using namespace std;
typedef long long LL;
int n;

int qmi(int a, int k, int p)
{
	int res = 1;
	while(k)
	{
		if(k & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		k >>= 1;
	}
	return res ;
}

int C(int a, int b, int p)
{
	int res = 1;
	for(int i = a; i > a - b; i--)
	{
		res = (LL)res * i % p;
	}
	for(int i = 1; i <= b; i++)
	{
		res = (LL)res * qmi(i, p - 2, p) % p;
	}
	
	return res;
}

int lucas(LL a, LL b, LL p)
{
	if(a < p && b < p) return C(a, b, p);
	else return (LL)lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		LL a, b, p;
		scanf("%lld%lld%lld", &a, &b, &p);
		int res = lucas(a, b, p);
		printf("%d\n", res);
	}
	
	return 0;
}
