#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(vector<int>& arr, int n, int key) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int last_occurrence(vector<int>& arr, int n, int key) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
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

        int key;
        cin >> key;

        int first = first_occurrence(arr, n, key);

        if (first == -1) {
            cout << "Key not present" << endl;
        }
        else {
            int last = last_occurrence(arr, n, key);
            int count = last - first + 1;

            cout << key << "-" << count << endl;
        }
    }

    return 0;
}
