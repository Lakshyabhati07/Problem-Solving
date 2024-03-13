#include<bits/stdc++.h>
using namespace std;

bool isPossibleToFormSubarray(int mid,vector<int> &A,int s){
    int n=A.size();
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum<s){
            cnt++;
        }

        else break;
    }

    return cnt>=mid;
}

int solvefunction(vector<int> &A,int s){

    int high=A.size();
    int low=1;
    int ans=low;

    while(low<=high){
        int mid=(low+high)/2;

        if(isPossibleToFormSubarray(mid,A,s)){
            ans=mid;
            low=mid+1;
        }
        else high = mid-1;
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> A(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    int s;
    cin>>s;

    int ans=solvefunction(A,s);

cout<<"Answer ->"<<ans<<" : )";
return 0;
}

