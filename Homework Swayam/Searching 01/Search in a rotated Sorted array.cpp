#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;

        while(low<=high){

         int   mid=(low+high)/2;

            if(nums[mid]==target)
            return mid;
            //leftt sorted
            else if(nums[0]<=nums[mid]){

                if(nums[0]<=target&&target<=nums[mid])
                    high=mid-1;

                else    low=mid+1;

            }
            else{

                if(nums[mid]<=target&&target<=nums[high])
                    low=mid+1;
                else    high=mid-1;
            }

        }
        return -1;
    }
};