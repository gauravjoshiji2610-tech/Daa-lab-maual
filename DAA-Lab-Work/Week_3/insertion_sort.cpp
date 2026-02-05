#include <iostream>
#include <vector>
using namespace std;

pair<int, int> insertion_sort_count(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;

            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else {
                break;
            }
        }

        arr[j + 1] = key;
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

        pair<int, int> result = insertion_sort_count(arr);

        for (int x : arr) {
            cout << x << " ";
        }

        cout << endl;
        cout << result.first << endl;
        cout << result.second << endl;
    }

    return 0;
}
