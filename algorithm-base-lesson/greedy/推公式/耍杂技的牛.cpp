#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;
int n;
pair<int, int> t[N];

int main()
{
	cin >> n;
	for(int i = 0;i < n;i ++)
	{
		int w, s;
		cin >> w >> s;
		t[i] = {w + s, w};
	}
	sort(t, t + n);
	int res = -0x3f3f3f3f;
	int sum = 0;
	for(int i = 0;i < n; i++)
	{
		int w = t[i].second, s = t[i].first - w;
		res = max(res, sum - s);
		sum += w;
	}
	
	cout << res << endl;
	
	return 0;
}
