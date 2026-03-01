#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while(i <= mid)
        temp.push_back(arr[i++]);

    while(j <= right)
        temp.push_back(arr[j++]);

    for(int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        mergeSort(arr, 0, n-1);

        int left = 0, right = n-1;
        bool found = false;

        while(left < right)
        {
            int sum = arr[left] + arr[right];

            if(sum == key)
            {
                cout << arr[left] << " " << arr[right] << endl;
                found = true;
                break;
            }
            else if(sum < key)
                left++;
            else
                right--;
        }

        if(!found)
            cout << "No Such Element Exist" << endl;
    }

    return 0;
}