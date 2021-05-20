#include <iostream>
#include <vector>
#include <chrono>
#include <complex>
using namespace std;


struct matrix
{

	vector < vector <complex <double> > > v;
	int size;
	matrix(int n)
	{
		v.assign(n, vector <complex <double> >(n));
		size = n;
	}

};

matrix slow_mult(matrix a, matrix b)
{
	matrix c = matrix(a.size);
	for (int i = 0; i < a.size; i++)
		for (int j = 0; j < a.size; j++)
			for (int k = 0; k < a.size; k++)
				c.v[i][j] += a.v[i][k] * b.v[k][j];
	return c;
}

matrix slice(matrix a, int n, int m)
{
	matrix c = matrix(a.size / 2);
	for (int i = 0; i < a.size / 2; i++)
	{
		for (int j = 0; j < a.size / 2; j++)
		{
			c.v[i][j] = a.v[i + (a.size / 2) * (n % 2)][j + (a.size / 2) * (m % 2)];
		}
	}
	return c;
}
matrix exp(matrix a, int n, int m)
{
	matrix c = matrix(a.size * 2);
	for (int i = 0; i < a.size; i++)
	{
		for (int j = 0; j < a.size; j++)
		{
			c.v[i + (a.size) * (n % 2)][j + (a.size) * (m % 2)] = a.v[i][j];
		}
	}
	return c;
}
matrix add(matrix a, matrix b, int sign)
{
	matrix c = matrix(a.size);
	for (int i = 0; i < a.size; i++)
		for (int j = 0; j < a.size; j++)
			c.v[i][j] = a.v[i][j] + b.v[i][j] * complex <double>(sign, 0);
	return c;
}

matrix foo(matrix a)
{
	int i = 1;
	for (; i <= a.size; i *= 2)
		if (i == a.size)
			return a;
	vector <vector <complex <double> > > v(i, vector <complex <double>>(i, complex <double>(0, 0)));
	for (int i = 0; i < a.size; i++)
		for (int j = 0; j < a.size; j++)
			v[i][j] = a.v[i][j];
	a.v = v;
	a.size = i;
	return a;
}
matrix foo1(matrix a, int n)
{
	matrix c = matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c.v[i][j] = a.v[i][j];
	return c;
}
matrix mult(matrix a, matrix b)
{
	matrix c = matrix(a.size);
	if (a.size == 64)
		return slow_mult(a, b);
	matrix buf = matrix(a.size / 2);
	vector <matrix> p(7, buf);
	vector <matrix> va(4, buf);
	vector <matrix> vb(4, buf);
	vector <matrix> vc(4, buf);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			va[i * 2 + j] = slice(a, i, j);
			vb[i * 2 + j] = slice(b, i, j);
		}
	p[0] = mult(add(va[0], va[3], 1), add(vb[0], vb[3], 1));
	p[1] = mult(add(va[2], va[3], 1), vb[0]);
	p[2] = mult(va[0], add(vb[1], vb[3], -1));
	p[3] = mult(va[3], add(vb[2], vb[0], -1));
	p[4] = mult(add(va[0], va[1], 1), vb[3]);
	p[5] = mult(add(va[2], va[0], -1), add(vb[0], vb[1], 1));
	p[6] = mult(add(va[1], va[3], -1), add(vb[2], vb[3], 1));

	vc[0] = add(p[0], p[3], 1);
	vc[0] = add(vc[0], p[4], -1);
	vc[0] = add(vc[0], p[6], 1);

	vc[1] = add(p[2], p[4], 1);
	vc[2] = add(p[1], p[3], 1);

	vc[3] = add(p[0], p[1], -1);
	vc[3] = add(vc[3], p[2], 1);
	vc[3] = add(vc[3], p[5], 1);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			c = add(c, exp(vc[i * 2 + j], i, j), 1);
	return c;
}


void show(matrix c)
{
	for (int i = 0; i < c.size; i++)
	{
		for (int j = 0; j < c.size; j++)
			cout << c.v[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int n = 125;
	matrix a = matrix(n);
	matrix b = matrix(n);
	vector <complex <double> > vec(n);
	for (int i = 0; i < n; i++)
		vec[i] = i;
	a.v.assign(n, vec);
	b.v.assign(n, vec);
	a = foo(a);
	b = foo(b);
	auto start = chrono::system_clock::now();
	matrix c = mult(a, b);
	auto stop = chrono::system_clock::now();
	chrono::duration < double > dif = stop - start;
	c = foo1(c, n);
	show(c);
	cout << endl << endl << dif.count();
	return 0;
}