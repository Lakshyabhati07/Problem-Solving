#include<bits/stdc++.h>
using namespace std;

int blackbox(vector<vector<int> > &A, int num)
{
int n = A.size();
int m = A[0].size();
int cnt=0;
for(int i=0;i<n;i++)
{
    int l=0,h=m-1;
    while(l<h)
    {
        int middle = (l+h)/2;
        if(A[i][middle] <= num)
            l=middle+1;
        else if(A[i][middle] > num)
            h=middle;
    }
    if(A[i][l] <= num)
        cnt+=l+1;
    else
        cnt+=l;
}
return cnt;
}



int findMedian(vector<vector<int> > &A) {
    
  int low = INT_MAX;
  int high = INT_MIN;
  int n = A.size();
  int m = A[0].size();
  int k=(n*m)/2; //let k be the mid element
  for(int i=0;i<n;i++){
    //assign lowest and highest value as matrix is sorted row wise 
    low=min(low, A[i][0]);
    high= max(high, A[i][m-1]);
  }

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = blackbox(A,mid);
    //if count is greater than go to left part
    if(cnt >= (k+1))
        high=mid-1;
        // else go to right pasrt
    else if(cnt < (k+1))
        low=mid+1;
  }
  return low;
}
