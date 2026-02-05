#include <iostream>
#include <vector>
using namespace std;

pair<int, int> selection_sort_count(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(arr[i], arr[min_index]);
            swaps++;
        }
    }

    return {comparisons, swaps};
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        pair<int, int> result = selection_sort_count(arr);

        for (int x : arr) {
            cout << x << " ";
        }

        cout << endl;
        cout << result.first << endl;
        cout << result.second << endl;
    }

    return 0;
}
