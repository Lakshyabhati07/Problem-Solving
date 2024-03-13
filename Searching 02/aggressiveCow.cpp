#include<bits/stdc++.h>
using namespace std;

bool CanWePlaceTheCows(vector<int> &stalls, int k,int distance){

    int NumCows=1;
    int lastPlaced=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-lastPlaced>=distance){
            NumCows++;
            lastPlaced=stalls[i];
        }
       if(NumCows>=k)   return true;
    }
    return false;
}



int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int size=stalls.size();
    int low=0;
    int high=stalls[size-1]-stalls[0];
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;

        if(CanWePlaceTheCows(stalls,k,mid)){
            ans=mid; //maybe a potential answer check for another
            low=mid+1;
        }
        else    high=mid-1;

    }
return ans;
}
