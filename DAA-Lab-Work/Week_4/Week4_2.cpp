//Quick Sort
#include<iostream>
#include<vector>
using namespace std;
int comparisons=0,swaps=0;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        comparisons++;
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1],arr[high]);
    swaps++;
    return i+1;

}
void quickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi,high);
    }
}
int main(){
    int T;
    cout<<"Enter the number of test cases:";
    cin>>T;
    while(T--){
        int n;
        cout<<"Enter the number of elements in unsorted array of integers";
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        quickSort(arr,0,n-1);
         for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";

        cout<<endl;

        cout<<"Comparisons = "<<comparisons<<endl;
        cout<<"Swaps = "<<swaps<<endl;
    }
    return 0;
    }
