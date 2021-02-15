#include <iostream>
#include <string>

using namespace std;


string task_10_side(string& ans, int number_in_place)
{
	ans += ((number_in_place % 100 - number_in_place % 10) / 10 ? string((number_in_place % 100 - number_in_place % 10) / 10, '<') : ".");
	ans += (number_in_place % 10 ? string(number_in_place % 10, 'v') : ".");
	return ans;
}


int task_1_side(int first_number, int second_number)
{
	return (second_number ? task_1_side(second_number, first_number % second_number) : first_number);
}


int task_1_main()
{
	int first_number, second_number;
	cin >> first_number >> second_number;
	int gcd = task_1_side(first_number, second_number);
	cout << "gcd = " << gcd << endl << "lcm = " << first_number * second_number / gcd;
	return 0;
}


int task_2_main()
{
	int year;
	cin >> year;
	cout << ((!(year % 400) || (!(year % 4) && (year % 100))) ? "YES" : "NO");
	return 0;
}


int task_3_main()
{
	int input_buffer, answer = 0;
	cin >> input_buffer;
	while (input_buffer != 0)
	{
		answer += !(input_buffer % 2);
		cin >> input_buffer;
	}
	cout << answer;
	return 0;
}


int task_4_main()
{
	uint64_t input_number, itter = 1;
	cin >> input_number;
	while (itter < input_number)
	{
		itter <<= 1;
	}
	cout << (itter == input_number ? "YES" : "NO");
	return 0;
}


int task_5_main()
{
	int input_buffer, max_number = -10e6 + 1;
	cin >> input_buffer;
	while (input_buffer != 0)
	{
		if (!(input_buffer % 2) && input_buffer > max_number)
		{
			max_number = input_buffer;
		}
		cin >> input_buffer;
	}
	cout << max_number;
	return 0;
}


int task_6_main()
{
	int input_buffer, max_number = -10e6 + 1, amount_of_max_numbers = 0;
	cin >> input_buffer;
	while (input_buffer != 0)
	{
		if (!(input_buffer % 2) && input_buffer > max_number)
		{
			max_number = input_buffer;
			amount_of_max_numbers = 0;
		}

		if (input_buffer == max_number)
		{
			amount_of_max_numbers++;
		}

		cin >> input_buffer;
	}
	cout << max_number << " " << amount_of_max_numbers;
	return 0;
}


int task_7_main()
{
	int input_number;
	cin >> input_number;
	for (int i = 2; i * i <= input_number; i++)
	{
		if (!(input_number % i))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}


int task_8_main()
{
	int input_number;
	cin >> input_number;
	for (int i = 2; input_number != 1; i++)
	{
		while (!(input_number % i))
		{
			input_number /= i;
			cout << i << " ";
		}
	}
	return 0;
}


int task_9_main()
{
	return 0;
}


int task_10_main()
{

	string answer = "";
	int input_number, buff = 1;
	cin >> input_number;
	while (input_number > buff * 60 - 1)
	{
		buff *= 60;
	}
	while (input_number != 0)
	{
		task_10_side(answer, input_number / buff);
		input_number %= buff;
		buff /= 60;
	}
	if (answer[0] == '.') answer = answer.substr(1, answer.size() - 1);
	cout << answer;

	return 0;
}


int main()
{
	int a;
	cout << "Enter the number of a task: ";
	cin >> a;
	switch (a)
	{
	case 1:
		task_1_main();
		break;
	case 2:
		task_2_main();
		break;
	case 3:
		task_3_main();
		break;
	case 4:
		task_4_main();
		break;
	case 5:
		task_5_main();
		break;
	case 6:
		task_6_main();
		break;
	case 7:
		task_7_main();
		break;
	case 8:
		task_8_main();
		break;
	case 9:
		task_9_main();
		break;
	case 10:
		task_10_main();
		break;
	}
	return 0;
}