#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++) {

        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {

    if(low <= high) {

        int pi = partition(arr, low, high);

        if(pi == k)
            return arr[pi];

        else if(pi > k)
            return quickSelect(arr, low, pi - 1, k);

        else
            return quickSelect(arr, pi + 1, high, k);
    }

    return -1;
}

int main() {

    int T;
    cin >> T;

    while(T--) {

        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if(k > n) {
            cout << "not present" << endl;
            continue;
        }

        int ans = quickSelect(arr, 0, n-1, k-1);

        if(ans == -1)
            cout << "not present" << endl;
        else
            cout << ans << endl;
    }
}