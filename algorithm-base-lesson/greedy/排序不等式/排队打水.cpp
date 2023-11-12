#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
int a[N];
LL res;
int n;

int main()
{
	cin >> n;
	for(int i = 0;i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for(int i = 0;i < n; i++)
	{
		res += a[i] * (n - i - 1);
	}
	
	cout << res << endl;
	
	return 0;
}
