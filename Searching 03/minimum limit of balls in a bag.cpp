#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
bool blackboxcheck(vector<int>& nums, int maxop, int mid){
   
            for(int i=0;i<nums.size();i++){
                maxop-=(ceil(nums[i] /mid));
                if(nums[i]%mid==0)
                maxop++;
            }
            return maxop>=0;
}
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int ans=*max_element(nums.begin(),nums.end());
        int n=nums.size();

        int low=1;
        int high=ans;

        while(low<=high){
            int mid=(low+high)/2;
         
            if(blackboxcheck(nums,maxOperations,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
return ans;
    }
};