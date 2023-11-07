#include <iostream>
#include <string.h>

using namespace std;

const int N = 15, M = 1010;
char str[M][N];
int n, m;

int edit_distance(char a[], char b[])
{
	int dp[N][N];
	int la = strlen(a + 1), lb = strlen(b + 1);
	for(int i = 0; i <= la; i++) dp[i][0] = i;
	for(int i = 0; i <= lb; i++) dp[0][i] = i;
	for(int i = 1;i <= la; i++)
	{
		for(int j = 1; j <= lb; j++)
		{
			dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
			dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i] != b[j]));
		}
	}
	
	return dp[la][lb];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	while(m--)
	{
		char tmp[N];
		int num;
		scanf("%s%d", tmp + 1, &num);
		int res = 0;
		for(int i = 0; i < n; i++)
		{
			if(edit_distance(str[i], tmp) <= num) res++;
		}
		printf("%d\n", res);
	}
	
	return 0;
}
