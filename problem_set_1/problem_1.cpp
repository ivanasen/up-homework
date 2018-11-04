#include <iostream>

using namespace std;

double get_function_result(double x)
{
	double result = (11 * x * x + 3 * x + 15) / (x * x * x - 25);
	return result;
}

int main()
{
	double x;
	cin >> x;
	cout << get_function_result(x) << endl;
	return 0;
}
