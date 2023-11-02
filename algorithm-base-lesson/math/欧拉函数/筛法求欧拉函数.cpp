#include <iostream>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
int primes[N], oula[N];
bool st[N];
int n, cnt;

int main()
{
	scanf("%d", &n);
	oula[1] = 1;
	LL res = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) 
		{
			primes[cnt++] = i;
			oula[i] = i-1;
			res += oula[i];
		}
		for(int j = 0; primes[j] <= n / i; j++)
		{
			int t = primes[j] * i;
			st[t] = true;
			if(i % primes[j] == 0)
			{
				oula[t] = oula[i] * primes[j];
				res += oula[t];
				break;
			}
			oula[t] = oula[i] * (primes[j] - 1);
			res += oula[t];
		}
	}
	printf("%lld\n", res);
	
	return 0;
}
