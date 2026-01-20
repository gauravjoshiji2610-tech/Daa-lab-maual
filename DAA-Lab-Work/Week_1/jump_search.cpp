#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<bool, int> jump_search(vector<int>& arr, int key) {
    int n = arr.size();
    int comparisons = 0;

    int step = sqrt(n);
    int prev = 0;

    while (prev < n && arr[min(step, n) - 1] < key) {
        comparisons++;

        prev = step;
        step += sqrt(n);

        if (prev >= n) {
            return {false, comparisons};
        }
    }

    while (prev < min(step, n)) {
        comparisons++;

        if (arr[prev] == key) {
            return {true, comparisons};
        }

        prev++;
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

        pair<bool, int> result = jump_search(arr, key);

        if (result.first) {
            cout << "Present " << result.second << endl;
        }
        else {
            cout << "Not Present " << result.second << endl;
        }
    }

    return 0;
}
