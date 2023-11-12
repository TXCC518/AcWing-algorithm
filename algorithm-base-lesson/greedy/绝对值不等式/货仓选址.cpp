#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int n;
int a[N];

int main()
{
	cin >> n;
	for(int i = 0;i < n; i++) cin >> a[i];
	sort(a, a + n);
	LL res = 0;
	int l = 0, r = n - 1;
	while(l < r)
	{
		res += a[r--] - a[l++];
	}
	cout << res << endl;
	
	return 0;
}
