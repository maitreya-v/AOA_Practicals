#include<iostream>
using namespace std;
int board[100];

void print_board(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i]==j){
                cout<<"Q ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<"\n";

    }
};
int is_valid(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row)){
            return 0;
        }
    }
    return 1;
};
void solve(int n,int row){
    if(row==n){
        print_board(n);
        cout<<"\n\n";
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(is_valid(row,i)){
                board[row]=i;
                solve(n,row+1);
            }
        }
    }
};


int main()
{   
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    solve(n,0);
    return 0;
}