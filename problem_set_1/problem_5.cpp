#include <iostream>
#include <climits>

using namespace std;

int get_digits_sum(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

main()
{
	int n;
	cin >> n;

	for (int i = 2018; i <= INT_MAX; i++)
	{
		int sum = get_digits_sum(i);
		if (n % sum == 0)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
