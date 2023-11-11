#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, s, t;

struct Node
{
	int l, r;
}ans[N];

bool cmp(Node a, Node b)
{
	return a.l < b.l;
}

int main()
{
	scanf("%d%d%d", &s, &t, &n);
	for(int i = 0;i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		ans[i] = {l, r};
	}
	sort(ans, ans + n, cmp);
	int res = 0;
	bool tmp = false;
	for(int i = 0;i < n; i++)
	{
		int end = -0x3f3f3f3f;
		while(i < n && ans[i].l <= s)
		{
			end = max(end, ans[i].r);
			i++;
		}
		if(end < s)
		{
			res = -1;
			break;
		}
		res++;
		s = end;
		if(s >= t)
		{
			tmp = true;
			break;
		}
		i--;
	}
	if(!tmp) res = -1;
	printf("%d\n", res);
	
	return 0;
}
