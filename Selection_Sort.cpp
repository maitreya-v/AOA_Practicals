#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    int arr[n] = {64, 25, 12, 22, 11};
    for(int i=0;i<n-1;i++){
        int Var=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[Var]){
                Var=j;
            }
        }
        swap(arr[i],arr[Var]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}