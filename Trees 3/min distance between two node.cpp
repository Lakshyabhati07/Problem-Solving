 #include<bits/stdc++.h>
 #include<vector>
 using namespace std;
  
struct Node
{
    int data;
    Node* left, * right;
};
 class Solution{
    public:
    Node* LCA(Node *root, int first, int second)
    {
        if(root==NULL || root->data==first || root->data==second)
         return root;
       
        Node* left=LCA(root->left, first, second);
        Node* right=LCA(root->right, first, second);
    
        if(left==NULL)
         return right;
        
        if(right==NULL)
         return left;
        return root;
    }
    int minDist(Node *node, int toFind, int level)
    {
        if(node==NULL)
         return 0;
       
        if(node->data==toFind)
         return level;
        
        int left=minDist(node->left, toFind, level+1);
        
        int right=minDist(node->right, toFind, level+1);
        
        return left+right;
    }
    int findDist(Node* root, int a, int b) 
    {
        Node* ancestor=LCA(root,a,b);
        
        if(ancestor->data==a) 
         return minDist(ancestor,b,0);
        
        else if(ancestor->data==b)
         return minDist(ancestor,a,0);
        
        return minDist(ancestor,a,0)+minDist(ancestor,b,0); 
    }
};