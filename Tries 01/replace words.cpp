#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *childList[26];
    bool isEnd;

    TrieNode(){
       this-> isEnd=false;
        for(int i=0;i<26;i++){
           this-> childList[i]=NULL;
        }
    }
};

class Solution {
public:
TrieNode* root;
     void insert(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(!temp->childList[ch-'a'])
            {   //newnode create krni h
                temp->childList[ch-'a'] = new TrieNode();
            }
            temp=temp->childList[ch-'a'];

        }
        temp->isEnd=true;
    }

    string check(string word) {
     TrieNode* temp=root;
     string s="";
     for(int i=0;i<word.length();i++){
         char ch=word[i];
            if(temp->childList[ch-'a'] == NULL)
            break;
            
            s+=ch;
            temp=temp->childList[ch-'a'];
            if(temp->isEnd) return s;
     }  
     return word;
    }


    string replaceWords(vector<string>& dictionary, string sentence) {
       root=new TrieNode();
        string ans="",word="";


        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }

         stringstream ss(sentence);
         while(ss>>word){
            ans += check(word);
            ans += ' ';
        }
        ans.pop_back();
       
        return ans;
    }
};