#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e9 + 7;

int n;

int qmi(int a, int k)
{
	int res = 1;
	while(k)
	{
		if(k & 1) res = (LL)res * a % N;
		a = (LL)a * a % N;
		k >>= 1;
	}
	
	return res;
}

int C(int a, int b)
{
	int res = 1;
	for(int i = a; i > a - b; i--) res = (LL)res * i % N;
	for(int i = 1; i <= b; i++) res = (LL)res * qmi(i, N-2) % N;
	
	return res;
}

int main()
{
	scanf("%d", &n);
	int res = (LL)C(2 * n, n) * qmi(n+1, N - 2) % N;
	printf("%d", res);
	
	return 0;
}
