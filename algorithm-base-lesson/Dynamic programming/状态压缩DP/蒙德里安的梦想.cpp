#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
bool st[M];		// 表示当前状态是否有偶数个连续的0
vector<int> state[M];
long long dp[N][M];

int main()
{
	while(cin >> n >> m, n || m)
	{
		// 预处理1：判断每一种状态是否有偶数个连续的0
		for(int i = 0;i < (1 << n); i++)
		{
			bool isValid = true;
			int cnt = 0;
			for(int j = 0; j < n; j++)
			{
				if((i >> j) & 1) 
				{
					if(cnt & 1)
					{
						isValid = false;
						break;
					}
					cnt = 0;
				}
				else cnt++;
			}
			if(cnt & 1) isValid = false;
			st[i] = isValid;
		}
		
		// 预处理2：每一个状态可以被哪些状态转移过来
		for(int i = 0; i < (1 << n); i++)
		{
			state[i].clear();
			for(int j = 0; j < (1 << n); j++)
			{
				if((i & j) == 0 && st[i | j])
				{
					state[i].push_back(j);
				}
			}
		}
		
		// 正式开始DP
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j < (1 << n); j++)
			{
				for(auto k : state[j])
				{
					dp[i][j] += dp[i-1][k];
				}
			}
		}
		
		cout << dp[m][0] << endl;
		
	}
	
	return 0;
}
