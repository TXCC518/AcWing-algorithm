#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, int> un;
queue<string> q;

int bfs(string start)
{
	string end = "12345678x";
	q.push(start);
	un[start] = 0;
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	while(q.size())
	{
		string t = q.front();
		q.pop();
		int distance = un[t];
		if(t == end) return distance;
		int idx = t.find('x');
		int x = idx / 3, y = idx % 3;
		for(int i = 0;i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[idx], t[a * 3 + b]);
				if(!un.count(t))
				{
					un[t] = distance + 1;
					q.push(t);
				}
				swap(t[idx], t[a * 3 + b]);
			}
		}
	}
	return -1;
}

int main()
{
	string start;
	for(int i = 0;i < 9; i++)
	{
		char c;
		cin >> c;
		start += c;
	}
	cout << bfs(start) <<endl;
	
	return 0;
}
