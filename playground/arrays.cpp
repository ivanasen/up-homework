#include <iostream>

using namespace std;

const int MAX = 100;

int fill_array(int *arr)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return n;
}

bool is_monotonously_increasing(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool all_different(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				return false;
			}
		}
	}
	return true;
}

void sort_array(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void print_array(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	int arr[MAX];
	int len = fill_array(arr);
	string monotonous = is_monotonously_increasing(arr, len) ? "Yes" : "No";
	cout << "Monotonous: " << monotonous << endl;

	string different = all_different(arr, len) ? "Yes" : "No";
	cout << "Different: " << different << endl;

	sort_array(arr, len);
	print_array(arr, len);

	return 0;
}