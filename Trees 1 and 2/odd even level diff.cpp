#include<bits/stdc++.h>
using namespace std;
  
  struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution{
  public:
    /*You are required to complete this function*/
    int oddSum=0,evenSum=0;
    void findDiff(Node* root, int level){
        if(root==NULL)
        return;
        
        if(level%2==0){
            evenSum+=root->data;
        }
        else oddSum+=root->data;
        
        findDiff(root->left,level+1);
        findDiff(root->right,level+1);
    }
    
    int getLevelDiff(Node *root)
    {
       //Your code here
       findDiff(root,1);
       
       return oddSum-evenSum;
       
    }
};
