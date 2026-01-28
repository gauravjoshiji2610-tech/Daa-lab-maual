#include <iostream>
#include <vector>
using namespace std;

bool find_three_indices(vector<int>& arr, int n, int& iPos, int& jPos, int& kPos) {
    for (int k = n - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;

        while (i < j) {
            int s = arr[i] + arr[j];

            if (s == arr[k]) {
                iPos = i;
                jPos = j;
                kPos = k;
                return true;
            }
            else if (s < arr[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    return false;
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

        int iPos, jPos, kPos;

        bool found = find_three_indices(arr, n, iPos, jPos, kPos);

        if (found) {
            cout << iPos << " " << jPos << " " << kPos << endl;
        }
        else {
            cout << "No sequence found" << endl;
        }
    }

    cout << "End of Program";

    return 0;
}
