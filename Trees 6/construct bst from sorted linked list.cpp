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
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
   TreeNode* getMid(ListNode* head){
    if(head==NULL)
    return NULL;
    ListNode* slow=head ;
    ListNode* fast=head;
    ListNode* prev=NULL;
    
    while(fast!=NULL&&fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    
    //building tree now
    TreeNode* root=new TreeNode(slow->val);
    if(prev!=NULL){
        prev->next=NULL;
        root->left=getMid(head);
    }
    root->right=getMid(slow->next);
    return root;
   }

TreeNode* sortedListToBST(ListNode* head) {
     return getMid(head);
    }
};