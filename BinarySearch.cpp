#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int arr[20];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key you want to search"<<endl;
    cin>>key;
    int start=0;
    int end=n-1;
int flag=1;
    while(start<=end){
        int mid=(start+end)/2;

        if(arr[mid]==key){
            cout<<"Key found at "<<mid<<endl;
            flag=0; 
            break;
        }

        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return 0;
}