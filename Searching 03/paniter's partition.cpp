#include<bits/stdc++.h>
using namespace std;

bool blackbox(vector<int> &boards,int k,int n, int mid){
int sum=0;
int total=0;

for(int i=0;i<boards.size();i++){
    sum+=boards[i];
    if(sum>mid)
    {   total++;
        sum=boards[i];
        }
}
total++;

return total<=k;

}

int sum(vector<int> &boards){
    int sum=0;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
    }
    return sum;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int size=boards.size();
    if(k>size)  return -1;
    int ans=0;
    int low=*max_element(boards.begin(),boards.end());
    int high=sum(boards);

    while(low<=high){
        int mid=(low+high)/2;

        if(blackbox(boards,k,size,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;;
        }
    }

    return ans;

}