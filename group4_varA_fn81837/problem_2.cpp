#include <iostream>

using namespace std;

bool is_right_triangle(double a, double b, double c)
{
	return a * a + b * b == c * c ||
		   a * a + c * c == b * b ||
		   b * b + c * c == a * a;
}

bool has_triangles(double *a, double *b, double *c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (is_right_triangle(a[i], b[j], c[k]))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void solve()
{
	int n = 3;
	double a[] = {1, 5, 3};
	double b[] = {2, 4, 8};
	double c[] = {6, 3, 0};

	cout << has_triangles(a, b, c, n) << '\n';
}

int main()
{
	solve();
	return 0;
}