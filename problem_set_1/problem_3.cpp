#include <iostream>
#include <cmath>

using namespace std;

int transform_number(int n)
{
	int result = 0;
	int tenthPower = 1;
	while (n != 0)
	{
		int remainder = n % 10;

		if (remainder % 3 == 0)
		{
			result += tenthPower * (remainder / 3);
		}
		else
		{
			result += tenthPower * (remainder + 1 + remainder % 2);
		}

		tenthPower *= 10;
		n /= 10;
	}

	return result;
}

main()
{
	int n;
	cin >> n;

	int result = transform_number(n);

	cout << result << endl;

	return 0;
}
