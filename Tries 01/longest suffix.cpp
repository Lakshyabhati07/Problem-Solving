#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    int bestIdx;
    Trie *children[26];
    Trie(int bestIdx){
        bestIdx=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Solution {
    void insert(Trie *root, int i, vector<string>& wordsContainer) {
        Trie* curr = root;
        if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        for(int j = wordsContainer[i].length() - 1; j >= 0; j--) {
            int ch = wordsContainer[i][j] - 'a';
            if(curr -> children[ch] == nullptr) {
                curr -> children[ch] = new Trie(i);
            } 
            curr = curr -> children[ch];
            if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        }
    }
    int search(Trie *root, string &word) {
        Trie* curr = root;
        for(int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if(curr -> children[ch] == nullptr) {
                return curr -> bestIdx;
            } 
            curr = curr -> children[ch];
        }
        return curr -> bestIdx;
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie *root = new Trie(0);
        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(root, i, wordsContainer);
        }
        vector<int> ans;
        for(int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(root, wordsQuery[i]));
        }
        return ans;
    }
};