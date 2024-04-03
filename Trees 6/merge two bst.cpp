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

class Solution
{
    public:
    void inorder(Node* root,vector<int>& ans){
        if(root==NULL)
        return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
       //Your code here
       inorder(root1,ans);
       inorder(root2,ans);
       sort(ans.begin(),ans.end());
       return ans;
    }
};