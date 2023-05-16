#include<iostream>
using namespace std;
#define MAX_SIZE 100
int set[MAX_SIZE],subset[MAX_SIZE];
int n;
int sum;
int found=0;

void subset_sum(int index,int current_sum){
    if(sum==current_sum){
        found=1;
        for(int i=0;i<n;i++){
            cout<<subset[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(current_sum>sum || index==n){
            return;
    }
    subset[index]=set[index];
    subset_sum(index+1,current_sum+set[index]);
    subset[index]=0;
    subset_sum(index+1,current_sum);
}

int main()
{
    cout<<"Enter the size of the set"<<endl;
    cin>>n;
    cout<<"Enter the numbers of the set"<<endl;
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
    cout<<"Enter the desired sum"<<endl;
    cin>>sum;
    subset_sum(0,0);

    if(!found){
        cout<<"There is no subset"<<endl;
    }

    


    return 0;
}