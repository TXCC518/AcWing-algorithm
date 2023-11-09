#include <iostream>
#include <algorithm>

using namespace std;

using namespace std;
const int N = 1e5 + 10;

int n;
struct Node
{
	int l;
	int r;
}node[N];

bool cmp(Node a, Node b)
{
	return a.r < b.r;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0;i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		node[i] = {l, r};
	}
	sort(node, node + n, cmp);
	int res = 0;
	int tmp = -0x3f3f3f3f;
	for(int i = 0; i < n;i ++)
	{
		if(node[i].l > tmp)
		{
			res++;
			tmp = node[i].r;
		}
	}
	
	printf("%d\n", res);
	
	return 0;
	
}
