#include <iostream>

using namespace std;

int main()
{
	double x;
	cin >> x;

	double top = 11 * x * x + 3 * x + 15;
	double bottom = x * x * x - 25;

	if (bottom == 0)
	{
		cout << "Can\'t divide by 0 :(" << endl;
	}

	double result = top / bottom;
	cout << result << endl;
	
	return 0;
}
