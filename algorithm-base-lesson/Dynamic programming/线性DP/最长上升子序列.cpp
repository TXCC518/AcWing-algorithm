#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int q[N];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int len = 0;
	for(int i = 0; i < n; i++)
	{
		int l = 0, r = len + 1;
		q[0] = -2e9;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(q[mid] >= a[i]) r = mid;
			else l = mid + 1;
		}
		len = max(len, r);
		q[r] = a[i];
	}
	
	printf("%d\n", len);
	
	return 0;
}
