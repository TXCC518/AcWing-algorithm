#include <iostream>

using namespace std;

const int N = 12000;
int v[N], w[N];
int dp[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for(int i = 0; i < n; i++)
	{
		int a, b, s;
		scanf("%d%d%d", &a, &b, &s);
		int k = 1;
		while(k <= s)
		{
			v[cnt] = a * k;
			w[cnt] = b * k;
			cnt++;
			s -= k;
			k *= 2;
		}
		if(s) 
		{
			v[cnt] = a * s;
			w[cnt] = b * s;
			cnt++;
		}
	}
	n = cnt - 1;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= v[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	
	printf("%d\n", dp[m]);
	
	return 0;
}
