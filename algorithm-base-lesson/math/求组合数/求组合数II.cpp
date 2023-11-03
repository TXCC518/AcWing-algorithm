#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10, mod = 1e9 + 7;
LL fact[N], infact[N];
int n;

int qmi(int a, int b)
{
	LL res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	scanf("%d", &n);
	fact[0] = infact[0] = 1;
	for(int i = 1; i < N; i++)
	{
		fact[i] = i * fact[i-1] % mod;
		infact[i] = infact[i-1] * qmi(i, mod-2) % mod;
	}
	while(n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", fact[a] * infact[a-b] % mod * infact[b] % mod);
	}
	
	return 0;
}
