#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *childList[2];
    TrieNode(){
            childList[0]=NULL;
            childList[1]=NULL;
    }
};



class Solution {
public:

    void insert(int num,TrieNode* root){
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int curBit = (num>>i)&1;
            if(curr->childList[curBit]==NULL){
                curr->childList[curBit]=new TrieNode();
            }
            curr=curr->childList[curBit];
        }
    }

    int solve(int num,TrieNode* root){
        TrieNode* curr=root;
        int xori=0;
         for(int i=31;i>=0;i--){
            int curBit = (num>>i)&1;
            if(curr->childList[curBit^1]!=NULL){
                xori+=(1<<i);
                curr=curr->childList[curBit^1];
            }
            else
            curr=curr->childList[curBit];
         }
         return xori;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maximumXor = 0;
        insert(nums[0],root);
        for(int i=1; i<nums.size(); i++){
            maximumXor = max(maximumXor, solve(nums[i],root));
            insert(nums[i],root);
        }

        return maximumXor;
    }
};