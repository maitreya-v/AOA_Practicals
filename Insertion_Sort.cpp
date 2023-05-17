// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n=5;
//     int arr[n]={12,13,4,2,1};
//     for(int i = 1 ; i<n;i++){
//         int j=i-1;
//         int key = arr[i];
//         while(j>=0 && arr[j]>key){
//             swap(arr[j+1],arr[j]);
//             j=j-1;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than the key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int a[1000],i;
    clock_t start,end;
    double cpu_time_used;

    srand(time(NULL));

    start=clock();

    insertion_sort(a,1000);

    end=clock();

    cpu_time_used=(float(end-start)/CLOCKS_PER_SEC);

    cout<<"Total time taken "<<cpu_time_used;
    return 0;

}