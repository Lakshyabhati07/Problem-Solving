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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL&&q==NULL)
        return true;

        if(p==NULL && q!=NULL)
        return false;

        if(p!=NULL && q==NULL)
        return false;

        bool lefti=isSameTree(p->left,q->left);
        bool righti=isSameTree(p->right,q->right);

        bool cond=p->val==q->val;

        if(lefti&&righti&&cond)
        return true;

        return false;

    }
};