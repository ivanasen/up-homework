#include <iostream>
#include <cmath>

using namespace std;

bool is_armstrong(int n)
{
	int numLength = log10(n) + 1;
	int sum = 0;
	int nTemp = n;

	while(n != 0)
	{
		int lastDigit = n % 10;
		sum += pow(lastDigit, numLength);
		n /= 10;
	}
	
	return sum == nTemp;
}

main()
{
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (is_armstrong(i))
		{
			cout << i << endl;
		}
	}

	return 0;
}
