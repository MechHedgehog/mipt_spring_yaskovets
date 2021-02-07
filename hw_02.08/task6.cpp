#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n / 2 + n % 2; i++) cout << string(i, ' ') + string(n - i * 2, '*') << endl;
	return 0;
}