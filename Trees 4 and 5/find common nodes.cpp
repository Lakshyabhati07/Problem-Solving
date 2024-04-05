
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
    
    void mark(Node*&root, map<int,bool>&visited){
            if(root==NULL){
                return;
            }
            
            mark(root->left,visited);
            
            visited[root->data]=true;
            
            mark(root->right,visited);
    }
    
    void chk(Node*&root,vector<int>&ans,map<int,bool>&visited){
        if(root==NULL){
            return;
        }
        chk(root->left,ans,visited);
       
        if(visited[root->data]==true){
            ans.push_back(root->data);
        }
       
        chk(root->right,ans,visited);
        
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     map<int,bool>visited;
     
     vector<int>ans;
     
     mark(root1,visited);
     
     chk(root2,ans,visited);
     
     sort(ans.begin(),ans.end());
     
     return ans;
         
    }
};


