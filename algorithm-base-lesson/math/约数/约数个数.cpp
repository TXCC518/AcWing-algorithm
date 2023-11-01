#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long LL;
const LL t = 1e9 + 7;

// 已知： x = p1^a * p2^b * p3^c
// 可得 约数个数：(a + 1) * (b + 1) * (c + 1)
int n, a;

int main()
{
	scanf("%d", &n);
	unordered_map<int, int> res;
	while(n--)
	{
		scanf("%d", &a);
		for(int i = 2; i <= a / i; i++)
		{
			while(a % i == 0)
			{
				res[i]++;
				a /= i;
			}
		}
		if(a > 1) res[a]++;
	}
	LL sum = 1;
	for(auto map : res)
	{
		sum = sum * (map.second + 1) % t;
	}
	printf("%lld\n", sum);
	
	return 0;
}

