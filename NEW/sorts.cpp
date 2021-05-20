#include <iostream>

using namespace std; 

void insertionSort(int* v, int size)
{
	int temp, j;
	for (int i = 1; i < size; i++)
	{
		temp = v[i];
		for (j = i; j > 0 && v[j - 1] > temp; j--) 
		{
			v[j] = v[j - 1];
		}
		v[j] = temp;   
	}
}


void shell_sort_1(int* v, int size) 
{
	int n = 1;
	for (; n - 1 <= size;)
		n <<= 1;
	n--;
	for (int d = n; d > 0; d = (d + 1) / 2 - 1) 
		for (int i = 0; i < size; i++) 
			for (int j = i + d; j < size; j += d)
				if (v[i] > v[j])
					swap(v[i], v[j]);
}

void shell_sort_2(int* v, int size)
{
	for (int d = size / 2; d > 0; d /= 2)
		for (int i = 0; i < size; i++)
			for (int j = i + d; j < size; j += d)
				if (v[i] > v[j])
					swap(v[i], v[j]);
}

void selection_sort(int* v, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (v[j] < v[min])
				min = j;

		if (min != i)
			swap(v[i], v[min]);
	}
}
void merge_sort(int* v, int st, int en)
{
	if (en-st < 10)
	{
		for (int i = st; i < en; i++)
		{
			for (int j = st; j < en; j++)
			{
				if (v[i] > v[j])
					swap(v[i], v[j]);
			}
		}
		return;
	}
	int b = (en - st) / 2 + (en - st) % 2;
	merge_sort(v, st, b);
	merge_sort(v, b, en);
	int* d = new int[en - st];
	int i = 0, j = 0;
	for (; i < b - st && j < en - b; )
	{
		if (v[st + i] <= v[b + j])
		{
			d[i + j] = v[st + i];
			i++;
		}
		else
		{
			d[i + j] = v[b + j];
			j++;
		}
	}
	for (; i < b - st; i++)
		d[j + i] = v[st + i];
	for (; j < en - b; j++)
		d[j + i] = v[en - b];
	for (int k = 0; k < en - st; k++)
		v[k] = d[k];
	delete[] d;
}


void quick_sort(int* v, int st, int en)
{
	int i = st, j = en, x = v[(st + en) / 2];
	do {
		while (v[i] < x) i++;
		while (v[j] > x) j--;

		if (i <= j)
		{
			if (v[i] > v[j]) swap(v[i], v[j]);
			i++, j--;
		}
	} while (i <= j);

	if (i < en)
		quick_sort(v, i, en);
	if (st < j)
		quick_sort(v, st, j);
}
int main()
{
	//freopen("inp.txt", "r", stdin);
	int n;
	cin >> n;
	int* v = new int[n];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	quick_sort(v, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	return 0;
}