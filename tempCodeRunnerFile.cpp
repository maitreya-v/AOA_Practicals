#include<iostream>
using namespace std;

void quicksort(int arr[],int first,int last){
    if(first<last){
    int i=first;
    int j=last;
    int pivot=first;
    int temp;

    while(i<j){
        
        while(i<last && arr[i]>arr[pivot]){
            i++;
        }
        while(arr[j]<arr[pivot]){
            j--;
        }

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    }

    temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;

    quicksort(arr,first,j-1);
    quicksort(arr,j+1,last);
    

    }

}

int main()
{
    int arr[20];
    int n;
    cout<<"Enter the number of elemeents"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);

    cout<<"The sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}