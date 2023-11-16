//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int N = 20;
//
//char a[N][N];
//bool col[N], dg[N], udg[N];
//int n;
//
//void dfs(int x)
//{
//	if(x == n)
//	{
//		for(int i = 0; i < n; i++)
//		{
//			for(int j = 0; j < n; j++)
//			{
//				printf("%c", a[i][j]);
//			}
//			puts("");
//		}
//		puts("");
//		return;
//	}
//	for(int i = 0;i < n;i ++)
//	{
//		if(!col[i] && !dg[i - x + n] && !udg[i + x])
//		{
//			a[x][i] = 'Q';
//			col[i] = dg[i-x+n] = udg[i+x] = true;
//			dfs(x + 1);
//			col[i] = dg[i-x+n] = udg[i+x] = false;
//			a[x][i] = '.';
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	memset(a, '.', sizeof a);
//	dfs(0);
//	
//	return 0;
//}

// 第二种方法，遍历每行每列，并记录当前放了多少个皇后
#include <iostream>
#include <cstring>

using namespace std;

const int N = 20;
int n;
char a[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int d)
{
	if(y == n) x++, y = 0;
	if(x == n)
	{
		if(d == n)
		{
			for(int i = 0;i < n; i++)
			{
				for(int j = 0; j < n; j++) printf("%c", a[i][j]);
				puts("");
			}
		}
		return;
	}
	// 不放皇后
	dfs(x, y + 1, d);
	// 放皇后
	if(!row[x] && !col[y] && !dg[y - x + n] && !udg[y + x])
	{
		a[x][y] = 'Q';
		row[x] = col[y] = dg[y-x+n] = udg[y+x] = true;
		dfs(x, y + 1, d + 1);
		row[x] = col[y] = dg[y-x+n] = udg[y+x] = false;
		a[x][y] = '.';
	}
}

int main()
{
	cin >> n;
	memset(a, '.', sizeof a);
	dfs(0, 0, 0);
	
	return 0;
}
