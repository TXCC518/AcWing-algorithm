#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULL;
ULL n, k;
vector<int> ans;

void def(ULL res, ULL k)
{
	if(res == 1)
	{
		ans.push_back(k ? 1 : 0);
		return;
	}
	
	if(k > res / 2)
	{
		ans.push_back(1);
		def(res / 2, res - k);
	}
	else
	{
		ans.push_back(0);
		def(res / 2, k);
	}
}

int main()
{
	scanf("%llu%llu", &n, &k);
	ULL res = 1;
	for(int i = 0; i < n; i++) res *= 2;
	res--;
	def(res, k);
	for(int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i]);
	}
	
	return 0;
}
