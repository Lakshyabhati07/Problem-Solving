#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int blackbox(int a[MAX][MAX], int n, int mid)
{
    int count = 0;
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < n)
    {
        if (a[i][j] <= mid){
            count += (i + 1);
            j++;
        }
        else i--;
    }
    return count;
}
int kthSmallest(int matrix[MAX][MAX], int n, int k)
{

    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    //Your code here
  

    while (low < high){
        int mid = low + (high - low) / 2;
        int count = blackbox(matrix, n, mid);
        // if count < k then goto right part
        if (count < k) 
            low = mid + 1;
        //else goto left part including mid
        else
            high = mid;
    }
    return low;
}