// #include<bits/stdc++.h>
// using namespace std;


// int main()
// {
//     int n;
//     cout<<"Enter the value of n"<<endl;
//     cin>>n;
//     int arr[20];
//     cout<<"Enter the elements of the array"<<endl;
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     int key;
//     cout<<"Enter the key you want to search"<<endl;
//     cin>>key;
//     int start=0;
//     int end=n-1;
// int flag=1;
//     while(start<=end){
//         int mid=(start+end)/2;

//         if(arr[mid]==key){
//             cout<<"Key found at "<<mid<<endl;
//             flag=0; 
//             break;
//         }

//         else if(arr[mid]<key){
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end)
{
    if (start > end)
        return -1; // Base case: key not found

    int mid = (start + end) / 2;

    if (arr[mid] == key)
        return mid; // Base case: key found at mid

    if (arr[mid] < key)
        return binarySearch(arr, key, mid + 1, end);
    else
        return binarySearch(arr, key, start, mid - 1);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[20];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key you want to search: ";
    cin >> key;

    int result = binarySearch(arr, key, 0, n - 1);

    if (result == -1)
        cout << "Key not found" << endl;
    else
        cout << "Key found at index " << result << endl;

    return 0;
}
