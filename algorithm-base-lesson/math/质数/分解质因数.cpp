#include <iostream>

using namespace std;

int n;

void print_prime(int x)
{
	for(int i = 2; i <= x / i; i++)
	{
		if(x % i == 0)
		{
			int res = 0;
			while(x % i == 0)
			{
				x /= i;
				res++;
			}
			printf("%d %d\n", i, res);
		}
	}
	if(x > 1) printf("%d 1\n", x);
	puts("");
}

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		print_prime(x);
	}
	
	return 0;
}
