#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    long maxNum = 0;
    for (auto &query : queries) {        
        maxNum += query[2];       
    }
    vector<long> arr(n, maxNum);
    vector<bool> checked(n, false);
    int checkedCount = 0;
    int i = queries.size() - 1;
    for (; i >= 0 && checkedCount < n; i--) {
        int start = queries[i][0] - 1;
        int end = queries[i][1] - 1;
        int value = queries[i][2];
        // std::cout << start << end << '\n';
        for (int j = 0; j < n && checkedCount < n; j++) {
            if (j == start) {
                if (end < n - 1) {
                    j = end + 1;
                } else {
                    break;
                }
                
            }

            if (!checked[j]) {
                checked[j] = true;
                checkedCount++;
            }

            arr[j] -= value;            
        }

        // for (int i = 0; i < arr.size(); i++) {
        //     std::cout << arr[i] << ' ';
        // }
        // std::cout << '\n';
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {            
            maxIndex = i;
        }
    }

    for (; i >= 0; i--) {
		int start = queries[i][0] - 1;
		int end = queries[i][1] - 1;
		int value = queries[i][2];

		if (maxIndex < start || maxIndex > end) {
			arr[maxIndex] -= value;
		}
    }


    return arr[maxIndex];
}

int main()
{

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}