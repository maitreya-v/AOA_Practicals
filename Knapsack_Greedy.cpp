#include<bits/stdc++.h>
using namespace std;

int main()
{
    float w,p=0,pw[10][4];
    int n;
// 0 for weight
// 1 for profit
// 2 for profit to weight ratio
// 3 for consumed
    cout<<"Enter max weight"<<endl;
    cin>>w;
    cout<<"Enter number of weights"<<endl;
    cin>>n;
    cout<<"enter the weights and profits"<<endl;
    for(int i=0;i<n;i++){
    printf("Enter weight and value of item %d: ", i + 1);
    cin>>pw[i][0];
    cin>>pw[i][1];
    pw[i][2] = pw[i][1] / pw[i][0]; // Calculating profit to weight ratio
    pw[i][3] = 0; // Setting consumed flag to 0 initially
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pw[j][2]>pw[i][2]){

                temp=pw[i][0];
                pw[i][0]=pw[j][0];
                pw[j][0]=temp;

                temp=pw[i][1];
                pw[i][1]=pw[j][1];
                pw[j][1]=temp;

                temp=pw[i][2];
                pw[i][2]=pw[j][2];
                pw[j][2]=temp;

            }
        }
    }

    int i=0;
    while(w!=0 && i<n){

        if(w>pw[i][0]){
            w-=pw[i][0];
            p+=pw[i][1];
            pw[i][3]=1;
            i++;
        }
        else{

            p+=(w*pw[i][2]);
            pw[i][3]=(w/pw[i][0]);
            break;
        }
    }
    
    for(i=0;i<n;i++)
 {
 printf("Weight: %1.2f Value: %1.2f consumed: %1.2f\n",pw[i][0],pw[i][1],pw[i][3]);
 }
 printf("Total Profit: %1.2f",p);
    return 0;
}