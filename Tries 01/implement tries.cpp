#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *childList[26];
    bool isEnd;

    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            childList[i]=NULL;
        }
    }
};
class Trie {
public:
TrieNode* root;
    Trie() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->childList[ch-'a'] == NULL)
            {   //newnode create krni h
                temp->childList[ch-'a'] = new TrieNode();
            }
            temp=temp->childList[ch-'a'];

        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->childList[ch-'a'] == NULL)
            return false;
             temp=temp->childList[ch-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
     TrieNode* temp=root;
     for(int i=0;i<prefix.length();i++){
         char ch=prefix[i];
            if(temp->childList[ch-'a'] == NULL)
            return false;
             temp=temp->childList[ch-'a'];
     }  
     return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */