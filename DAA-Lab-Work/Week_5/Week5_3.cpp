#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int m,n;

        cin >> m;
        vector<int> a(m);

        for(int i=0;i<m;i++)
            cin >> a[i];

        cin >> n;
        vector<int> b(n);

        for(int i=0;i<n;i++)
            cin >> b[i];

        int i=0,j=0;

        while(i<m && j<n)
        {
            if(a[i]==b[j])
            {
                cout<<a[i]<<" ";
                i++;
                j++;
            }
            else if(a[i] < b[j])
                i++;
            else
                j++;
        }

        cout<<endl;
    }

    return 0;
}