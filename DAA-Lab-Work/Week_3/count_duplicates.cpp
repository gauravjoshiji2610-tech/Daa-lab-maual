#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        arr.push_back(x);
        freq[x]++;
    }

    int duplicates = 0;

    for (auto it : freq) {
        if (it.second > 1) {
            duplicates += it.second - 1;
        }
    }

    cout << "Total number of duplicate elements: " << duplicates;

    return 0;
}
