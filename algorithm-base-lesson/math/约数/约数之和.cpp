#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

int n, a;

// 已知：x = p1^a * p2^b * p3^c
// 可得：约数之和 = (p1^0 + p1^1 + ... + p1^a) * (p2^0 + p2^1 + ... + p2^b) * ...

int main()
{
	scanf("%d", &n);
	unordered_map<int, int> map;
	
	while(n--)
	{
		scanf("%d", &a);
		for(int i = 2; i <= a / i; i++)
		{
			while(a % i == 0)
			{
				map[i]++;
				a /= i;
			}
		}
		if(a > 1) map[a]++;
	}
	LL res = 1;
	for(auto u : map)
	{
		LL t = 1;
		int num = u.second;
		while(num--)
		{
			t = (t * u.first + 1) % mod;
		}
		res = res * t % mod;
	}
	printf("%lld\n", res);
	
	return 0;
}
