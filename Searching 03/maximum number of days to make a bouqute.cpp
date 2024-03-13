#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool possibleToMake(vector<int>& bloomDay,int mid ,int m, int k){
        int cnt=0;
        int numofbouqet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                numofbouqet+=(cnt/k);
                cnt=0;
            }
        }
         numofbouqet+=(cnt/k);
        return  numofbouqet>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL * k * 1LL;
       if(val>bloomDay.size())   return -1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
       while(low<=high){

        int mid=(low+high)/2;
        if(possibleToMake(bloomDay,mid,m,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
return ans;
    }
};