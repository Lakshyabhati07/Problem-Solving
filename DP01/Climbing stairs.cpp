#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        int pp=1;
        int p=2;
        int nx;
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        for(int i=2;i<n;i++){
            nx=pp+p;
            pp=p;
            p=nx;
        }
        return nx;
    }
};