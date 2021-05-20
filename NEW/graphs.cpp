#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map <int, vector <int>> m;
vector <int> sm;
int color = 1;


void bfs(int s)
{
	int n = m.size();
	queue<int> q;
	q.push(s);
	vector<int> d(n), p(n);
	sm[s] = color;
	p[s] = -1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < m[v].size(); i++) 
		{
			int to = m[v][i];
			if (!sm[to])
			{
				sm[to] = color;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
}



vector<int> colour;
vector<int> path;
int cycle_st, cycle_end;


bool dfs(int v) {
	colour[v] = 1;
	for (int i = 0; i < m[v].size(); i++) {
		int to = m[v][i];
		if (colour[to] == 0) {
			path[to] = v;
			if (dfs(to))  return 1;
		}
		else if (colour[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return 1;
		}
	}
	colour[v] = 2;
	return 0;
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
		m[f].push_back(b);
	}
	sm.assign(m.size(), 0);
	//тут кусок относится к поиску компонент связности. 
	//в массиве sm каждой вершине сопоставлен её цвет. одинаковый цвет - одна компонента.
	for (auto i : m)
	{
		if (sm[i.first] == 0)
		{
			bfs(i.first);
			color++;
		}
	}
	//тут кусок относится к поиску циклов
	path.assign(m.size(), -1);
	colour.assign(m.size(), 0);

	cycle_st = -1;
	for (int i = 0; i < n; ++i)
		if (dfs(i))
			break;

	if (cycle_st == -1)
		cout << "NETU";
	else {
		cout << "EST";
		vector<int> cycle;
		cycle.push_back(cycle_st);
		for (int v = cycle_end; v != cycle_st; v = path[v])
			cycle.push_back(v);
		cycle.push_back(cycle_st);
		for (auto i = (--cycle.end()); i != cycle.begin(); --i)
			cout << *i + 1 << " ";
		cout << *cycle.begin() + 1;
	}
	return 0;
}
