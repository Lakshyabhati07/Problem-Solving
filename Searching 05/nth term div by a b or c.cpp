#include <bits/stdc++.h>
using namespace std;
 
//to find LCM of two number first finding HCF
int HCF(int a, int b)
{
    if (a == 0)
        return b;
 
    return HCF(b % a, a);
}
 
int lcm(int a, int b)
{
    return (a * b) / HCF(a, b);
}
 

int divTermCount(int a, int b, int c, int num)
{
//maths formulae : 
    return ((num / a) + (num / b) + (num / c)- (num / lcm(a, b))- (num / lcm(b, c))- (num / lcm(a, c))+ (num / lcm(a, lcm(b, c))));
}
 

int findNthTerm(int a, int b, int c, int n)
{
 
    // low=1 because a number can't be divide by zero
    //high =max(a,b,c)*n
    int low = 1, high = INT_MAX, mid;
 
    while (low < high) {
        mid = low + (high - low) / 2;
 
        //if term < n then move to right part
        if (divTermCount(a, b, c, mid) < n)
            low = mid + 1;
 
      //if term >= n then move to left part including mid
        else
            high = mid;
    }
 
    return low;
}
 

int main()
{
    int a,b,c,n;
    cout<<"Enter a then b then c:";
    cin>>a>>b>>c;

    cout<<"Enter n:";
    cin>>n;
 
    cout << findNthTerm(a, b, c, n);
 
    return 0;
}