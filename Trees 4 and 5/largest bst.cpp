#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool isBST(Node* root, int min,int max){
        if(root==NULL)
        return true;

        if(root->data <= min || root->data >= max)      
         return false;
          
        return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
 }
 
 int TotalNodes(Node* root){
     if(root==NULL)
     return 0;
     
     return 1+ TotalNodes(root->left)+TotalNodes(root->right);
 }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	if(root==NULL)
    	return 0;
    	
    	if(isBST(root,INT_MIN,INT_MAX)){
                return TotalNodes(root);	    
    
    	}
    	
    	return max(largestBst(root->left),largestBst(root->right));
    }
};