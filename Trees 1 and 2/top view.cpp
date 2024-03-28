#include<bits/stdc++.h>
using namespace std;
  
 struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
 
    vector<int> topView(Node *root) //vertical means y axis level 
    {
        vector<int> ans;
      
        //Your code here
        if(root==NULL)
        return ans;
        
        queue<pair<Node*,int>> q; //node, vertical
        map<int,int> m; // vertical to node val
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            
            Node* node=temp.first;
            int line=temp.second; 
            if(m.find(line)==m.end())//line means vertical
            m[line]=node->data;
            if(node->left)  q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it: m){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};