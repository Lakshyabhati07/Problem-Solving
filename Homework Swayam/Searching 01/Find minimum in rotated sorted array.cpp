#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){

            int mid=low+(high-low)/2;

    //left sorted
            if(nums[low]<=nums[mid]){
                //find minimum fromt it;
                ans=min(nums[low],ans);
                low=mid+1;
            }
    //rigth sorted

            else{

                ans=min(nums[mid],ans);
                high=mid-1;
            }

        }

return ans;
    }
};