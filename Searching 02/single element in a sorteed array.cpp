#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }


        int s=1;
        int e=n-2;

        while(s<=e){
            int m=s+(e-s)/2;
            //single elemnt
            if(nums[m]!=nums[m+1]&&nums[m]!=nums[m-1])
            return nums[m];
            // leftt
           if((m%2==1&& nums[m-1]==nums[m])||(m%2==0&& nums[m+1]==nums[m])){
               s=m+1;
           }
           else e=m-1;

        }
        return -1;

    }
};