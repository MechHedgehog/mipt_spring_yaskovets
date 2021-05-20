/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map <int, vector <int>> m;
map <int, int> c;

int smegnost(int start,int color)
{
	queue <int> q;
	q.push(start);
	int buf;
	while (q.size())
	{
		buf = q.front();
		c[buf] = color;
		q.pop();
		for (int i = 0; i < m[buf].size(); i++)
		{
			if (c[m[buf][i]] == 0) q.push(m[buf][i]);
		}
	}
	return 0;
}


int tsikli(int start, int prev)
{
	c[start] = 1;
	for (int i = 0; i < m[start].size(); i++)
	{
		if (c[m[start][i]] > 0 && m[start][i] != prev) return 1;
		if (c[m[start][i]] == 0) tsikli(m[start][i], start);
	}
	c[start] = 2;
}


int main()
{
	freopen("inp.txt", "r", stdin);
	int n;
	cin >> n;
	int b, f;
	for (int i = 0; i < n; i++)
	{
		cin >> b >> f;
		m[b].push_back(f);
	}

	return 0;
}*/