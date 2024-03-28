#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> ans;

       map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
       

        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode *frontnode=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;


            nodes[hd][level].insert(frontnode->val);

            if(frontnode->left!=NULL)
            {
                q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
            }
            if(frontnode->right!=NULL)
            {
                q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
            }
        }
         
            for(auto i:nodes){
                vector<int> col;
                for(auto j:i.second){
                    col.insert(col.end(),j.second.begin(),j.second.end());
                     }
                     ans.push_back(col);
            }  
        return ans;
    }
};