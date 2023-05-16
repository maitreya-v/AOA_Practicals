#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int arr[n]={12,13,4,2,1};
    for(int i = 1 ; i<n;i++){
        int j=i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key){
            swap(arr[j+1],arr[j]);
            j=j-1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}