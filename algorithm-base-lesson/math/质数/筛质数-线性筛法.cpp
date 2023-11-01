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
		if(!st[i]) primes[cnt++] = i;
		for(int j = 0; primes[j] <= n / i; j++)     // 终止条件：primes[j] <= n / i，因为i的最小质因数一定是    
			// 在primes当前保存中的
			// i为合数时，primes[j]为i的最小质因子时break
			// i为质数时，primes[i]就是i的最小质因子break
		{
			// 存在两种情况：
			// 1、i % primes[j] != 0：说明primes[j]小于i的最小质因数，primes[j]是自身的最小质因数，因此
			//    primes[j]是 i * primes[j] 的最小质因数
			// 2、i % primes[j] == 0：说明primes[j]是i的最小质因数，因为primes是递增的，因此primes[j]后面
			//    的数都是大于i的最小质因数，所以退出
			
			// 核心思想：每个合数都是被他的最小质因数筛去的，且每个合数的最小质因数只有一个
			st[primes[j] * i] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

int main()
{
	cin >> n; 
	get_primes();
	printf("%d\n", cnt);
}
