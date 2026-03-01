#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<char> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> count(26,0);

        for(int i = 0; i < n; i++)
            count[arr[i] - 'a']++;

        int maxFreq = 0;
        char result;

        for(int i = 0; i < 26; i++)
        {
            if(count[i] > maxFreq)
            {
                maxFreq = count[i];
                result = 'a' + i;
            }
        }

        if(maxFreq <= 1)
            cout << "No Duplicates Present" << endl;
        else
            cout << result << " " << maxFreq << endl;
    }

    return 0;
}