#include<bits/stdc++.h>
#include<string.h>

using namespace std;
#define PRIME 101
int main()
{
    int tl,pl,hash[100],patternhash=0;
    string text,pattern;
    cout<<"Enter text string\n";
    cin>>text;
    cout<<"Enter pattern string\n";
    cin>>pattern;
    tl=text.length();
    pl=pattern.length();
    int totalhash=tl-pl+1;

    for(int i=0;i<100;i++){
        hash[i]=0;
    }
    for(int i=0;i<pl;i++){
        patternhash+=pattern[i];
    }
    patternhash%=PRIME;

    for(int i=0;i<totalhash;i++){
        for(int j=0;j<pl;j++){
            hash[i]+=(text[i+j]);
        }
        hash[i]%=PRIME;
    }

    int flag=1;
    for(int i=0;i<totalhash;i++){
        if(hash[i]==patternhash){
            for(int j=0;j<pl;j++){
                if(text[i+j]!=pattern[j]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cout<<"FOUND\n";
            }
        }
    }
    if(!flag)
    cout<<"NOT FOUND";
        return 0;
}