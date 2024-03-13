#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   long long int bsearch(int n){
        int s=0;
        int ans=0;
        int e=n-1;
        long long int mid= s+((e-s)/2);
        while(s<=e){
            long long int sqr=mid*mid;
            if(sqr==n)
            return mid;

            if(sqr>n)
            e=mid-1;
            else{
            ans=mid;
            s=mid+1;}
        mid= s+((e-s)/2);
        }
       return ans;
        }
    
    int mySqrt(int x) { 

        if(x==1)
        return 1;
        else   
    return bsearch(x);   

    }
};