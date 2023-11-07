// 状态表示
// dp[i][j] = dp[i-1][j] + dp[i][j-i]

//#include <iostream>
//
//using namespace std;
//
//const int N = 1010, mod = 1e9 + 7;
//
//int n;
//int dp[N][N];
//
//int main()
//{
//	scanf("%d", &n);
//	dp[0][0] = 1;
//	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j <= n; j++)
//		{
//			dp[i][j] = dp[i-1][j];
//			for(int k = 1; k * i <= j; k++)
//			{
//				dp[i][j] = (dp[i][j] + dp[i-1][j-k * i]) % mod;
//			}
//		}
//	}
//	
//	printf("%d\n", dp[n][n]);
//	
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//const int N = 1010, mod = 1e9 + 7;
//
//int n;
//int dp[N][N];
//
//int main()
//{
//	scanf("%d", &n);
//	dp[0][0] = 1;
//	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 0; j <= n; j++)
//		{
//			if(j < i) dp[i][j] = dp[i-1][j] % mod;
//			else dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % mod;
//		}
//	}
//	
//	printf("%d\n", dp[n][n]);
//	
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//const int N = 1010, mod = 1e9 + 7;
//
//int n;
//int dp[N];
//
//int main()
//{
//	scanf("%d", &n);
//	dp[0] = 1;
//	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = i; j <= n; j++)
//		{
//			dp[j] = (dp[j] + dp[j-i]) % mod;
//		}
//	}
//	
//	printf("%d\n", dp[n]);
//	
//	return 0;
//}

// 另一种状态表示
// dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int dp[N][N];

int main()
{
	scanf("%d", &n);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i-1][j-1] + dp[i-j][j]) % mod;
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res = (res + dp[n][i]) % mod;
	
	printf("%d\n", res);
	
	return 0;
}
