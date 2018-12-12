#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
	Node(const Node *left, const Node *right) : sum(left->sum + right->sum),
												left(left),
												right(right)
	{
	}

	Node(int sum) : sum(sum) {}

	Node(const vector<int> &values, int from, int to)
	{
		if (from == to)
		{
			sum = values[from];
			return;
		}

		int middle = (from + to) / 2;
		left = new Node(values, from, middle);
		right = new Node(values, middle + 1, to);
		sum = left->sum + right->sum;
	}

	int sum = 0;
	const Node *left = nullptr, *right = nullptr;

	int get_value(int index, int from, int to) const
	{
		if (from == to)
			return sum;

		int middle = (from + to) / 2;

		if (index <= middle)
			return left->get_value(index, from, middle);
		else
			return right->get_value(index, middle + 1, to);
	}

	const Node *set_value(int index, int value, int from, int to) const
	{
		if (index < from || index > to)
			return this; //this Node is unchanged.
		if (from == to)
			return new Node(value);

		int middle = (from + to) / 2;

		return new Node(
			left->set_value(index, value, from, middle),
			right->set_value(index, value, middle + 1, to));
	}
};

class PersistentArray
{
  private:
	Node *rootNode;
	vector<const Node *> versions;
	int size;

  public:
	PersistentArray(const vector<int> &initialArray)
	{
		this->rootNode = new Node(initialArray, 0, initialArray.size() - 1);
		this->size = initialArray.size();
		versions.push_back(nullptr);
		versions.push_back(rootNode);
	}

	int get(int version, int index)
	{
		return versions[version]->get_value(index, 0, size - 1);
	}

	void set(int index, int oldVersion, int value)
	{
		versions.push_back(versions[oldVersion]->set_value(index, value, 0, size - 1));
	}
};

PersistentArray *read()
{
	int n;
	vector<int> initialValues;
	cin >> n;

	initialValues.resize(n);
	for (int &x : initialValues)
		cin >> x;

	PersistentArray *array = new PersistentArray(initialValues);

	return array;
}

void solve(PersistentArray &array)
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string command;
		cin >> command;

		if (command == "create")
		{
			int basedOn, index, value;
			cin >> basedOn >> index >> value;
			array.set(index - 1, basedOn, value);
		}
		else if (command == "get")
		{
			int version, index;
			cin >> version >> index;
			printf("%d\n", array.get(version, index - 1));
		}
		else
			throw runtime_error("invalid command: " + command);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	PersistentArray *array = read();
	solve(*array);
	return EXIT_SUCCESS;
}