#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int a[N][N];
int d[N][N];
PII q[N*N];
int n, m;

int bfs()
{
	int hh = 0, tt = 0;
	q[tt] = {0, 0};
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	while(hh <= tt)
	{
		PII t = q[hh++];
		for(int i = 0; i< 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && d[x][y] == -1)
			{
				q[++tt] = {x, y};
				d[x][y] = d[t.first][t.second] + 1;
			}
		}
	}
	
	return d[n-1][m-1];
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i ++)
	{
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	cout << bfs() << endl;
	
	return 0;
}
