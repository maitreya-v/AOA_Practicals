// #include <iostream>
// using namespace std;

// pair<int, int> maxValminVal(int i, int j, int arr[100], int maxVal, int minVal) {
//     int mid, maxVal1, minVal1;

//     if (i == j) {
//         minVal = arr[i];
//         maxVal = arr[i];
//     } else if (i == j - 1) {
//         if (arr[i] > arr[j]) {
//             maxVal = arr[i];
//             minVal = arr[j];
//         } else {
//             minVal = arr[i];
//             maxVal = arr[j];
//         }
//     } else {
//         mid = (i + j) / 2;
//         pair<int, int> left = maxValminVal(i, mid, arr, maxVal, minVal);
//         maxVal1 = left.first;
//         minVal1 = left.second;
//         pair<int, int> right = maxValminVal(mid + 1, j, arr, maxVal, minVal);
//         if (right.first > maxVal1) {
//             maxVal1 = right.first;
//         }
//         if (right.second < minVal1) {
//             minVal1 = right.second;
//         }
//         maxVal = maxVal1;
//         minVal = minVal1;
//     }

//     return make_pair(maxVal, minVal);
// }

// int main() {
//     int n;
//     cout << "Value of n: ";
//     cin >> n;

//     int arr[100];
//     cout << "Enter elements of the array:" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int maxVal, minVal;
//     maxVal = arr[0];
//     minVal = arr[0];
//     pair<int, int> result = maxValminVal(0, n - 1, arr, maxVal, minVal);
//     maxVal = result.first;
//     minVal = result.second;

//     cout << "maxVal is " << maxVal << endl;
//     cout << "minVal is " << minVal << endl;

//     return 0;
// }


#include <iostream>
using namespace std;

int maxVal,minVal;
int arr[100];

void maxValminVal(int i,int j){
    int midVal;
    int max1,min1;
    if(i==j){
        maxVal=arr[i];
        minVal=arr[i];
    }
    else if(i==j-1){
        if(arr[i]<arr[j]){
            maxVal=arr[j];
            minVal=arr[i];
        }
        else{
            maxVal=arr[i];
            minVal=arr[j];
        }
    }
    else{
        midVal=(i+j)/2;
        maxValminVal(i,midVal);
        max1=maxVal;
        min1=minVal;
        maxValminVal(midVal+1,j);
        if(max1>maxVal){
            maxVal=max1;
        }
        if(min1<minVal){
            minVal=min1;
        }
    }
}


int main(){
     int n;
    cout << "Value of n: ";
    cin >> n;

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // maxVal = arr[0];
    // minVal = arr[0];
    maxValminVal(0, n - 1);

    cout << "maxVal is " << maxVal << endl;
    cout << "minVal is " << minVal << endl;

    return 0;
}