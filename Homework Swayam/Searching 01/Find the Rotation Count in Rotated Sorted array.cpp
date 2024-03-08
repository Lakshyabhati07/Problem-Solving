#include <bits/stdc++.h> 
using namespace std; 
  
int countRotations(int arr[], int l, int h) 
{ 
    if (h < l) 
        return 0; 
  
    if (h == l) 
        return l; 
  
  
    int mid = (l+h )/ 2; 
  
    if (mid < h && arr[mid + 1] < arr[mid]) 
        return (mid + 1); 
  
    if (mid > l && arr[mid] < arr[mid - 1]) 
        return mid; 
    if (arr[h] > arr[mid]) 
        return countRotations(arr, l, mid - 1); 
  
    return countRotations(arr, mid + 1, h); 
}