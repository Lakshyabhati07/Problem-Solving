#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int lastoccurene(vector<int>& nums, int target){
        int s=0;
        int n=nums.size();
        int e=nums.size()-1;
        int m=(s+e)/2;
         while(s<=e){

            if(nums[m]==target&&(m==n-1||nums[m]<nums[m+1]))
            return m;

            //left discard
            if(nums[m]<=target)
            s=m+1;
            else
            e=m-1;


            m=(s+e)/2;
        }
        return -1;

    }

    int firstoccurence(vector<int>& nums, int target){
         int s=0;
        int e=nums.size()-1;
        int m=s+(e-s)/2;
        while(s<=e){

            if(nums[m]==target&&(m==0||nums[m-1]!=target))
          return m;

            //left discard
            if(nums[m]<target)
            s=m+1;
            else
            e=m-1;


            m=s+(e-s)/2;
        }
return -1;
    }

public:

    vector<int> searchRange(vector<int>& nums, int target) {
       
        return {firstoccurence(nums,target),lastoccurene(nums,target)};
       
    }
};