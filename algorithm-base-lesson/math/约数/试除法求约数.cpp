#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		vector<int> res;
		int x;
		scanf("%d", &x);
		for(int i = 1; i <= x / i; i++)
		{
			if(x % i == 0)
			{
				res.push_back(i);
				if(x / i != i) res.push_back(x / i);
			}
		}
		sort(res.begin(), res.end());
		for(auto num : res) printf("%d ", num);
		puts("");
	}
	
	return 0;
}
