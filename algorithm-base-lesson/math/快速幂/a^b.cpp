#include <iostream>

using namespace std;
typedef long long LL;

int n, b, p;

int qmi(int a, int k, int p)
{
	int res = 1;
	while(k)
	{
		if(k & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		k >>= 1;
	}
	
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &b, &p);
	int res = qmi(n, b, p);
	
	printf("%d\n", res);
	
	return 0;
}
