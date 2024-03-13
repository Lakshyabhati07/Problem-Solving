#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int NthRoot(int n, int m)
	{
	    if(m==1) return 1;
	    
	    int low=1;
	    int high=m;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        if(pow(mid,n)<m)    low=mid+1;
	        
	        else high=mid-1;
	    }
	    
	    return -1;
	    // Code here.
	}  

};