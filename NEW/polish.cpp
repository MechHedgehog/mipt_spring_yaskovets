//Ввод - алгебраическое выражение без пробелов типа (2+3)/4
//Вывод - первая строка - выражение в обратной польской записи, вторая - результат
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
pair <int, char> convert(char ch)
{
	if (ch == '(') return pair <int, char>(0, ch);
	if (ch == ')') return pair <int, char>(1, ch);
	if (ch == '+' || ch == '-') return pair <int, char>(2, ch);
	if (ch == '*' || ch == '/') return pair <int, char>(3, ch);
}
int main()
{
	string s, buf = "";
	vector <string> result;
	stack <pair <int, char>> oper;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		while (isdigit(s[i]) || s[i] == '.')
		{
			buf += s[i];
			i++;
		}
		if (buf != "")
		{
			result.push_back(buf);
			buf = "";
			i--;
			continue;
		}
		auto sim = convert(s[i]);
		if (!oper.size() || sim.second == '(')
		{
			oper.push(sim);
			continue;
		}
		if (sim.second == ')')
		{
			char bf = oper.top().second;
			oper.pop();
			while (bf != '(')
			{
				result.push_back(string(1,bf));
				bf = oper.top().second;
				oper.pop();
			}
			continue;
		}
		while (oper.size() && oper.top().first >= sim.first)
		{
			result.push_back(string(1, oper.top().second));
			oper.pop();
		}
		oper.push(sim);
	}
	while (oper.size())
	{
		result.push_back(string(1, oper.top().second));
		oper.pop();
	}
	for (auto i : result)
	{
		cout << i << " ";
	}
	cout << endl;
	stack <double> st;
	for (auto i : result)
	{
		if (isdigit(i[0]))
		{
			st.push(atof(i.c_str()));
		}
		else
		{
			double res, n1, n2;
			n1 = st.top();
			st.pop();
			n2 = st.top();
			st.pop();
			if (i == "+") res = n2 + n1;
			if (i == "-") res = n2 - n1;
			if (i == "*") res = n2 * n1;
			if (i == "/") res = n2 / n1;
			st.push(res);
		}
	}
	cout << st.top();
	return 0;
}
