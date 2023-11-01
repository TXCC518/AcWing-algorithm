#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, cnt;     // cnt表示质数的个数
bool st[N];     // st中存储的是当前下标是否是质数，true表示是质数
int primes[N];

void get_primes()
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			primes[cnt++] = i;
		}
		for(int j = i; j <= n; j += i) st[j] = true;	// 不管是什么数，都把他的倍数筛掉
	}
}

int main()
{
	cin >> n; 
	get_primes();
	printf("%d\n", cnt);
}
