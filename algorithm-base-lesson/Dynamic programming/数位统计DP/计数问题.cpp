#include <iostream>
#include <vector>

using namespace std;

int a, b;

int get_start(vector<int> n, int l, int r)
{
	int res = 0;
	for(int i = l; i >= r; i--)
	{
		res *= 10;
		res += n[i];
	}
	return res;
}

int power10(int l)
{
	int res = 1;
	for(int i = 0; i < l; i++)
	{
		res *= 10;
	}
	
	return res;
}

int count(int num, int idx)
{
	if(!num) return 0;
	vector<int> n;
	while(num)
	{
		n.push_back(num % 10);
		num /= 10;
	}
	int res = 0;
	for(int i = n.size() - 1; i >= 0; i--)
	{
		if(i != n.size()-1)
		{
			res += get_start(n, n.size() - 1, i + 1) * power10(i);
		}
		if(!idx) res -= power10(i);
		if (n[i] == idx)
		{
			res += get_start(n, i - 1, 0) + 1;
		}
		else if(n[i] > idx) 
		{
			res += power10(i);
		}
	}
	
	return res;
}

int main()
{
	while(cin >> a >> b, a || b)
	{
		if(a > b) swap(a, b);
		for(int i = 0; i < 10; i++)
		{
			printf("%d ", count(b, i) - count(a - 1, i));
		}
		puts("");
	}
	
	return 0;
}
