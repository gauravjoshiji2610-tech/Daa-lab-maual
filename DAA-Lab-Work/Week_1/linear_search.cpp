#include <iostream>
#include <vector>
using namespace std;

pair<bool, int> linear_search(vector<int>& arr, int key) {
    int comparisons = 0;

    for (int value : arr) {
        comparisons++;

        if (value == key) {
            return {true, comparisons};
        }
    }

    return {false, comparisons};
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        pair<bool, int> result = linear_search(arr, key);

        if (result.first) {
            cout << "Present " << result.second << endl;
        }
        else {
            cout << "Not Present " << result.second << endl;
        }
    }

    return 0;
}
