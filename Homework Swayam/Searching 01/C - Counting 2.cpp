#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  vector<int> arr(n);
  vector<int> query(q);

  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr.push_back(a);
  }
  sort(arr.begin(),arr.end());
  for(int i=0;i<q;i++){
    int qu;
    cin>>qu;
    query.push_back(qu);
  }
  for(int i=0;i<q;i++){
    int key=query[i];
  int low=0, high=n-1,ans=-1;
    
    while(low<=high){
     int mid=(low+(high-low)/2);
      
      if(arr[mid]>=key){
        ans=mid;
        high=mid-1;
      }
      else if(arr[mid]<key){
        low=mid+1;
      }
      else {
        
        high=mid-1;
      }

  }
     if(ans==-1)
      cout<<0<<endl;
    else
   cout<<n-ans<<endl; 
  }
  return 0;
}