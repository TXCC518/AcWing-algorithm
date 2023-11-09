#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
struct Node
{
	int l;
	int r;
}a[N];
bool cmp(Node a, Node b)
{
	return a.l < b.l;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n;i ++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		a[i] = {l, r};
	}
	sort(a, a + n, cmp);
	priority_queue<int, vector<int>, greater<int>> pri;
	for(int i = 0; i < n;i ++)
	{
		if(pri.empty()) pri.push(a[i].r);
		else
		{
			int t = pri.top();
			if(t >= a[i].l) pri.push(a[i].r);
			else 
			{
				pri.pop();
				pri.push(a[i].r);
			}
		}
	}
	printf("%d\n", pri.size());
	
	return 0;
}
