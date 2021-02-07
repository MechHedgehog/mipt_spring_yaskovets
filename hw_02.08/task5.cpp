#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cout << string(n - i, '*') << endl;
	return 0;
}
