#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> heap;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a;
		scanf("%d", &a);
		heap.push(a);
	}
	int res = 0;
	while(heap.size() > 1)
	{
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	
	printf("%d\n", res);
	
	return 0;
}

