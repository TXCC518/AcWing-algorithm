#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int P = 131, N = 1e6 + 10;
ULL h[N], cnt[N];

ULL find(int l, int r)
{
	return h[r] - h[l-1] * cnt[r - l + 1];
}

int main()
{
	string s;
	int m;
	cin >> s >> m;
	cnt[0] = 1;
	for(int i = 1; i <= s.size(); i++)
	{
		h[i] = h[i-1] * P + s[i-1] - 'a' + 1;	
		cnt[i] = cnt[i - 1] * P;
	}
	while(m --)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if(find(l1, r1) == find(l2, r2)) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
