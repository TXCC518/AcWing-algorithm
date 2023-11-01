#include <iostream>

using namespace std;

int n;

bool is_prime(int x)
{
	if(x < 2) return false;
	for(int i = 2; i <= x / i; i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(is_prime(x)) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
